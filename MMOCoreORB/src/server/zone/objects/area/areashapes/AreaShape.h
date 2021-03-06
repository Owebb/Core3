/*
 *	server/zone/objects/area/areashapes/AreaShape.h generated by engine3 IDL compiler 0.60
 */

#ifndef AREASHAPE_H_
#define AREASHAPE_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

#include "engine/core/ManagedObject.h"

#include "engine/util/u3d/Vector3.h"

namespace server {
namespace zone {
namespace objects {
namespace area {
namespace areashapes {

class AreaShape : public ManagedObject {
public:
	AreaShape();

	void setAreaCenter(float x, float y);

	Vector3 getAreaCenter();

	bool containsPoint(float x, float y);

	bool containsPoint(const Vector3& point);

	float getRadius();

	Vector3 getRandomPosition();

	Vector3 getRandomPosition(const Vector3& origin, float minDistance, float maxDistance);

	bool isCircularAreaShape();

	bool isRectangularAreaShape();

	bool intersectsWith(AreaShape* areaShape);

	float getArea();

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	AreaShape(DummyConstructorParameter* param);

	virtual ~AreaShape();

	friend class AreaShapeHelper;
};

} // namespace areashapes
} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area::areashapes;

namespace server {
namespace zone {
namespace objects {
namespace area {
namespace areashapes {

class AreaShapeImplementation : public ManagedObjectImplementation {
protected:
	Vector3 areaCenter;

public:
	AreaShapeImplementation();

	AreaShapeImplementation(DummyConstructorParameter* param);

	void setAreaCenter(float x, float y);

	Vector3 getAreaCenter();

	virtual bool containsPoint(float x, float y);

	virtual bool containsPoint(const Vector3& point);

	virtual float getRadius();

	virtual Vector3 getRandomPosition();

	virtual Vector3 getRandomPosition(const Vector3& origin, float minDistance, float maxDistance);

	virtual bool isCircularAreaShape();

	virtual bool isRectangularAreaShape();

	virtual bool intersectsWith(AreaShape* areaShape);

	virtual float getArea();

	WeakReference<AreaShape*> _this;

	operator const AreaShape*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~AreaShapeImplementation();

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

	friend class AreaShape;
};

class AreaShapeAdapter : public ManagedObjectAdapter {
public:
	AreaShapeAdapter(AreaShape* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void setAreaCenter(float x, float y);

	bool containsPoint(float x, float y);

	float getRadius();

	bool isCircularAreaShape();

	bool isRectangularAreaShape();

	bool intersectsWith(AreaShape* areaShape);

	float getArea();

};

class AreaShapeHelper : public DistributedObjectClassHelper, public Singleton<AreaShapeHelper> {
	static AreaShapeHelper* staticInitializer;

public:
	AreaShapeHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<AreaShapeHelper>;
};

} // namespace areashapes
} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area::areashapes;

#endif /*AREASHAPE_H_*/
