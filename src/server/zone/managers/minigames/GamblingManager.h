/*
 *	server/zone/managers/minigames/GamblingManager.h generated by engine3 IDL compiler 0.60
 */

#ifndef GAMBLINGMANAGER_H_
#define GAMBLINGMANAGER_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerCreature;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

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
namespace terminal {
namespace gambling {

class GamblingTerminal;

} // namespace gambling
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::gambling;

namespace server {
namespace zone {
namespace managers {
namespace minigames {
namespace events {

class GamblingEvent;

} // namespace events
} // namespace minigames
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::minigames::events;

#include "engine/util/Observer.h"

#include "engine/core/ManagedObject.h"

#include "engine/log/Logger.h"

#include "engine/lua/Lua.h"

#include "system/util/VectorMap.h"

#include "system/util/Vector.h"

#include "system/lang/ref/Reference.h"

namespace server {
namespace zone {
namespace managers {
namespace minigames {

class GamblingManager : public Observer {
public:
	GamblingManager(ZoneServer* server);

	Vector<String>* getRoulette();

	void initializeSlotTimer();

	void initializeRouletteTimer();

	void initializeSlots();

	void initializeRouletteRed();

	void initializeRoulette();

	int notify(SceneObject* sceneObject);

	bool isHigh(int value);

	bool isLow(int value);

	bool isEven(int value);

	bool isOdd(int value);

	bool isBlack(int value);

	bool isRed(int value);

	void handleSlot(PlayerCreature* player, bool cancel, bool other);

	void bet(PlayerCreature* player, int amount, int target, int machineType);

	void bet(GamblingTerminal* terminal, PlayerCreature* player, int amount, int target);

	void startGame(PlayerCreature* player, int machineType);

	void startGame(GamblingTerminal* terminal);

	void leaveTerminal(PlayerCreature* player, int machineType);

	void registerPlayer(GamblingTerminal* terminal, PlayerCreature* player);

	void refreshRouletteMenu(PlayerCreature* player);

	void continueGame(GamblingTerminal* terminal);

	void stopGame(GamblingTerminal* terminal, bool cancel);

	void calculateOutcome(GamblingTerminal* terminal);

	unsigned int createWindow(GamblingTerminal* terminal, PlayerCreature* player);

	unsigned int createPayoutWindow(PlayerCreature* player);

	unsigned int createSlotWindow(PlayerCreature* player, unsigned int payoutBoxID);

	unsigned int createRouletteWindow(PlayerCreature* player);

	void createEvent(GamblingTerminal* terminal, int time);

	bool isPlaying(PlayerCreature* player);

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	GamblingManager(DummyConstructorParameter* param);

	virtual ~GamblingManager();

	friend class GamblingManagerHelper;
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

class GamblingManagerImplementation : public ObserverImplementation, public Logger {
protected:
	ManagedReference<ZoneServer* > zoneServer;

	VectorMap<ManagedReference<PlayerCreature* >, ManagedReference<GamblingTerminal* > > slotGames;

	VectorMap<ManagedReference<PlayerCreature* >, ManagedReference<GamblingTerminal* > > rouletteGames;

	Vector<String> roulette;

	Vector<String> red;

	Vector<int> slot;

	Vector<int> slotTimer;

	Vector<int> rouletteTimer;

public:
	GamblingManagerImplementation(ZoneServer* server);

	GamblingManagerImplementation(DummyConstructorParameter* param);

	Vector<String>* getRoulette();

	void initializeSlotTimer();

	void initializeRouletteTimer();

	void initializeSlots();

	void initializeRouletteRed();

	void initializeRoulette();

	int notify(SceneObject* sceneObject);

	bool isHigh(int value);

	bool isLow(int value);

	bool isEven(int value);

	bool isOdd(int value);

	bool isBlack(int value);

	bool isRed(int value);

	void handleSlot(PlayerCreature* player, bool cancel, bool other);

protected:
	void refreshSlotMenu(PlayerCreature* player, GamblingTerminal* terminal);

public:
	void bet(PlayerCreature* player, int amount, int target, int machineType);

	void bet(GamblingTerminal* terminal, PlayerCreature* player, int amount, int target);

	void startGame(PlayerCreature* player, int machineType);

	void startGame(GamblingTerminal* terminal);

	void leaveTerminal(PlayerCreature* player, int machineType);

	void registerPlayer(GamblingTerminal* terminal, PlayerCreature* player);

	void refreshRouletteMenu(PlayerCreature* player);

	void continueGame(GamblingTerminal* terminal);

	void stopGame(GamblingTerminal* terminal, bool cancel);

	void calculateOutcome(GamblingTerminal* terminal);

	unsigned int createWindow(GamblingTerminal* terminal, PlayerCreature* player);

	unsigned int createPayoutWindow(PlayerCreature* player);

	unsigned int createSlotWindow(PlayerCreature* player, unsigned int payoutBoxID);

	unsigned int createRouletteWindow(PlayerCreature* player);

	void createEvent(GamblingTerminal* terminal, int time);

	bool isPlaying(PlayerCreature* player);

	GamblingManager* _this;

	operator const GamblingManager*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~GamblingManagerImplementation();

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
	bool readObjectMember(ObjectInputStream* stream, const String& name);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class GamblingManager;
};

class GamblingManagerAdapter : public ObserverAdapter {
public:
	GamblingManagerAdapter(GamblingManagerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeSlotTimer();

	void initializeRouletteTimer();

	void initializeSlots();

	void initializeRouletteRed();

	void initializeRoulette();

	int notify(SceneObject* sceneObject);

	bool isHigh(int value);

	bool isLow(int value);

	bool isEven(int value);

	bool isOdd(int value);

	bool isBlack(int value);

	bool isRed(int value);

	void handleSlot(PlayerCreature* player, bool cancel, bool other);

	void bet(PlayerCreature* player, int amount, int target, int machineType);

	void bet(GamblingTerminal* terminal, PlayerCreature* player, int amount, int target);

	void startGame(PlayerCreature* player, int machineType);

	void startGame(GamblingTerminal* terminal);

	void leaveTerminal(PlayerCreature* player, int machineType);

	void registerPlayer(GamblingTerminal* terminal, PlayerCreature* player);

	void refreshRouletteMenu(PlayerCreature* player);

	void continueGame(GamblingTerminal* terminal);

	void stopGame(GamblingTerminal* terminal, bool cancel);

	void calculateOutcome(GamblingTerminal* terminal);

	unsigned int createWindow(GamblingTerminal* terminal, PlayerCreature* player);

	unsigned int createPayoutWindow(PlayerCreature* player);

	unsigned int createSlotWindow(PlayerCreature* player, unsigned int payoutBoxID);

	unsigned int createRouletteWindow(PlayerCreature* player);

	void createEvent(GamblingTerminal* terminal, int time);

	bool isPlaying(PlayerCreature* player);

};

class GamblingManagerHelper : public DistributedObjectClassHelper, public Singleton<GamblingManagerHelper> {
	static GamblingManagerHelper* staticInitializer;

public:
	GamblingManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<GamblingManagerHelper>;
};

} // namespace minigames
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::minigames;

#endif /*GAMBLINGMANAGER_H_*/