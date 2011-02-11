/*
 *	server/zone/objects/creature/aigroup/AiGroup.h generated by engine3 IDL compiler 0.60
 */

#ifndef AIGROUP_H_
#define AIGROUP_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

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
namespace managers {
namespace creature {

class StaticSpawnGroup;

} // namespace creature
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::creature;

namespace server {
namespace zone {
namespace managers {
namespace creature {

class DynamicSpawnGroup;

} // namespace creature
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::creature;

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace aigroup {

class AiGroupObserver;

} // namespace aigroup
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::aigroup;

#include "server/zone/objects/scene/SceneObject.h"

#include "engine/core/ManagedObject.h"

#include "engine/util/u3d/Coordinate.h"

#include "system/util/SortedVector.h"

#include "system/util/Vector.h"

#include "engine/util/Observable.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace aigroup {

class AiGroup : public SceneObject {
public:
	AiGroup();

	void setPatrolPoints();

	void setPatrolPoint(AiAgent* member);

	void setup(StaticSpawnGroup* templ);

	void setup(DynamicSpawnGroup* templ);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	bool isHerdGroup();

	bool isPackGroup();

	bool isLairGroup();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	AiGroup(DummyConstructorParameter* param);

	virtual ~AiGroup();

	friend class AiGroupHelper;
};

} // namespace aigroup
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::aigroup;

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace aigroup {

class AiGroupImplementation : public SceneObjectImplementation {
protected:
	ManagedReference<SceneObject* > leader;

	SortedVector<ManagedReference<AiAgent* > > scouts;

	Vector<String> scoutTemps;

	SortedVector<ManagedReference<AiAgent* > > protectors;

	Vector<String> protectorTemps;

	SortedVector<ManagedReference<AiAgent* > > babies;

	Vector<String> babyTemps;

	SortedVector<ManagedReference<AiGroup* > > subgroups;

	SortedVector<ManagedReference<AiGroupObserver* > > observers;

	int commandLevel;

	float wanderRadius;

	int size;

	float scoutWeight;

	float protectorWeight;

	float babyWeight;

	bool isStatic;

public:
	AiGroupImplementation();

	AiGroupImplementation(DummyConstructorParameter* param);

	void setPatrolPoints();

	void setPatrolPoint(AiAgent* member);

	void setup(StaticSpawnGroup* templ);

	void setup(DynamicSpawnGroup* templ);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	virtual bool isHerdGroup();

	virtual bool isPackGroup();

	virtual bool isLairGroup();

	AiGroup* _this;

	operator const AiGroup*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~AiGroupImplementation();

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

	friend class AiGroup;
};

class AiGroupAdapter : public SceneObjectAdapter {
public:
	AiGroupAdapter(AiGroupImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void setPatrolPoints();

	void setPatrolPoint(AiAgent* member);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	bool isHerdGroup();

	bool isPackGroup();

	bool isLairGroup();

};

class AiGroupHelper : public DistributedObjectClassHelper, public Singleton<AiGroupHelper> {
	static AiGroupHelper* staticInitializer;

public:
	AiGroupHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<AiGroupHelper>;
};

} // namespace aigroup
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::aigroup;

#endif /*AIGROUP_H_*/
