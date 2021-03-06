/*
 *	server/zone/objects/area/StaticSpawnArea.h generated by engine3 IDL compiler 0.60
 */

#ifndef STATICSPAWNAREA_H_
#define STATICSPAWNAREA_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace managers {
namespace object {

class ObjectManager;

} // namespace object
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::object;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class AiAgent;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace aigroup {

class AiGroup;

} // namespace aigroup
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::aigroup;

namespace server {
namespace zone {
namespace objects {
namespace area {

class SpawnObserver;

} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area;

#include "server/zone/objects/area/SpawnArea.h"

#include "system/util/SortedVector.h"

#include "engine/core/ManagedObject.h"

#include "engine/util/Observable.h"

namespace server {
namespace zone {
namespace objects {
namespace area {

class StaticSpawnArea : public SpawnArea {
public:
	StaticSpawnArea();

	void spawnCreatures();

	bool isStaticArea();

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	StaticSpawnArea(DummyConstructorParameter* param);

	virtual ~StaticSpawnArea();

	friend class StaticSpawnAreaHelper;
};

} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area;

namespace server {
namespace zone {
namespace objects {
namespace area {

class StaticSpawnAreaImplementation : public SpawnAreaImplementation {
protected:
	SortedVector<ManagedReference<AiGroup* > > groups;

public:
	StaticSpawnAreaImplementation();

	StaticSpawnAreaImplementation(DummyConstructorParameter* param);

	void spawnCreatures();

	virtual bool isStaticArea();

	WeakReference<StaticSpawnArea*> _this;

	operator const StaticSpawnArea*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~StaticSpawnAreaImplementation();

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

	friend class StaticSpawnArea;
};

class StaticSpawnAreaAdapter : public SpawnAreaAdapter {
public:
	StaticSpawnAreaAdapter(StaticSpawnArea* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void spawnCreatures();

	bool isStaticArea();

};

class StaticSpawnAreaHelper : public DistributedObjectClassHelper, public Singleton<StaticSpawnAreaHelper> {
	static StaticSpawnAreaHelper* staticInitializer;

public:
	StaticSpawnAreaHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<StaticSpawnAreaHelper>;
};

} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area;

#endif /*STATICSPAWNAREA_H_*/
