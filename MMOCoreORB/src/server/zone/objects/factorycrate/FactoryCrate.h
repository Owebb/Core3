/*
 *	server/zone/objects/factorycrate/FactoryCrate.h generated by engine3 IDL compiler 0.60
 */

#ifndef FACTORYCRATE_H_
#define FACTORYCRATE_H_

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

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace packets {
namespace scene {

class AttributeListMessage;

} // namespace scene
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::scene;

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
namespace variables {

class ContainerPermissions;

} // namespace variables
} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene::variables;

#include "server/zone/objects/tangible/OptionBitmask.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "system/util/VectorMap.h"

#include "engine/lua/LuaObject.h"

#include "server/zone/objects/tangible/TangibleObject.h"

namespace server {
namespace zone {
namespace objects {
namespace factorycrate {

class FactoryCrate : public TangibleObject {
public:
	FactoryCrate();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void initializeTransientMembers();

	void sendBaselinesTo(SceneObject* player);

	void fillAttributeList(AttributeListMessage* msg, CreatureObject* object);

	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player);

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	bool isFactoryCrate();

	int getMaxCapacity();

	void setMaxCapacity(int value);

	void setUseCount(unsigned int newUseCount, bool notifyClient = true);

	TangibleObject* getPrototype();

	String getCraftersName();

	String getSerialNumber();

	bool extractObjectToParent();

	TangibleObject* extractObject(int count = 1);

	void split(int newStackSize);

	int getCountableObjectsRecursive();

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	FactoryCrate(DummyConstructorParameter* param);

	virtual ~FactoryCrate();

	friend class FactoryCrateHelper;
};

} // namespace factorycrate
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::factorycrate;

namespace server {
namespace zone {
namespace objects {
namespace factorycrate {

class FactoryCrateImplementation : public TangibleObjectImplementation {
protected:
	int maxCapacity;

public:
	FactoryCrateImplementation();

	FactoryCrateImplementation(DummyConstructorParameter* param);

	void loadTemplateData(SharedObjectTemplate* templateData);

	void initializeTransientMembers();

	void sendBaselinesTo(SceneObject* player);

	void fillAttributeList(AttributeListMessage* msg, CreatureObject* object);

	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player);

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	virtual bool isFactoryCrate();

	int getMaxCapacity();

	void setMaxCapacity(int value);

	void setUseCount(unsigned int newUseCount, bool notifyClient = true);

	TangibleObject* getPrototype();

	String getCraftersName();

	String getSerialNumber();

	bool extractObjectToParent();

	TangibleObject* extractObject(int count = 1);

	void split(int newStackSize);

	virtual int getCountableObjectsRecursive();

	WeakReference<FactoryCrate*> _this;

	operator const FactoryCrate*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~FactoryCrateImplementation();

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

	friend class FactoryCrate;
};

class FactoryCrateAdapter : public TangibleObjectAdapter {
public:
	FactoryCrateAdapter(FactoryCrate* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	void sendBaselinesTo(SceneObject* player);

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	bool isFactoryCrate();

	int getMaxCapacity();

	void setMaxCapacity(int value);

	void setUseCount(unsigned int newUseCount, bool notifyClient);

	TangibleObject* getPrototype();

	String getCraftersName();

	String getSerialNumber();

	bool extractObjectToParent();

	TangibleObject* extractObject(int count);

	void split(int newStackSize);

	int getCountableObjectsRecursive();

};

class FactoryCrateHelper : public DistributedObjectClassHelper, public Singleton<FactoryCrateHelper> {
	static FactoryCrateHelper* staticInitializer;

public:
	FactoryCrateHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<FactoryCrateHelper>;
};

} // namespace factorycrate
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::factorycrate;

#endif /*FACTORYCRATE_H_*/
