/*
 *	server/zone/objects/creature/aigroup/AiGroupObserver.cpp generated by engine3 IDL compiler 0.60
 */

#include "AiGroupObserver.h"

#include "server/zone/objects/creature/aigroup/AiGroup.h"

#include "server/zone/objects/scene/SceneObject.h"

/*
 *	AiGroupObserverStub
 */

enum {RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_ = 6};

AiGroupObserver::AiGroupObserver(AiGroup* group) : Observer(DummyConstructorParameter::instance()) {
	AiGroupObserverImplementation* _implementation = new AiGroupObserverImplementation(group);
	_impl = _implementation;
	_impl->_setStub(this);
}

AiGroupObserver::AiGroupObserver(DummyConstructorParameter* param) : Observer(param) {
}

AiGroupObserver::~AiGroupObserver() {
}


int AiGroupObserver::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	AiGroupObserverImplementation* _implementation = (AiGroupObserverImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_);
		method.addUnsignedIntParameter(eventType);
		method.addObjectParameter(observable);
		method.addObjectParameter(arg1);
		method.addSignedLongParameter(arg2);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->notifyObserverEvent(eventType, observable, arg1, arg2);
}

DistributedObjectServant* AiGroupObserver::_getImplementation() {

	_updated = true;
	return _impl;
}

void AiGroupObserver::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	AiGroupObserverImplementation
 */

AiGroupObserverImplementation::AiGroupObserverImplementation(DummyConstructorParameter* param) : ObserverImplementation(param) {
	_initializeImplementation();
}


AiGroupObserverImplementation::~AiGroupObserverImplementation() {
}


void AiGroupObserverImplementation::finalize() {
}

void AiGroupObserverImplementation::_initializeImplementation() {
	_setClassHelper(AiGroupObserverHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void AiGroupObserverImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (AiGroupObserver*) stub;
	ObserverImplementation::_setStub(stub);
}

DistributedObjectStub* AiGroupObserverImplementation::_getStub() {
	return _this;
}

AiGroupObserverImplementation::operator const AiGroupObserver*() {
	return _this;
}

void AiGroupObserverImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void AiGroupObserverImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void AiGroupObserverImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void AiGroupObserverImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void AiGroupObserverImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void AiGroupObserverImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void AiGroupObserverImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void AiGroupObserverImplementation::_serializationHelperMethod() {
	ObserverImplementation::_serializationHelperMethod();

	_setClassName("AiGroupObserver");

}

void AiGroupObserverImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(AiGroupObserverImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool AiGroupObserverImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ObserverImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "aiGroup") {
		TypeInfo<ManagedReference<AiGroup* > >::parseFromBinaryStream(&aiGroup, stream);
		return true;
	}


	return false;
}

void AiGroupObserverImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = AiGroupObserverImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int AiGroupObserverImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "aiGroup";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedReference<AiGroup* > >::toBinaryStream(&aiGroup, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + ObserverImplementation::writeObjectMembers(stream);
}

AiGroupObserverImplementation::AiGroupObserverImplementation(AiGroup* group) {
	_initializeImplementation();
	// server/zone/objects/creature/aigroup/AiGroupObserver.idl():  		aiGroup = group;
	aiGroup = group;
	// server/zone/objects/creature/aigroup/AiGroupObserver.idl():  		Logger.setLoggingName("AiGroupObserver");
	Logger::setLoggingName("AiGroupObserver");
}

int AiGroupObserverImplementation::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	// server/zone/objects/creature/aigroup/AiGroupObserver.idl():  			return aiGroup.notifyObserverEvent(eventType, observable, arg1, arg2);
	if (aiGroup == NULL)	// server/zone/objects/creature/aigroup/AiGroupObserver.idl():  			return 0;
	return 0;

	else 	// server/zone/objects/creature/aigroup/AiGroupObserver.idl():  			return aiGroup.notifyObserverEvent(eventType, observable, arg1, arg2);
	return aiGroup->notifyObserverEvent(eventType, observable, arg1, arg2);
}

/*
 *	AiGroupObserverAdapter
 */

AiGroupObserverAdapter::AiGroupObserverAdapter(AiGroupObserverImplementation* obj) : ObserverAdapter(obj) {
}

Packet* AiGroupObserverAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_:
		resp->insertSignedInt(notifyObserverEvent(inv->getUnsignedIntParameter(), (Observable*) inv->getObjectParameter(), (ManagedObject*) inv->getObjectParameter(), inv->getSignedLongParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

int AiGroupObserverAdapter::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	return ((AiGroupObserverImplementation*) impl)->notifyObserverEvent(eventType, observable, arg1, arg2);
}

/*
 *	AiGroupObserverHelper
 */

AiGroupObserverHelper* AiGroupObserverHelper::staticInitializer = AiGroupObserverHelper::instance();

AiGroupObserverHelper::AiGroupObserverHelper() {
	className = "AiGroupObserver";

	Core::getObjectBroker()->registerClass(className, this);
}

void AiGroupObserverHelper::finalizeHelper() {
	AiGroupObserverHelper::finalize();
}

DistributedObject* AiGroupObserverHelper::instantiateObject() {
	return new AiGroupObserver(DummyConstructorParameter::instance());
}

DistributedObjectServant* AiGroupObserverHelper::instantiateServant() {
	return new AiGroupObserverImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* AiGroupObserverHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new AiGroupObserverAdapter((AiGroupObserverImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}
