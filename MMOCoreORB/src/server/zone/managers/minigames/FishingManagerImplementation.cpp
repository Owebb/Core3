/*
 * FishingManagerImplementation.cpp
 *
 *  Created on: Apr 11, 2010
 *      Author: swgemu
 */

#include "FishingManager.h"
#include "server/zone/objects/player/PlayerCreature.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/tangible/weapon/WeaponObject.h"
#include "server/zone/objects/tangible/fishing/FishingPoleObject.h"
#include "server/zone/objects/tangible/fishing/FishingBaitObject.h"
#include "server/zone/objects/tangible/fishing/FishObject.h"
#include "server/zone/managers/terrain/TerrainManager.h"
#include "server/zone/managers/resource/ResourceManager.h"
#include "server/zone/Zone.h"
#include "server/zone/managers/planet/PlanetManager.h"
#include "server/zone/managers/player/PlayerManager.h"

#include "server/zone/ZoneServer.h"
#include "server/chat/StringIdChatParameter.h"
#include "server/zone/managers/minigames/events/FishingEvent.h"
#include "server/zone/managers/minigames/events/FishingSplashEvent.h"
#include "server/zone/managers/minigames/FishingSession.h"
#include "system/util/VectorMap.h"


int FishingManagerImplementation::checkLocation(PlayerCreature* player, int quality, float& x, float& y, float& z) {
	if (player == NULL)
		return 1;

	float angle = player->getDirectionAngle();

	if (angle > 360)
		angle = angle - 360;

	float distance = MIN((MAX(10.0 - (quality / 12.f), 2.1) + (float)System::random(3)), 10.0); // Calculates the Distance, using the Pole's Quality

	angle = 2 * M_PI * angle / 360;

	x = player->getPositionX() + sin(angle) * (distance);
	y = player->getPositionY() + cos(angle) * (distance);

	if (!player->getZone()->getPlanetManager()->getTerrainManager()->getWaterHeight(x, y, z))
		return 3;

	if (z < (player->getZone()->getHeight(x, y)))
		return 4;

	return 0;
}


int FishingManagerImplementation::startFishing(PlayerCreature* player) {
	if (player == NULL)
		return 6;

	ManagedReference<FishingPoleObject*> pole = getPole(player);

	if (pole == NULL) {
		player->sendSystemMessage("@fishing:must_have_pole");
		return 1;
	}

	ManagedReference<FishingBaitObject*> bait = getBait(player);

	if (bait == NULL) {
		player->sendSystemMessage("@fishing:bait_your_pole");
		return 2; // NOBAIT
	}

	float x, y, z;

	int locationCheck = checkLocation(player,pole->getQuality(), x, y, z);

	if (locationCheck == 1)
		return 6; // Something went wrong and player was NULL

	if (locationCheck == 3) {
		player->sendSystemMessage("@fishing:too_far"); // Your cast goes astray and lands at a non-fishable spot.
		return locationCheck; // NOWATER

	} else if (locationCheck == 4) {
		player->sendSystemMessage("@fishing:invalid_location");
		return locationCheck; // TERRAINABOVEWATER
	}

	if (player->isSwimming()) {
		player->sendSystemMessage("@fishing:bad_cast");
		return 5; // SWIMMING
	}

	ManagedReference<Zone*> zone = player->getZone();
	if (zone == NULL)
		return 6;

	ManagedReference<SceneObject*> markerObject = createMarker(x, y, z, zone);
	if (markerObject == NULL)
		return 6;

	createSplash(x, y, z, zone, player);
	String moodString = player->getMoodString();
	createFishingSession(player, createFishingEvent(player, zoneServer, WAITING), markerObject, DONOTHING, 0, 0, WAITING, moodString);
	uint32 boxID = createWindow(player, 0);
	sessions.get(player)->setFishBoxID(boxID);

	player->doAnimation("fishing_cast");
	player->setMoodString("fishing");

	player->sendSystemMessage("@fishing:start_fishing");

	player->registerObserver(ObserverEventType::POSITIONCHANGED, _this);

	return 0;
}

void FishingManagerImplementation::stopFishing(PlayerCreature* player, uint32 boxID, bool rem) {
	if (player == NULL) // should never occur
		return;

	String moodString;
	FishingEvent* fishingEvent = getFishingEvent(player);

	player->doAnimation("fishing_reel");

	if (fishingEvent != NULL) {
		moodString = sessions.get(player)->getMoodString();
		player->setMoodString(moodString);
	}

	setFishingState(player, NOTFISHING);

	ManagedReference<SceneObject*> marker = getFishMarker(player);

	if (marker != NULL)
		createSplash(marker->getPositionX(), marker->getPositionY(), marker->getPositionZ(), player->getZone(), player);

	uint32 id = boxID;

	if (boxID == 0)
		id = getFishBoxID(player);

	// close windows
	closeMenu(player, id);

	// stop events
	if (rem) {
		Locker locker(_this);
		removeMarker(player, marker);
		stopFishingEvent(player);
		sessions.drop(player);
	}

	player->sendSystemMessage("@fishing:stop_fishing");

	player->dropObserver(ObserverEventType::POSITIONCHANGED, _this);
}


