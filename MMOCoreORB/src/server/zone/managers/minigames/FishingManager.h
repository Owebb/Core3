/*
 *	server/zone/managers/minigames/FishingManager.h generated by engine3 IDL compiler 0.60
 */

#ifndef FISHINGMANAGER_H_
#define FISHINGMANAGER_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObject;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {

class ZoneServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace fishing {

class FishingPoleObject;

} // namespace fishing
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::fishing;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace fishing {

class FishingBaitObject;

} // namespace fishing
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::fishing;

namespace server {
namespace zone {
namespace managers {
namespace minigames {
namespace events {

class FishingEvent;

} // namespace events
} // namespace minigames
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::minigames::events;

namespace server {
namespace zone {
namespace managers {
namespace minigames {
namespace events {

class FishingSplashEvent;

} // namespace events
} // namespace minigames
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::minigames::events;

namespace server {
namespace zone {
namespace managers {
namespace minigames {

class FishingSession;

} // namespace minigames
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::minigames;

#include "server/zone/objects/scene/ObserverEventType.h"

#include "engine/log/Logger.h"

#include "engine/lua/Lua.h"

#include "system/util/VectorMap.h"

#include "system/lang/ref/Reference.h"

#include "engine/util/Observer.h"

#include "engine/util/Observable.h"

namespace server {
namespace zone {
namespace managers {
namespace minigames {

class FishingManager : public Observer {
public:
	static const int NOTFISHING = 0;

	static const int WAITING = 1;

	static const int SNAGGED = 2;

	static const int NIBBLE = 3;

	static const int BITE = 4;

	static const int CATCH = 5;

	static const int REELING = 6;

	static const int REELGAME = 7;

	static const int BLACKFISH = 0;

	static const int BLOWFISH = 1;

	static const int BLUEFISH = 2;

	static const int FAA = 3;

	static const int LAA = 4;

	static const int RAY = 5;

	static const int STRIPED = 6;

	static const int FRESH = 0;

	static const int SOGGY = 6;

	static const int MUSH = 10;

	static const int DONOTHING = 0;

	static const int TUGUP = 1;

	static const int TUGRIGHT = 2;

	static const int TUGLEFT = 3;

	static const int REEL = 4;

	static const int STOPFISHING = 5;

	static const int NOEVENT = 0;

	static const int PROCEED = 17;

	static const int MISHAP = 45;

	FishingManager();

	void initializeBaitStatus();

	void initializeProperty();

	void initializeAction();

	void initializeState();

	void initializeFishType();

	void initializeFishLength();

	void initializeLoot();

	void initializeColor();

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void checkFishingOnPositionUpdate(CreatureObject* player);

	int notifyCloseContainer(CreatureObject* player, SceneObject* container);

	int checkLocation(CreatureObject* player, int quality, float& x, float& y, float& z);

	int startFishing(CreatureObject* player);

	void stopFishing(CreatureObject* player, unsigned int boxID, bool rem);

	void fishingStep(CreatureObject* player);

	void success(CreatureObject* player, int fish, SceneObject* marker, unsigned int boxID);

	String getTime();

	void sendReward(CreatureObject* player, SceneObject* marker, SceneObject* loot);

	unsigned int createWindow(CreatureObject* player, unsigned int boxID);

	void closeMenu(CreatureObject* player, unsigned int boxID);

	int vegetation(SceneObject* marker);

	int density(SceneObject* marker);

	int getFish(CreatureObject* player);

	int getNextAction(CreatureObject* player);

	void setNextAction(CreatureObject* player, int next);

	FishingPoleObject* getPole(CreatureObject* player);

	FishingBaitObject* getBait(CreatureObject* player);

	unsigned int getFishBoxID(CreatureObject* player);

	void setFishBoxID(CreatureObject* player, unsigned int boxID);

	int getFishingState(CreatureObject* player);

	void setFishingState(CreatureObject* player, int state);

	SceneObject* getFishMarker(CreatureObject* player);

	void setFishMarker(CreatureObject* player, SceneObject* marker);

	void freeBait(CreatureObject* player);

	void fishingProceed(CreatureObject* player, int nextAction, SceneObject* marker, int fish, unsigned int boxID, int newstate, bool notifyClient, String& moodString);

	void mishapEvent(const String& text, CreatureObject* player, unsigned int boxID, bool losebait, String& moodString);

	bool loseBait(CreatureObject* player);

