/*
 *	server/zone/objects/creature/aigroup/AiGroupObserver.h generated by engine3 IDL compiler 0.60
 */

#ifndef AIGROUPOBSERVER_H_
#define AIGROUPOBSERVER_H_

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
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

#include "engine/util/Observer.h"

#include "engine/util/Observable.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace aigroup {

class AiGroupObserver : public Observer {
public:
	AiGroupObserver(AiGroup* group);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	AiGroupObserver(DummyConstructorParameter* param);

	virtual ~AiGroupObserver();

	friend class AiGroupObserverHelper;
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

class AiGroupObserverImplementation : public ObserverImplementation, public Logger {
protected:
	ManagedReference<AiGroup* > aiGroup;

public:
	AiGroupObserverImplementation(AiGroup* group);

	AiGroupObserverImplementation(DummyConstructorParameter* param);

	virtual int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	AiGroupObserver* _this;

	operator const AiGroupObserver*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~AiGroupObserverImplementation();

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

	friend class AiGroupObserver;
};

class AiGroupObserverAdapter : public ObserverAdapter {
public:
	AiGroupObserverAdapter(AiGroupObserverImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

};

class AiGroupObserverHelper : public DistributedObjectClassHelper, public Singleton<AiGroupObserverHelper> {
	static AiGroupObserverHelper* staticInitializer;

public:
	AiGroupObserverHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<AiGroupObserverHelper>;
};

} // namespace aigroup
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::aigroup;

#endif /*AIGROUPOBSERVER_H_*/