void FishingManagerImplementation::fishingStep(PlayerCreature* player) {
	if (player == NULL)
		return;

	if (!sessions.contains(player))
		return;

	FishingSession* fishingSession = sessions.get(player);

	int nextAction = fishingSession->getNextAction();
	ManagedReference<SceneObject*> marker = fishingSession->getMarker();
	int fish = fishingSession->getFish();
	uint32 boxID = fishingSession->getFishBoxID();
	String moodString = fishingSession->getMoodString();

	int state = fishingSession->getFishingState();

	// close windows
	if (state != REELGAME)
		closeMenu(player, boxID);

	// Random Event & Mishap
	ManagedReference<FishingPoleObject*> pole = getPole(player);

	int event = System::random(50);
	if (pole != NULL) {
		if (pole->getQuality() != 0)
			event += (int)ceil(pole->getQuality() / 20);
	}


	int mishap = System::random(1);

	// Luck might have it a mishap turns into something else!
	/*if (event == MISHAP) {
		chance = System::random(luck/10);
		if (chance >= (int)((luck / 10) * (3 / 4))) event--;
	}*/

	// Accounting for bad Bait
	ManagedReference<FishingBaitObject*> bait = getBait(player);

	if (bait != NULL) {
		if ((state < CATCH) && (bait->getFreshness() > SOGGY)) {
			if (System::random(15) < bait->getFreshness()) {

				mishapEvent("@fishing:toss_bait", player, boxID, true, moodString);
				return; // NOBAIT
			}
		}
	}

	//debug player->sendSystemMessage("Event: " + String::valueOf(event) + " Mishap: " + String::valueOf(mishap) + " Next Action: " + String::valueOf(nextAction));

	// animate character
	animate(player, nextAction);

	switch (state) {

	case WAITING:
	{
		// CALCULATING FISH
		int newFish = getFish(player);

		if (event >= MISHAP) {
			fishingProceed(player, nextAction, marker, newFish, boxID, SNAGGED, true, moodString);
		} else {
			if (nextAction == REEL) {
				ManagedReference<SceneObject*> newMarker = updateMarker(player, marker, false);

				if (newMarker != NULL)
					fishingProceed(player, nextAction, newMarker, newFish, boxID, WAITING, false, moodString);

			} else if (event >=  (vegetation(marker) * 5)) {
				fishingProceed(player, nextAction, marker, newFish, boxID, NIBBLE, true, moodString);
			} else {
				fishingProceed(player, nextAction, marker, newFish, boxID, WAITING, false, moodString);
			}
		}
		break;
	}
	case SNAGGED:
	{
		if (event >= PROCEED) {
			fishingProceed(player, nextAction, marker, fish, boxID, NIBBLE, true, moodString);

		} else {
			fishingProceed(player, nextAction, marker, fish, boxID, SNAGGED, false, moodString);

		}
		break;
	}
	case NIBBLE:
	{
		if (event >= MISHAP) {

			if (mishap == 0) { // Line snapped, losing bait
				mishapEvent("@fishing:line_snap", player, boxID, true, moodString);

			} else { // Lost catch
				mishapEvent("@fishing:lost_catch", player, boxID, false, moodString);

			}

		} else if ((event >= (PROCEED + 10 - (density(marker) * 2))) && (nextAction >= TUGUP && nextAction <= TUGLEFT)) {
			fishingProceed(player, nextAction, marker, fish, boxID, BITE, true, moodString);

		} else if (nextAction == REEL) {
			ManagedReference<SceneObject*> newMarker = updateMarker(player, marker, false);

			if (newMarker != NULL)
				fishingProceed(player, nextAction, newMarker, fish, boxID, NIBBLE, false, moodString);
		} else {
			fishingProceed(player, nextAction, marker, fish, boxID, NIBBLE, false, moodString);

		}
		break;
	}
	case BITE:
	{
		if (event >= MISHAP) {

			if (mishap == 0) { // Lost Bait
				mishapEvent("@fishing:lost_bait", player, boxID, true, moodString);

			} else { // Fish pulled out the line, but the player has no penalty - appearently every fisherman can fix his line :)
				mishapEvent("@fishing:line_spooled", player, boxID, false, moodString);

			}
		} else if ((event >= PROCEED) && (nextAction >= TUGUP && nextAction <= TUGLEFT)) {
			fishingProceed(player, nextAction, marker, fish, boxID, CATCH, true, moodString);

		} else if (nextAction == REEL) {
			ManagedReference<SceneObject*> newMarker = updateMarker(player, marker, false);

			if (newMarker != NULL)
				fishingProceed(player, nextAction, newMarker, fish, boxID, BITE, false, moodString);
		} else {
			fishingProceed(player, nextAction, marker, fish, boxID, BITE, false, moodString);

		}
		break;
	}
	case CATCH:
	{
		/*if (player->isInRange(marker, 2.0)) { // in case reeling closer gets it into catching range but neither did the position change nor did he do nothing or reel
			success(player, fish, marker, boxID);

		} else {

			if (event == MISHAP) { // Fish is trying to get away
				fishingProceed(player, nextAction, marker, fish, boxID, CATCH, true, moodString);

			}  else*/
		if ((nextAction == DONOTHING) || (nextAction == REEL)) {

			/*SceneObject* newMarker = updateMarker(player, marker, false);

			if (newMarker != NULL)*/
				fishingProceed(player, nextAction, marker, fish, boxID, REELING, true, moodString);

		} else {
			fishingProceed(player, nextAction, marker, fish, boxID, CATCH, true, moodString);
		}

		//}
		break;
	}
	case REELING:
	{
		ManagedReference<SceneObject*> newMarker = updateMarker(player, marker, false);

		if (newMarker != NULL)
			fishingProceed(player, nextAction, newMarker, fish, boxID, REELING, true, moodString);

		break;
	}
	case REELGAME:
	{
		if (player->isInRange(marker, 2.0)) {
			success(player, fish, marker, boxID);

		} else {
			if (event >= MISHAP) {
				mishapEvent("@fishing:tore_bait", player, boxID, true, moodString);
			} else {

				ManagedReference<SceneObject*> newMarker = updateMarker(player, marker, true);

				if (newMarker != NULL) {
					fishingProceed(player, nextAction, newMarker, fish, boxID, REELGAME, true, moodString);
				} else {
					success(player, fish, marker, boxID);
				}

			}
		}
		break;
	}
	}
}