	void animate(CreatureObject* player, int nextAction);

	SceneObject* createMarker(float x, float y, float z, Zone* zone);

	void createSplash(float x, float y, float z, Zone* zone, CreatureObject* player);

	bool checkUpdateMarker(CreatureObject* player, float& x, float& y, float& z);

	bool isPlaying(CreatureObject* player);

	SceneObject* updateMarker(CreatureObject* player, SceneObject* marker, bool notifyPlayer);

	void removeMarker(CreatureObject* player, SceneObject* container);

	void removeSplash(SceneObject* splash);

	void createFishingSplashEvent(CreatureObject* player, SceneObject* splash);

	void createFishingSession(CreatureObject* player, FishingEvent* event, SceneObject* marker, int nextAction, int fish, unsigned int boxID, int fishingState, String& mood);

	FishingEvent* createFishingEvent(CreatureObject* player, int state);

	void stopFishingEvent(CreatureObject* player);

	FishingEvent* getFishingEvent(CreatureObject* player);

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	FishingManager(DummyConstructorParameter* param);

	virtual ~FishingManager();

	friend class FishingManagerHelper;
};

} // namespace minigames
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::minigames;

namespace server {
namespace zone {
namespace managers {
namespace minigames {

class FishingManagerImplementation : public ObserverImplementation, public Logger {
protected:
	Vector<String> miscLoot;

	Vector<String> rareLoot;

	VectorMap<String, int> color;

	Vector<int> fishLength;

	Vector<String> fishType;

	Vector<String> state;

	Vector<String> action;

	Vector<String> property;

	Vector<String> baitStatus;

public:
	static const int NOTFISHING = 0;

	static const int WAITING = 1;

	static const int SNAGGED = 2;

	static const int NIBBLE = 3;

	static const int BITE = 4;

	static const int CATCH = 5;

	static const int REELING = 6;

	static const int REELGAME = 7;

	static const int BLACKFISH = 0;

	static const int BLOWFISH = 1;

	static const int BLUEFISH = 2;

	static const int FAA = 3;

	static const int LAA = 4;

	static const int RAY = 5;

	static const int STRIPED = 6;

	static const int FRESH = 0;

	static const int SOGGY = 6;

	static const int MUSH = 10;

	static const int DONOTHING = 0;

	static const int TUGUP = 1;

	static const int TUGRIGHT = 2;

	static const int TUGLEFT = 3;

	static const int REEL = 4;

	static const int STOPFISHING = 5;

	static const int NOEVENT = 0;

	static const int PROCEED = 17;

	static const int MISHAP = 45;

	FishingManagerImplementation();

	FishingManagerImplementation(DummyConstructorParameter* param);

	void initializeBaitStatus();

	void initializeProperty();

	void initializeAction();

	void initializeState();

	void initializeFishType();

	void initializeFishLength();

	void initializeLoot();

	void initializeColor();

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void checkFishingOnPositionUpdate(CreatureObject* player);

	int notifyCloseContainer(CreatureObject* player, SceneObject* container);

	int checkLocation(CreatureObject* player, int quality, float& x, float& y, float& z);

	int startFishing(CreatureObject* player);

	void stopFishing(CreatureObject* player, unsigned int boxID, bool rem);

	void fishingStep(CreatureObject* player);

	void success(CreatureObject* player, int fish, SceneObject* marker, unsigned int boxID);

	String getTime();

	void sendReward(CreatureObject* player, SceneObject* marker, SceneObject* loot);

	unsigned int createWindow(CreatureObject* player, unsigned int boxID);

	void closeMenu(CreatureObject* player, unsigned int boxID);

	int vegetation(SceneObject* marker);

	int density(SceneObject* marker);

	int getFish(CreatureObject* player);

	int getNextAction(CreatureObject* player);

	void setNextAction(CreatureObject* player, int next);

	FishingPoleObject* getPole(CreatureObject* player);

	FishingBaitObject* getBait(CreatureObject* player);

	unsigned int getFishBoxID(CreatureObject* player);

	void setFishBoxID(CreatureObject* player, unsigned int boxID);

	int getFishingState(CreatureObject* player);

	void setFishingState(CreatureObject* player, int state);

	SceneObject* getFishMarker(CreatureObject* player);

	void setFishMarker(CreatureObject* player, SceneObject* marker);

	void freeBait(CreatureObject* player);

