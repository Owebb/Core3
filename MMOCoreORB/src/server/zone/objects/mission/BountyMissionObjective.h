/*
 *	server/zone/objects/mission/BountyMissionObjective.h generated by engine3 IDL compiler 0.60
 */

#ifndef BOUNTYMISSIONOBJECTIVE_H_
#define BOUNTYMISSIONOBJECTIVE_H_

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
namespace creature {

class AiAgent;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace templates {

class SharedObjectTemplate;

} // namespace templates
} // namespace zone
} // namespace server

using namespace server::zone::templates;

namespace server {
namespace zone {
namespace objects {
namespace mission {
namespace bountyhunter {

class BountyHunterDroid;

} // namespace bountyhunter
} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission::bountyhunter;

namespace server {
namespace zone {
namespace objects {
namespace mission {
namespace bountyhunter {
namespace events {

class BountyHunterTargetTask;

} // namespace events
} // namespace bountyhunter
} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission::bountyhunter::events;

#include "server/zone/templates/TemplateReference.h"

#include "server/zone/objects/mission/bountyhunter/events/FindTargetTaskList.h"

#include "engine/util/Observer.h"

#include "engine/util/Observable.h"

#include "engine/core/Task.h"

#include "server/zone/objects/mission/MissionObjective.h"

#include "system/thread/Mutex.h"

namespace server {
namespace zone {
namespace objects {
namespace mission {

class BountyMissionObjective : public MissionObjective {
public:
	static const int INITSTATUS = 0;

	static const int HASBIOSIGNATURESTATUS = 1;

	static const int HASTALKED = 2;

	static const int TARGETELIMINATEDSTATUS = 3;

	BountyMissionObjective(MissionObject* mission);

	void initializeTransientMembers();

	void activate();

	void abort();

	void complete();

	void spawnTarget(const String& zoneName);

	int notifyObserverEvent(MissionObserver* observer, unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void setNpcTemplateToSpawn(SharedObjectTemplate* sp);

	void updateMissionStatus(int informantLevel);

	int getObjectiveStatus();

	SceneObject* getArakydDroid();

	void setArakydDroid(SceneObject* droid);

	void performDroidAction(int action, SceneObject* sceneObject, CreatureObject* player);

	bool playerHasMissionOfCorrectLevel(int action);

	void updateWaypoint();

	Vector3 getTargetPosition();

	void cancelAllTasks();

	String getTargetZoneName();

	Vector3 getEndPosition();

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	BountyMissionObjective(DummyConstructorParameter* param);

	virtual ~BountyMissionObjective();

	friend class BountyMissionObjectiveHelper;
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

class BountyMissionObjectiveImplementation : public MissionObjectiveImplementation {
protected:
	TemplateReference<SharedObjectTemplate*> npcTemplateToSpawn;

	ManagedReference<AiAgent* > npcTarget;

	int objectiveStatus;

	ManagedReference<SceneObject* > activeDroid;

	Reference<BountyHunterDroid* > droid;

	FindTargetTaskList droidTasks;

	Reference<BountyHunterTargetTask* > targetTask;

	Mutex syncMutex;

public:
	static const int INITSTATUS = 0;

	static const int HASBIOSIGNATURESTATUS = 1;

	static const int HASTALKED = 2;

	static const int TARGETELIMINATEDSTATUS = 3;

	BountyMissionObjectiveImplementation(MissionObject* mission);

	BountyMissionObjectiveImplementation(DummyConstructorParameter* param);

	void finalize();

	void initializeTransientMembers();

	void activate();

	void abort();

	void complete();

	void spawnTarget(const String& zoneName);

	int notifyObserverEvent(MissionObserver* observer, unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void setNpcTemplateToSpawn(SharedObjectTemplate* sp);

	void updateMissionStatus(int informantLevel);

	int getObjectiveStatus();

	SceneObject* getArakydDroid();

	void setArakydDroid(SceneObject* droid);

	void performDroidAction(int action, SceneObject* sceneObject, CreatureObject* player);

	bool playerHasMissionOfCorrectLevel(int action);

	void updateWaypoint();

	Vector3 getTargetPosition();

	void cancelAllTasks();

	String getTargetZoneName();

private:
	void addToBountyLock();

	void removeFromBountyLock(bool immediately);

	void removePlayerTargetObservers();

	void removeNpcTargetObservers();

	void removeObserver(int observerNumber, unsigned int observerType, CreatureObject* creature);

	void addObserverToCreature(unsigned int observerType, CreatureObject* creature);

	bool addPlayerTargetObservers();

	void startNpcTargetTask();

	bool isPlayerTarget();

	void handleNpcTargetKilled(ManagedObject* arg1);

	int handleNpcTargetReceivesDamage(ManagedObject* arg1);

	void handlePlayerKilled(ManagedObject* arg1);

	void handleDefenderAdded(ManagedObject* arg1);

	void handleDefenderDropped(ManagedObject* arg1);

public:
	Vector3 getEndPosition();

	WeakReference<BountyMissionObjective*> _this;

	operator const BountyMissionObjective*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~BountyMissionObjectiveImplementation();

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

	friend class BountyMissionObjective;
};

class BountyMissionObjectiveAdapter : public MissionObjectiveAdapter {
public:
	BountyMissionObjectiveAdapter(BountyMissionObjective* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void finalize();

	void initializeTransientMembers();

	void activate();

	void abort();

	void complete();

	void spawnTarget(const String& zoneName);

	int notifyObserverEvent(MissionObserver* observer, unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void updateMissionStatus(int informantLevel);

	int getObjectiveStatus();

	SceneObject* getArakydDroid();

	void setArakydDroid(SceneObject* droid);

	void performDroidAction(int action, SceneObject* sceneObject, CreatureObject* player);

	bool playerHasMissionOfCorrectLevel(int action);

	void updateWaypoint();

	void cancelAllTasks();

	String getTargetZoneName();

};

class BountyMissionObjectiveHelper : public DistributedObjectClassHelper, public Singleton<BountyMissionObjectiveHelper> {
	static BountyMissionObjectiveHelper* staticInitializer;

public:
	BountyMissionObjectiveHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<BountyMissionObjectiveHelper>;
};

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

#endif /*BOUNTYMISSIONOBJECTIVE_H_*/