String FishingManagerImplementation::getTime() {
	time_t seconds;
	time(&seconds);
	String result = ctime(&seconds);
	result = result + " PDT";
	return result;
}

void FishingManagerImplementation::success(PlayerCreature* player, int fish, SceneObject* marker, uint32 boxID) {
	if (player == NULL)
		return;

	Zone* zone = player->getZone();

	if (fish > 93){ // NON-FISH ITEM WAS CAUGHT!
		int chance = System::random(99)/*+(luck/10)*/;

		if (chance > 94) { // RARE ITEM WAS CAUGHT!
			int i = rareLoot.size();

			String loot = rareLoot.get(System::random(i - 1));
			ManagedReference<SceneObject*> lootObject = zoneServer->createObject(loot.hashCode(), 2);

			sendReward(player, marker, lootObject);
		} else { // MISC ITEM WAS CAUGHT!
			int i = miscLoot.size();

			String loot = miscLoot.get(System::random(i - 1));
			ManagedReference<SceneObject*> lootObject = zoneServer->createObject(loot.hashCode(), 2);

			sendReward(player, marker, lootObject);
		}
	} else {
		// 5% chance to toss fish away
		int badLuck = System::random(20);

		if (badLuck == 0) {
			player->sendSystemMessage("@fishing:size_matters");
			stopFishing(player, boxID, true);

			return;
		} else {
			String lootFish = "object/tangible/fishing/fish/" + fishType.get(fish) + ".iff";
			ManagedReference<FishObject*> lootFishObject = (FishObject*)zoneServer->createObject(lootFish.hashCode(), 2);

			if (lootFishObject != NULL) {
				String time = getTime();
				String name = player->getFirstName() + " " + player->getLastName();

				int quality = 1;

				ManagedReference<FishingPoleObject*> pole = getPole(player);

				if (pole != NULL) {
					if (pole->getQuality() != 0)
						quality += (int)ceil(pole->getQuality() / 25);
				}
				int factor = 1;

				if (player->hasSkillBox("outdoors_ranger_tracking_04"))
					factor = 8;
				else if (player->hasSkillBox("outdoors_ranger_tracking_03"))
					factor = 7;
				else if (player->hasSkillBox("outdoors_ranger_tracking_02"))
					factor = 6;
				else if (player->hasSkillBox("outdoors_ranger_tracking_01"))
					factor = 5;
				else if (player->hasSkillBox("outdoors_scout_camp_04"))
					factor = 4;
				else if (player->hasSkillBox("outdoors_scout_camp_03"))
					factor = 3;
				else if (player->hasSkillBox("outdoors_scout_camp_02"))
					factor = 2;

				float length = fishLength.get(fish)*factor;

				length = System::random(length)+quality;

				lootFishObject->setAttributes(name, zone->getZoneName(), time, length / 100);

				//if (player->hasSkillBox("outdoors_ranger_novice") || player->hasSkillBox("outdoors_scout_novice")) {
				int xp;

				if (fish == 1)
					xp = length * 5;
				else
					xp = length * 2;

				ManagedReference<PlayerManager*> playerManager = zone->getZoneServer()->getPlayerManager();

				Locker playerLocker(player);
				playerManager->awardExperience(player, "camp", xp, true);

				lootFishObject->setCustomizationVariable(CustomizationVariableTypes::PRIVATE_INDEX_COLOR_1, color.get(zone->getZoneName()));

				String baitString = "object/tangible/fishing/bait/bait_chum.iff";
				ManagedReference<TangibleObject*> baitObject = (TangibleObject*)zoneServer->createObject(baitString.hashCode(), 2);

				int useCount = System::random(5);
				if (useCount > 1)
					baitObject->setUseCount(useCount,true);


				if (baitObject != NULL) {
					baitObject->sendTo(player, true);
					lootFishObject->addObject(baitObject, -1, true);
				}

				String resourceString = zone->getZoneName();
				resourceString = "seafood_fish_" + resourceString;
				int amount = System::random(50)+factor;
				ManagedReference<ResourceManager*> resourceManager = zone->getZoneServer()->getResourceManager();
				ManagedReference<SceneObject*> resource = (SceneObject*)resourceManager->harvestResource(player, resourceString, amount);

				if (resource != NULL) {
					resource->sendTo(player, true);
					lootFishObject->addObject(resource, -1, true);
				}

				sendReward(player, marker, (SceneObject*)lootFishObject);
			}
		}
	}

	stopFishing(player, boxID, false);
}


