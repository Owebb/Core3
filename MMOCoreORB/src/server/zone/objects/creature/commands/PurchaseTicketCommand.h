/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
*/

#ifndef PURCHASETICKETCOMMAND_H_
#define PURCHASETICKETCOMMAND_H_

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"
#include "server/zone/objects/player/sui/SuiWindowType.h"
#include "server/zone/objects/tangible/ticket/TicketObject.h"
#include "server/zone/managers/planet/PlanetManager.h"

class PurchaseTicketCommand : public QueueCommand {
public:

	PurchaseTicketCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidPostures(creature))
			return INVALIDPOSTURE;

		if (!creature->isPlayerCreature())
			return GENERALERROR;

		PlayerCreature* player = (PlayerCreature*) creature;

		ManagedReference<SceneObject*> inventory = player->getSlottedObject("inventory");

		if (inventory == NULL)
			return GENERALERROR;

		String departurePlanet;
		String departurePoint;

		String arrivalPlanet;
		String arrivalPoint;

		bool roundTrip;

		StringTokenizer tokenizer(arguments.toString());

		try {
			tokenizer.getStringToken(departurePlanet);
			tokenizer.getStringToken(departurePoint);
			tokenizer.getStringToken(arrivalPlanet);
			tokenizer.getStringToken(arrivalPoint);
			roundTrip = (bool) tokenizer.getIntToken();
		} catch(Exception& e) {
			return INVALIDPARAMETERS;
		}

		departurePlanet = departurePlanet.replaceAll("_", " ");
		departurePoint = departurePoint.replaceAll("_", " ");
		arrivalPlanet = arrivalPlanet.replaceAll("_", " ");
		arrivalPoint = arrivalPoint.replaceAll("_", " ");

		ManagedReference<Zone*> zone = player->getZone();

		//TODO:
		//@travel:no_location_found No location was found for your destination.

		//Check to see if the departure planet is the same planet the player is on.
		if (zone == NULL || zone->getZoneName() != departurePlanet)
			return GENERALERROR;

		//Check to see if this point can be reached from this location.
		if (!zone->getPlanetManager()->isTravelToLocationPermitted(departurePoint, arrivalPlanet, arrivalPoint))
			return GENERALERROR;

		ManagedReference<SceneObject*> obj = server->getZoneServer()->createObject(String("object/tangible/travel/travel_ticket/base/base_travel_ticket.iff").hashCode(), 1);

		if (obj == NULL || !obj->isTangibleObject())
			return GENERALERROR;

		TangibleObject* tano = (TangibleObject*) obj.get();

		if (!tano->isTicketObject())
			return GENERALERROR;

		TicketObject* ticket = (TicketObject*) tano;
		ticket->setDeparturePlanet(departurePlanet);
		ticket->setDeparturePoint(departurePoint);
		ticket->setArrivalPlanet(arrivalPlanet);
		ticket->setArrivalPoint(arrivalPoint);

		inventory->addObject(ticket, -1);
		ticket->sendTo(player, true);

		ManagedReference<SuiMessageBox*> suiBox = new SuiMessageBox(player, 0);
		suiBox->setPromptTitle("");
		suiBox->setPromptText("@travel:ticket_purchase_complete"); //Ticket purchase complete

		player->sendMessage(suiBox->generateMessage());

		return SUCCESS;
	}

};

#endif //PURCHASETICKETCOMMAND_H_