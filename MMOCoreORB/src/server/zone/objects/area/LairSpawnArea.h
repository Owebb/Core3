/*
 *	server/zone/objects/area/LairSpawnArea.h generated by engine3 IDL compiler 0.60
 */

#ifndef LAIRSPAWNAREA_H_
#define LAIRSPAWNAREA_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace area {

class ActiveArea;

} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area;

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
namespace managers {
namespace creature {

class LairSpawnGroup;

} // namespace creature
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::creature;

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

#include "engine/core/ManagedObject.h"

#include "system/util/SortedVector.h"

#include "system/util/VectorMap.h"

#include "server/zone/objects/area/SpawnArea.h"

#include "engine/util/Observable.h"

#include "system/util/HashTable.h"

#include "system/lang/Time.h"

namespace server {
namespace zone {
namespace objects {
namespace area {

class LairSpawnArea : public SpawnArea {
public:
	static const int MINSPAWNINTERVAL = 2000;

	LairSpawnArea();

	void notifyEnter(SceneObject* object);

	void notifyExit(SceneObject* object);

	void notifyPositionUpdate(QuadTreeEntry* obj);

	int trySpawnLair(SceneObject* object);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	bool isLairSpawnArea();

	void setSpawnGroup(LairSpawnGroup* group);

	LairSpawnGroup* getSpawnGroup();

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	LairSpawnArea(DummyConstructorParameter* param);

	virtual ~LairSpawnArea();

	friend class LairSpawnAreaHelper;
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

class LairSpawnAreaImplementation : public SpawnAreaImplementation {
protected:
	Reference<LairSpawnGroup* > spawnGroup;

	int currentlySpawnedLairs;

	ManagedReference<SpawnObserver* > exitObserver;

	HashTable<unsigned int, int> spawnedGroupsCount;

	HashTable<unsigned long long, unsigned int> lairTypes;

	Time lastSpawn;

public:
	static const int MINSPAWNINTERVAL = 2000;

	LairSpawnAreaImplementation();

	LairSpawnAreaImplementation(DummyConstructorParameter* param);

	void notifyEnter(SceneObject* object);

	void notifyExit(SceneObject* object);

	void notifyPositionUpdate(QuadTreeEntry* obj);

	int trySpawnLair(SceneObject* object);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	bool isLairSpawnArea();

	void setSpawnGroup(LairSpawnGroup* group);

	LairSpawnGroup* getSpawnGroup();

	WeakReference<LairSpawnArea*> _this;

	operator const LairSpawnArea*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~LairSpawnAreaImplementation();

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

	friend class LairSpawnArea;
};

class LairSpawnAreaAdapter : public SpawnAreaAdapter {
public:
	LairSpawnAreaAdapter(LairSpawnArea* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void notifyEnter(SceneObject* object);

	void notifyExit(SceneObject* object);

	void notifyPositionUpdate(QuadTreeEntry* obj);

	int trySpawnLair(SceneObject* object);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	bool isLairSpawnArea();

};

class LairSpawnAreaHelper : public DistributedObjectClassHelper, public Singleton<LairSpawnAreaHelper> {
	static LairSpawnAreaHelper* staticInitializer;

public:
	LairSpawnAreaHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<LairSpawnAreaHelper>;
};

} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area;

#endif /*LAIRSPAWNAREA_H_*/