void FishingManagerImplementation::sendReward(PlayerCreature* player, SceneObject* marker, SceneObject* loot) {
	if ((player != NULL) && (marker != NULL) && (loot != NULL)) {
		StringIdChatParameter body("fishing","prose_notify_catch");
		String itemName;
		loot->sendTo(player, true);

		Locker markerLocker(marker);

		if (marker->addObject(loot, -1, true)) {
			marker->openContainerTo(player);

			loot->getObjectName()->getFullPath(itemName);
			body.setTT(itemName);
			player->sendSystemMessage(body);
		}
	}
}


uint32 FishingManagerImplementation::createWindow(PlayerCreature* player, uint32 boxID) {
	if (player == NULL)
		return -1;

	ManagedReference<SceneObject*> marker = getFishMarker(player);

	if (marker == NULL)
		return -1;

	// clear old one
	closeMenu(player, boxID);

	int veg = vegetation(marker);
	int den = density(marker);

	ManagedReference<FishingBaitObject*> bait = getBait(player);

	if (bait == NULL)
		return -1;

	int freshness = bait->getFreshness();

	if (freshness >= MUSH) {
		freshness = 2;
	} else if (freshness >= SOGGY) {
		freshness = 1;
	} else {
		freshness = 0;
	}

	String prompt = "STATUS : " + state.get(getFishingState(player)) + "\nBAIT STATUS : "
			+ baitStatus.get(freshness) + "\nLINE RANGE : "
			+ String::valueOf( ceil( player->getDistanceTo(marker) * 100 ) / 100)
			+ "\nFISH DENSITY : "+ property.get(den)
			+ "\nVEGETATION : " + property.get(veg)
			+ "\nNEXT ACTION : "
			+ action.get( getNextAction(player) );

	// create new window
	ManagedReference<SuiListBox*> box = new SuiListBox(player, 90, 0);

	box->setPromptTitle("@fishing:sui_title");
	box->setPromptText(prompt);

	box->addMenuItem("@fishing:fa_tug_up", 0);
	box->addMenuItem("@fishing:fa_tug_right", 1);
	box->addMenuItem("@fishing:fa_tug_left", 2);
	box->addMenuItem("@fishing:fa_small_reel", 3);
	box->addMenuItem("@fishing:fa_stop", 4);

	player->addSuiBox(box);
	player->sendMessage(box->generateMessage());

	return box->getBoxID();
}


void FishingManagerImplementation::closeMenu(PlayerCreature* player, uint32 boxID) {
	if ((player != NULL) && (boxID != -1)) {
		if (player->hasSuiBox(boxID)) {
			player->sendMessage(player->getSuiBox(boxID)->generateCloseMessage());
			player->removeSuiBox(boxID);
		}
	}
}

int FishingManagerImplementation::vegetation(SceneObject* marker) {
	if (marker == NULL)
		return 0;

	return (int)ceil( fabs( marker->getPositionX() / 100 ) ) % 6;
}

int FishingManagerImplementation::density(SceneObject* marker) {
	if (marker == NULL)
		return 0;

	return (int)ceil( fabs( marker->getPositionY() / 100 ) ) % 6;
}


int FishingManagerImplementation::getFish(PlayerCreature* player) {
	int chance = System::random(99)/*+(luck/10)*/;

	if (player == NULL)
		return chance;

	if (chance < 94) {
		ManagedReference<FishingPoleObject*> pole = getPole(player);
		if (pole == NULL)
			return chance;

		ManagedReference<FishingBaitObject*> bait = getBait(player);
		if (bait == NULL)
			return chance;

		chance = (int)((pole->getQuality() * 0.06) // ACCOUNT FOR POLE QUALITY - quality is 50 at init
						+ (vegetation(player) * -0.75) // ACCOUNT FOR VEGETATION PENALTY - is 0 if vegetation method fails
						+ (density(player) * 0.75) // ACCOUNT FOR FISH DENSITY - is 0 if density method fails
						+ ((3 - bait->getFreshness()) * 3.0) // ACCOUNT FOR BAIT STATUS - freshness is 0 at init
						//+ (luck / 100) // ACCOUNT FOR LUCK - no luck stat yet!?
						+ (System::random(20))) // RANDOM BIAS
						% 7; // MUX NUMBER TO FISH 0-6
	}

	return chance;
}


