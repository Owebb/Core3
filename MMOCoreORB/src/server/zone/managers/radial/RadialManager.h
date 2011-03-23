/*
 *	server/zone/managers/radial/RadialManager.h generated by engine3 IDL compiler 0.60
 */

#ifndef RADIALMANAGER_H_
#define RADIALMANAGER_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {

class ZoneServer;

} // namespace zone
} // namespace server

using namespace server::zone;

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
namespace packets {
namespace object {

class ObjectMenuResponse;

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;

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

#include "engine/core/ManagedObject.h"

#include "engine/log/Logger.h"

namespace server {
namespace zone {
namespace managers {
namespace radial {

class RadialManager : public ManagedObject {
public:
	RadialManager(ZoneServer* server);

	void handleObjectMenuSelect(PlayerCreature* player, byte selectID, unsigned long long objectID);

	void handleObjectMenuRequest(PlayerCreature* player, ObjectMenuResponse* defaultMenuResponse, unsigned long long objectID);

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	RadialManager(DummyConstructorParameter* param);

	virtual ~RadialManager();

	friend class RadialManagerHelper;
};

} // namespace radial
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::radial;

namespace server {
namespace zone {
namespace managers {
namespace radial {

class RadialManagerImplementation : public ManagedObjectImplementation, public Logger {
	ManagedWeakReference<ZoneServer* > zoneServer;

public:
	RadialManagerImplementation(ZoneServer* server);

	RadialManagerImplementation(DummyConstructorParameter* param);

	void handleObjectMenuSelect(PlayerCreature* player, byte selectID, unsigned long long objectID);

	void handleObjectMenuRequest(PlayerCreature* player, ObjectMenuResponse* defaultMenuResponse, unsigned long long objectID);

	RadialManager* _this;

	operator const RadialManager*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~RadialManagerImplementation();

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

	friend class RadialManager;
};

class RadialManagerAdapter : public ManagedObjectAdapter {
public:
	RadialManagerAdapter(RadialManagerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void handleObjectMenuSelect(PlayerCreature* player, byte selectID, unsigned long long objectID);

	void handleObjectMenuRequest(PlayerCreature* player, ObjectMenuResponse* defaultMenuResponse, unsigned long long objectID);

};

class RadialManagerHelper : public DistributedObjectClassHelper, public Singleton<RadialManagerHelper> {
	static RadialManagerHelper* staticInitializer;

public:
	RadialManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<RadialManagerHelper>;
};

} // namespace radial
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::radial;

#endif /*RADIALMANAGER_H_*/