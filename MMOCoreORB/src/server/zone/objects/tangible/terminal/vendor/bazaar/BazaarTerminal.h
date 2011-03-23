/*
 *	server/zone/objects/tangible/terminal/vendor/bazaar/BazaarTerminal.h generated by engine3 IDL compiler 0.60
 */

#ifndef BAZAARTERMINAL_H_
#define BAZAARTERMINAL_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

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

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

#include "server/zone/objects/auction/Vendor.h"

#include "server/zone/objects/tangible/terminal/vendor/VendorTerminal.h"

#include "system/util/VectorMap.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace vendor {
namespace bazaar {

class BazaarTerminal : public VendorTerminal {
public:
	BazaarTerminal();

	void loadTemplateData(SharedObjectTemplate* templateData);

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	bool isBazaarTerminal();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	BazaarTerminal(DummyConstructorParameter* param);

	virtual ~BazaarTerminal();

	friend class BazaarTerminalHelper;
};

} // namespace bazaar
} // namespace vendor
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::vendor::bazaar;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace vendor {
namespace bazaar {

class BazaarTerminalImplementation : public VendorTerminalImplementation {

public:
	BazaarTerminalImplementation();

	BazaarTerminalImplementation(DummyConstructorParameter* param);

	void loadTemplateData(SharedObjectTemplate* templateData);

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	virtual bool isBazaarTerminal();

	BazaarTerminal* _this;

	operator const BazaarTerminal*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~BazaarTerminalImplementation();

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

	friend class BazaarTerminal;
};

class BazaarTerminalAdapter : public VendorTerminalAdapter {
public:
	BazaarTerminalAdapter(BazaarTerminalImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	bool isBazaarTerminal();

};

class BazaarTerminalHelper : public DistributedObjectClassHelper, public Singleton<BazaarTerminalHelper> {
	static BazaarTerminalHelper* staticInitializer;

public:
	BazaarTerminalHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<BazaarTerminalHelper>;
};

} // namespace bazaar
} // namespace vendor
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::vendor::bazaar;

#endif /*BAZAARTERMINAL_H_*/