int FishingManagerImplementation::getNextAction(PlayerCreature* player) {
	if (player == NULL)
		return DONOTHING;

	if (!sessions.contains(player))
		return DONOTHING;

	return sessions.get(player)->getNextAction();
}

void FishingManagerImplementation::setNextAction(PlayerCreature* player, int next) {
	if (player == NULL)
		return;

	if (!sessions.contains(player))
		return;

	FishingSession* fishingSession = sessions.get(player);

	if ((next >= DONOTHING) && (next <= STOPFISHING)) {
		fishingSession->setNextAction(next);
	}
}


FishingPoleObject* FishingManagerImplementation::getPole(PlayerCreature* player) {
	if (player == NULL)
		return NULL;

	SceneObject* pole = player->getSlottedObject("hold_r");

	if (pole != NULL) {
		if (pole->isFishingPoleObject()) {
			ManagedReference<FishingPoleObject*> poleObject = (FishingPoleObject*)pole;

			return poleObject;
		}
	}

	return NULL;
}


FishingBaitObject* FishingManagerImplementation::getBait(PlayerCreature* player) {
	if (player == NULL)
		return NULL;

	Locker locker(_this);

	ManagedReference<FishingPoleObject*> pole = getPole(player);

	if (pole != NULL) {
		if (pole->isFishingPoleObject() && pole->hasFullContainerObjects()) {
			ManagedReference<FishingBaitObject*> bait = (FishingBaitObject*)pole->getContainerObject(0);

			if (bait != NULL) {
				if (bait->isFishingBait()) {
					return bait;
				}
			}
		}
	}

	return NULL;
}


uint32 FishingManagerImplementation::getFishBoxID(PlayerCreature* player) {
	if (player == NULL)
		return -1;

	if (sessions.contains(player)) {
		FishingSession* fishingSession = sessions.get(player);

		return fishingSession->getFishBoxID();
	}

	return -1;
}

void FishingManagerImplementation::setFishBoxID(PlayerCreature* player, uint32 boxID) {
	if (player == NULL)
		return;

	if (sessions.contains(player)) {
		FishingSession* fishingSession = sessions.get(player);

		fishingSession->setFishBoxID(boxID);
	}
}

int FishingManagerImplementation::getFishingState(PlayerCreature* player) {
	if (player == NULL)
		return NOTFISHING;

	if (sessions.contains(player)) {
		FishingSession* fishingSession = sessions.get(player);

		int state = fishingSession->getFishingState();

		if ((state >= NOTFISHING) && (state <= REELGAME))
			return state;
	}

	return NOTFISHING;
}


void FishingManagerImplementation::setFishingState(PlayerCreature* player, int state) {
	if (player == NULL)
		return;

	if (!sessions.contains(player))
		return;

	FishingSession* fishingSession = sessions.get(player);

	if ((state >= NOTFISHING) && (state <= REELGAME)) {
		fishingSession->setFishingState(state);
	}
}

SceneObject* FishingManagerImplementation::getFishMarker(PlayerCreature* player) {
	if (player == NULL)
		return NULL;

	if (sessions.contains(player))
		return sessions.get(player)->getMarker();
	else
		return player;
}


void FishingManagerImplementation::setFishMarker(PlayerCreature* player, SceneObject* marker) {
	if (player != NULL) {
		if (!sessions.contains(player))
			return;

		sessions.get(player)->setMarker(marker);
	}
}

void FishingManagerImplementation::freeBait(PlayerCreature* player) {
	if (player != NULL) {
		String bait = "object/tangible/fishing/bait/bait_worm.iff";
		ManagedReference<SceneObject*> baitObject = zoneServer->createObject(bait.hashCode(), 0);
		baitObject->sendTo(player, true);

		ManagedReference<FishingPoleObject*> pole = getPole(player);

		if ((pole != NULL) && (!pole->hasFullContainerObjects())) {
			pole->addObject(baitObject, -1, true);
		}
	}
}

