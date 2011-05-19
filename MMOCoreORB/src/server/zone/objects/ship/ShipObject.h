/*
 *	server/zone/objects/ship/ShipObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef SHIPOBJECT_H_
#define SHIPOBJECT_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

#include "engine/core/ManagedObject.h"

#include "server/zone/objects/tangible/TangibleObject.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {

class ShipObject : public TangibleObject {
public:
	ShipObject();

	void sendTo(SceneObject* player, bool doClose);

	void sendBaselinesTo(SceneObject* player);

	float getTotalMass();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	ShipObject(DummyConstructorParameter* param);

	virtual ~ShipObject();

	friend class ShipObjectHelper;
};

} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship;

namespace server {
namespace zone {
namespace objects {
namespace ship {

class ShipObjectImplementation : public TangibleObjectImplementation {
protected:
	float totalMass;

public:
	ShipObjectImplementation();

	ShipObjectImplementation(DummyConstructorParameter* param);

	void sendTo(SceneObject* player, bool doClose);

	void sendBaselinesTo(SceneObject* player);

	float getTotalMass();

	ShipObject* _this;

	operator const ShipObject*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~ShipObjectImplementation();

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

	friend class ShipObject;
};

class ShipObjectAdapter : public TangibleObjectAdapter {
public:
	ShipObjectAdapter(ShipObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void sendTo(SceneObject* player, bool doClose);

	void sendBaselinesTo(SceneObject* player);

	float getTotalMass();

};

class ShipObjectHelper : public DistributedObjectClassHelper, public Singleton<ShipObjectHelper> {
	static ShipObjectHelper* staticInitializer;

public:
	ShipObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<ShipObjectHelper>;
};

} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship;

#endif /*SHIPOBJECT_H_*/