	void fishingProceed(CreatureObject* player, int nextAction, SceneObject* marker, int fish, unsigned int boxID, int newstate, bool notifyClient, String& moodString);

	void mishapEvent(const String& text, CreatureObject* player, unsigned int boxID, bool losebait, String& moodString);

	bool loseBait(CreatureObject* player);

	void animate(CreatureObject* player, int nextAction);

	SceneObject* createMarker(float x, float y, float z, Zone* zone);

	void createSplash(float x, float y, float z, Zone* zone, CreatureObject* player);

	bool checkUpdateMarker(CreatureObject* player, float& x, float& y, float& z);

	bool isPlaying(CreatureObject* player);

	SceneObject* updateMarker(CreatureObject* player, SceneObject* marker, bool notifyPlayer);

	void removeMarker(CreatureObject* player, SceneObject* container);

	void removeSplash(SceneObject* splash);

	void createFishingSplashEvent(CreatureObject* player, SceneObject* splash);

	void createFishingSession(CreatureObject* player, FishingEvent* event, SceneObject* marker, int nextAction, int fish, unsigned int boxID, int fishingState, String& mood);

	FishingEvent* createFishingEvent(CreatureObject* player, int state);

	void stopFishingEvent(CreatureObject* player);

	FishingEvent* getFishingEvent(CreatureObject* player);

	WeakReference<FishingManager*> _this;

	operator const FishingManager*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~FishingManagerImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class FishingManager;
};

class FishingManagerAdapter : public ObserverAdapter {
public:
	FishingManagerAdapter(FishingManager* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeBaitStatus();

	void initializeProperty();

	void initializeAction();

	void initializeState();

	void initializeFishType();

	void initializeFishLength();

	void initializeLoot();

	void initializeColor();

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void checkFishingOnPositionUpdate(CreatureObject* player);

	int notifyCloseContainer(CreatureObject* player, SceneObject* container);

	int startFishing(CreatureObject* player);

	void stopFishing(CreatureObject* player, unsigned int boxID, bool rem);

	void fishingStep(CreatureObject* player);

	void success(CreatureObject* player, int fish, SceneObject* marker, unsigned int boxID);

	String getTime();

	void sendReward(CreatureObject* player, SceneObject* marker, SceneObject* loot);

	unsigned int createWindow(CreatureObject* player, unsigned int boxID);

	void closeMenu(CreatureObject* player, unsigned int boxID);

	int vegetation(SceneObject* marker);

	int density(SceneObject* marker);

	int getFish(CreatureObject* player);

	int getNextAction(CreatureObject* player);

	void setNextAction(CreatureObject* player, int next);

	FishingPoleObject* getPole(CreatureObject* player);

	FishingBaitObject* getBait(CreatureObject* player);

	unsigned int getFishBoxID(CreatureObject* player);

	void setFishBoxID(CreatureObject* player, unsigned int boxID);

	int getFishingState(CreatureObject* player);

	void setFishingState(CreatureObject* player, int state);

	SceneObject* getFishMarker(CreatureObject* player);

	void setFishMarker(CreatureObject* player, SceneObject* marker);

	void freeBait(CreatureObject* player);

	void fishingProceed(CreatureObject* player, int nextAction, SceneObject* marker, int fish, unsigned int boxID, int newstate, bool notifyClient, String& moodString);

	void mishapEvent(const String& text, CreatureObject* player, unsigned int boxID, bool losebait, String& moodString);

	bool loseBait(CreatureObject* player);

	void animate(CreatureObject* player, int nextAction);

	SceneObject* createMarker(float x, float y, float z, Zone* zone);

	void createSplash(float x, float y, float z, Zone* zone, CreatureObject* player);

	bool isPlaying(CreatureObject* player);

	SceneObject* updateMarker(CreatureObject* player, SceneObject* marker, bool notifyPlayer);

	void removeMarker(CreatureObject* player, SceneObject* container);

	void removeSplash(SceneObject* splash);

	void createFishingSplashEvent(CreatureObject* player, SceneObject* splash);

	void stopFishingEvent(CreatureObject* player);

};

class FishingManagerHelper : public DistributedObjectClassHelper, public Singleton<FishingManagerHelper> {
	static FishingManagerHelper* staticInitializer;

public:
	FishingManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<FishingManagerHelper>;
};

} // namespace minigames
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::minigames;

#endif /*FISHINGMANAGER_H_*/