void FishingManagerImplementation::fishingProceed(PlayerCreature* player, int nextAction, SceneObject* marker, int fish, uint32 boxID, int newstate, bool notifyClient, String& moodString) {
	if ((player == NULL) || (marker == NULL)) {
		return;
	}

	int oldstate = getFishingState(player);

	if ((newstate == CATCH) && (!notifyClient)) { // updated the marker!
		player->sendSystemMessage("@fishing:fish_fight_closer");
	}

	if (notifyClient) {

		switch (newstate) {

		case SNAGGED: {
			player->sendSystemMessage("@fishing:fs_snag");

			break;
		}
		case NIBBLE: {
			if (oldstate == SNAGGED) { // line just got unsnagged
				player->sendSystemMessage("@fishing:line_free");
			} else {
				player->sendSystemMessage("@fishing:fs_nibble");
			}

			player->showFlyText("fishing","fly_nibble", 50, 200, 50);

			createSplash(marker->getPositionX(), marker->getPositionY(), marker->getPositionZ(), player->getZone(), player);

			break;
		}
		case BITE: {
			player->showFlyText("fishing","fly_bite", 230, 150, 30);
			player->sendSystemMessage("@fishing:fs_bite");

			createSplash(marker->getPositionX(), marker->getPositionY(), marker->getPositionZ(), player->getZone(), player);

			break;
		}
		case CATCH: {
			if (oldstate == BITE) {
				player->showFlyText("fishing","fly_catch", 240, 240, 65);
				player->sendSystemMessage("@fishing:fs_caught");

				createSplash(marker->getPositionX(), marker->getPositionY(), marker->getPositionZ(), player->getZone(), player);
			}

			break;
		}
		case REELING: {
			if (oldstate == CATCH) {
				if (sessions.contains(player)) {
					player->sendSystemMessage("@fishing:reel_in");
					FishingEvent* fishingEvent = createFishingEvent(player, zoneServer, REELGAME);
					FishingSession* fishingSession = sessions.get(player);

					if (fishingEvent != NULL) {
						fishingSession->setEvent(fishingEvent);
						fishingSession->update(REEL, marker, fish, 0, REELGAME);
					}
				}
			}
			break;
		}
		case REELGAME: {
			if (sessions.contains(player)) {
				FishingEvent* fishingEvent = createFishingEvent(player, zoneServer, newstate);
				FishingSession* fishingSession = sessions.get(player);

				if (fishingEvent != NULL) {
					fishingSession->setEvent(fishingEvent);
					fishingSession->update(REEL, marker, fish, 0, newstate);
				}
			}
		}
		default:
			break;
		}
	}

	if ((nextAction >= DONOTHING) && (nextAction < REEL)) {
		ManagedReference<FishingBaitObject*> bait = getBait(player);

		if (bait != NULL)
			bait->lessFresh();
	}

	if ((newstate != REELING) && (newstate != REELGAME)) {
		if (sessions.contains(player)) {
			FishingEvent* fishingEvent = createFishingEvent(player, zoneServer, newstate);
			FishingSession* fishingSession = sessions.get(player);

			if (fishingEvent != NULL) {
				fishingSession->update(DONOTHING, marker, fish, boxID, newstate);
				fishingSession->setFishBoxID(createWindow(player, boxID));
				fishingSession->setEvent(fishingEvent);

			}
		}
	}


}

void FishingManagerImplementation::mishapEvent(const String& text, PlayerCreature* player, uint32 boxID, bool losebait, String& moodString) {
	if ((player != NULL) && (!text.isEmpty())) {
		player->sendSystemMessage(text);


		if (losebait) {
			stopFishing(player, boxID, true);
			loseBait(player);
		} else {
			if (sessions.contains(player)) {
				FishingEvent* fishingEvent = createFishingEvent(player, zoneServer, WAITING);
				FishingSession* fishingSession = sessions.get(player);

				if (fishingEvent != NULL) {
					fishingSession->update(DONOTHING, getFishMarker(player), getFish(player), boxID, WAITING);
					fishingSession->setFishBoxID(createWindow(player, boxID));
					fishingSession->setEvent(fishingEvent);
				}
			}
		}
	}
}

bool FishingManagerImplementation::loseBait(PlayerCreature* player) {
	if (player == NULL)
		return false;

	ManagedReference<SceneObject*> pole = player->getSlottedObject("hold_r");

	if (pole != NULL) {
		if (pole->isFishingPoleObject() && pole->hasFullContainerObjects()) {
			if (pole->getContainerObject(0) != NULL) {
				ManagedReference<SceneObject*> bait = pole->getContainerObject(0);

				if (!bait->isFishingBait())
					return false;

				ManagedReference<FishingBaitObject*> fishBait = (FishingBaitObject*) bait.get();

				if (fishBait->getUseCount() > 1)
					fishBait->setUseCount(fishBait->getUseCount() - 1, true);
				else {

					pole->removeObject(bait, true);

					if (bait->isPersistent())
						bait->destroyObjectFromDatabase(true);
				}

				return true;
			}
		}
	}

	return false;
}


void FishingManagerImplementation::animate(PlayerCreature* player, int nextAction) {
	if (player == NULL)
		return;

	switch (nextAction) {
		case TUGUP:
			player->doAnimation("fishing_tug_back");
			break;

		case TUGRIGHT:
			player->doAnimation("fishing_tug_right");
			break;

		case TUGLEFT:
			player->doAnimation("fishing_tug_left");
			break;

		case REEL:
			player->doAnimation("fishing_reel");
			break;
	}
}

