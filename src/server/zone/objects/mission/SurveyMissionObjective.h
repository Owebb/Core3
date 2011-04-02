/*
 *	server/zone/objects/mission/SurveyMissionObjective.h generated by engine3 IDL compiler 0.60
 */

#ifndef SURVEYMISSIONOBJECTIVE_H_
#define SURVEYMISSIONOBJECTIVE_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace mission {

class MissionObject;

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

namespace server {
namespace zone {
namespace objects {
namespace mission {

class MissionObserver;

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

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
namespace resource {

class ResourceSpawn;

} // namespace resource
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::resource;

#include "engine/util/Observer.h"

#include "engine/util/Observable.h"

#include "server/zone/objects/mission/MissionObjective.h"

namespace server {
namespace zone {
namespace objects {
namespace mission {

class SurveyMissionObjective : public MissionObjective {
public:
	SurveyMissionObjective(MissionObject* mission);

	void initializeTransientMembers();

	void activate();

	void abort();

	void complete();

	int notifyObserverEvent(MissionObserver* observer, unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void setSpawn(ResourceSpawn* sp);

	void setMissionGiver(SceneObject* object);

	void setEfficiency(unsigned int eff);

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	SurveyMissionObjective(DummyConstructorParameter* param);

	virtual ~SurveyMissionObjective();

	friend class SurveyMissionObjectiveHelper;
};

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

namespace server {
namespace zone {
namespace objects {
namespace mission {

class SurveyMissionObjectiveImplementation : public MissionObjectiveImplementation {
protected:
	ManagedReference<ResourceSpawn* > spawn;

	unsigned int efficiency;

	ManagedReference<SceneObject* > missionGiver;

public:
	SurveyMissionObjectiveImplementation(MissionObject* mission);

	SurveyMissionObjectiveImplementation(DummyConstructorParameter* param);

	void finalize();

	void initializeTransientMembers();

	void activate();

	void abort();

	void complete();

	int notifyObserverEvent(MissionObserver* observer, unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void setSpawn(ResourceSpawn* sp);

	void setMissionGiver(SceneObject* object);

	void setEfficiency(unsigned int eff);

	SurveyMissionObjective* _this;

	operator const SurveyMissionObjective*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~SurveyMissionObjectiveImplementation();

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

	friend class SurveyMissionObjective;
};

class SurveyMissionObjectiveAdapter : public MissionObjectiveAdapter {
public:
	SurveyMissionObjectiveAdapter(SurveyMissionObjectiveImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void finalize();

	void initializeTransientMembers();

	void activate();

	void abort();

	void complete();

	int notifyObserverEvent(MissionObserver* observer, unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void setSpawn(ResourceSpawn* sp);

	void setMissionGiver(SceneObject* object);

	void setEfficiency(unsigned int eff);

};

class SurveyMissionObjectiveHelper : public DistributedObjectClassHelper, public Singleton<SurveyMissionObjectiveHelper> {
	static SurveyMissionObjectiveHelper* staticInitializer;

public:
	SurveyMissionObjectiveHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<SurveyMissionObjectiveHelper>;
};

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

#endif /*SURVEYMISSIONOBJECTIVE_H_*/