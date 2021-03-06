/*
 *	server/zone/objects/area/SpawnArea.h generated by engine3 IDL compiler 0.60
 */

#ifndef SPAWNAREA_H_
#define SPAWNAREA_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

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

#include "server/zone/objects/area/ActiveArea.h"

#include "system/util/SortedVector.h"

#include "engine/core/ManagedObject.h"

#include "engine/util/Observable.h"

namespace server {
namespace zone {
namespace objects {
namespace area {

class SpawnArea : public ActiveArea {
public:
	SpawnArea();

	void registerObservers();

	Vector3 getRandomPosition(SceneObject* player);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void addTemplate(unsigned int tempCRC);

	void setTier(int n);

	void setSpawnConstant(int n);

	void addNoSpawnArea(SpawnArea* area);

	bool isStaticArea();

	bool isDynamicArea();

	bool isLairSpawnArea();

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	SpawnArea(DummyConstructorParameter* param);

	virtual ~SpawnArea();

	friend class SpawnAreaHelper;
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

class SpawnAreaImplementation : public ActiveAreaImplementation {
protected:
	SortedVector<unsigned int> spawnCreatureTemplates;

	SortedVector<ManagedReference<SpawnObserver* > > observers;

	Vector<ManagedReference<SpawnArea* > > noSpawnAreas;

	int tier;

	int spawnConstant;

public:
	SpawnAreaImplementation();

	SpawnAreaImplementation(DummyConstructorParameter* param);

	virtual void registerObservers();

	Vector3 getRandomPosition(SceneObject* player);

	virtual int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void addTemplate(unsigned int tempCRC);

	void setTier(int n);

	void setSpawnConstant(int n);

	void addNoSpawnArea(SpawnArea* area);

	virtual bool isStaticArea();

	virtual bool isDynamicArea();

	virtual bool isLairSpawnArea();

	WeakReference<SpawnArea*> _this;

	operator const SpawnArea*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~SpawnAreaImplementation();

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

	friend class SpawnArea;
};

class SpawnAreaAdapter : public ActiveAreaAdapter {
public:
	SpawnAreaAdapter(SpawnArea* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void registerObservers();

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void addTemplate(unsigned int tempCRC);

	void setTier(int n);

	void setSpawnConstant(int n);

	void addNoSpawnArea(SpawnArea* area);

	bool isStaticArea();

	bool isDynamicArea();

	bool isLairSpawnArea();

};

class SpawnAreaHelper : public DistributedObjectClassHelper, public Singleton<SpawnAreaHelper> {
	static SpawnAreaHelper* staticInitializer;

public:
	SpawnAreaHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<SpawnAreaHelper>;
};

} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area;

#endif /*SPAWNAREA_H_*/