SceneObject* FishingManagerImplementation::createMarker(float x, float y, float z, Zone* zone) {
	if (zone == NULL)
		return NULL;

	String marker = "object/tangible/fishing/marker.iff";
	ManagedReference<SceneObject*> markerObject = zoneServer->createObject(marker.hashCode(), 0);

	if (markerObject == NULL)
		return NULL;

	markerObject->initializePosition(x, z, y);
	markerObject->insertToZone(zone);

	markerObject->registerObserver(ObserverEventType::CLOSECONTAINER, _this);

	return markerObject;
}


void FishingManagerImplementation::createSplash(float x, float y, float z, Zone* zone, PlayerCreature* player) {
	if ((player != NULL) && (zone != NULL)) {
		String splash = "object/tangible/fishing/splash.iff";
		ManagedReference<SceneObject*> splashObject = zoneServer->createObject(splash.hashCode(), 0);

		if (splashObject != NULL) {
			splashObject->initializePosition(x, z + 0.5, y);
			splashObject->insertToZone(zone);

			createFishingSplashEvent(player, zoneServer, splashObject);
		}
	}
}

bool FishingManagerImplementation::checkUpdateMarker(PlayerCreature* player, float& x, float& y, float& z) {
	bool beached = false;

	float newZ = z;

	if (!player->getZone()->getPlanetManager()->getTerrainManager()->getWaterHeight(x, y, newZ))
		beached = true;

	newZ = player->getZone()->getHeight(x, y);

	if (z < newZ) {
		z = newZ;
		beached = true;
	}

	return beached;
}

SceneObject* FishingManagerImplementation::updateMarker(PlayerCreature* player, SceneObject* marker, bool notifyPlayer) {
	if ((player == NULL) || (marker == NULL))
		return NULL;

	Locker markerLocker(marker);

	// CALCULATING BOBBER POS
	Zone* zone = player->getZone();

	float x = player->getPositionX() + ((marker->getPositionX() - player->getPositionX()) * 0.75);// (player->getPositionX() + marker->getPositionX()) / 2;
	float y = player->getPositionY() + ((marker->getPositionY() - player->getPositionY()) * 0.75);
	float z = marker->getPositionZ();

	//info("Y from Marker: "+String::valueOf(marker->getPositionY())+" Y from Player: "+String::valueOf(player->getPositionY()),true);
	//info("X: "+String::valueOf(x)+" Y: "+String::valueOf(y) + " Z: "+String::valueOf(z), true);

	bool succeed = false;

	if (notifyPlayer) {
		int event = System::random(6);
		if (event < 2) {
			// SUCCEED IN DRAWING CLOSER
			if (checkUpdateMarker(player, x, y, z)) {
				player->sendSystemMessage("@fishing:loot_beached");// BEACHED!
				succeed = true;
			} else {
				player->sendSystemMessage("@fishing:fish_fight_closer");
			}
		} else if (event == 2) {
			// FIGHT EASY
			if (checkUpdateMarker(player, x, y, z)) {
				player->sendSystemMessage("@fishing:loot_beached");// BEACHED!
				succeed = true;
			} else {
				player->sendSystemMessage("@fishing:fish_fight_easy");
			}
		} else if (event == 3) {
			// FIGHT HARD
			x += System::random(1);
			y += System::random(1);
			//info("X: "+String::valueOf(x)+" Y: "+String::valueOf(y) + " Z: "+String::valueOf(z), true);
			if (checkUpdateMarker(player, x, y, z)) {
				player->sendSystemMessage("@fishing:loot_beached");// BEACHED!
				succeed = true;
			} else {
				player->sendSystemMessage("@fishing:fish_fight_hard");
			}
		} else if (event == 4) {
			// FIGHT AWAY
			x += System::random(1);
			y += System::random(1);
			//info("X: "+String::valueOf(x)+" Y: "+String::valueOf(y) + " Z: "+String::valueOf(z), true);
			if (checkUpdateMarker(player, x, y, z)) {
				player->sendSystemMessage("@fishing:loot_beached");// BEACHED!
				succeed = true;
			} else {
				player->sendSystemMessage("@fishing:fish_fight_hard");
			}
		} else if (event == 5) {
			// FISH RUN
			x += System::random(1);
			y += System::random(1);
			//info("X: "+String::valueOf(x)+" Y: "+String::valueOf(y) + " Z: "+String::valueOf(z), true);
			if (checkUpdateMarker(player, x, y, z)) {
				player->sendSystemMessage("@fishing:loot_beached");// BEACHED!
				succeed = true;
			} else {
				player->sendSystemMessage("@fishing:fish_run");
			}
		} else {
			// FISH CHARGE
			x -= System::random(1);
			y -= System::random(1);
			//info("X: "+String::valueOf(x)+" Y: "+String::valueOf(y) + " Z: "+String::valueOf(z), true);
			if (checkUpdateMarker(player, x, y, z)) {
				player->sendSystemMessage("@fishing:loot_beached");// BEACHED!
				succeed = true;
			} else {
				player->sendSystemMessage("@fishing:fish_charge");
			}
		}

	}

	if (!succeed) {

		if (checkUpdateMarker(player, x, y, z)) {
			player->sendSystemMessage("@fishing:loc_unfishable");
			stopFishing(player, 0, true);
			return NULL;
		}

		removeMarker(player, marker);

		ManagedReference<SceneObject*> newMarker = createMarker(x, y, z, zone);

		if (newMarker == NULL)
			return NULL;

		setFishMarker(player, newMarker);

		if ((player->isInRange(newMarker, 2.0)) && (getFishingState(player) < REELING)) {
			stopFishing(player, 0, true);
			return NULL;
		}

		return newMarker;
	}

	return NULL;
}

void FishingManagerImplementation::removeMarker(PlayerCreature* player, SceneObject* container) {
	if (player != NULL) {
		ManagedReference<SceneObject*> marker;

		if (container == NULL) {
			marker = getFishMarker(player);
		} else {
			marker = container;
		}

		if (marker != NULL) {
			if (!marker->isPlayerCreature()) {

				setFishMarker(player, NULL);

				marker->removeFromZone();

				if (marker->isPersistent()) {
					marker->destroyObjectFromDatabase(true);
				}

				VectorMap<uint64, ManagedReference<SceneObject*> >* objects = marker->getContainerObjects();

				while (objects->size() > 0) {
					ManagedReference<SceneObject*> object = objects->get((int)0);

					if (object->isPersistent()) {
						object->destroyObjectFromDatabase(true);
					}

					marker->removeObject(object);
				}
			}
		}
	}
}

void FishingManagerImplementation::removeSplash(SceneObject* splash) {
	if (splash != NULL) {
		if (!splash->isPlayerCreature()) {
			splash->removeFromZone();

			if (splash->isPersistent()) {
				splash->destroyObjectFromDatabase(true);
			}
		}
	}
}

void FishingManagerImplementation::createFishingSplashEvent(PlayerCreature* player, ZoneServer* zoneServer, SceneObject* splash) {
	if ((player != NULL) && (zoneServer != NULL) && (splash != NULL)) {
		Reference<FishingSplashEvent*> fishingSplashEvent = new FishingSplashEvent(player, zoneServer, splash);

		fishingSplashEvent->schedule(1000);
	}
}

void FishingManagerImplementation::createFishingSession(PlayerCreature* player, FishingEvent* event, SceneObject* marker, int nextAction, int fish, uint32 boxID, int fishingState, String& mood) {
	if ((player != NULL) && (event != NULL) && (marker != NULL))	{

		Locker locker(_this);
		sessions.put(player,new FishingSession(player, event, marker, nextAction, fish, boxID, fishingState, mood));
	}
}

FishingEvent* FishingManagerImplementation::createFishingEvent(PlayerCreature* player, ZoneServer* zoneServer, int state) {
	if ((player == NULL) || (zoneServer == NULL))
		return NULL;

	FishingEvent* fishingEvent = new FishingEvent(player, zoneServer, state);
	if (fishingEvent != NULL) {
		int timer = System::random(1000);
		if (state >= CATCH)
			fishingEvent->schedule(timer+4000);
		else
			fishingEvent->schedule(timer+6000);
		player->removePendingTask("fishing");
		player->addPendingTask("fishing", fishingEvent);
	}
	return fishingEvent;
}


void FishingManagerImplementation::stopFishingEvent(PlayerCreature* player) {
	if (player == NULL)
		return;

	FishingEvent* fishingEvent = getFishingEvent(player);

	if (fishingEvent != NULL) {
		fishingEvent->cancel();
		player->removePendingTask("fishing");
		if (sessions.contains(player))
			sessions.get(player)->setEvent(NULL);
		fishingEvent = NULL;
	}
}


FishingEvent* FishingManagerImplementation::getFishingEvent(PlayerCreature* player) {
	if (player == NULL)
		return NULL;

	if (!sessions.contains(player))
		return NULL;

	FishingEvent* fishingEvent = sessions.get(player)->getEvent();

	return fishingEvent;
}

bool FishingManagerImplementation::isPlaying(PlayerCreature* player) {
	return (sessions.contains(player));
}

int FishingManagerImplementation::notifyCloseContainer(PlayerCreature* player, SceneObject* container) {
	Locker locker(_this);

	removeMarker(player, container);
	sessions.drop(player);

	return 1;
}

void FishingManagerImplementation::checkFishingOnPositionUpdate(PlayerCreature* player) {
	//Locker _locker(player); player is already locked

	int fishingState = getFishingState(player);

	if (fishingState != FishingManager::NOTFISHING) {
		if (!sessions.contains(player))
			return;

		FishingSession* fishingSession = sessions.get(player);

		ManagedReference<SceneObject*> marker = fishingSession->getMarker();

		if (marker != NULL) {
			if ((player->isSwimming()) || (!player->isInRange(marker, 10.0))) {
				stopFishing(player, 0, true);
			}

			if (player->isInRange(marker, 2.0)) {
				if (fishingState >= FishingManager::REELING) {
					success(player, fishingSession->getFish(), marker, 0);
				} else {
					stopFishing(player, 0, true);
				}
			}
		}
	}
}