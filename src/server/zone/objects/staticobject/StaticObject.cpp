/*
 *	server/zone/objects/staticobject/StaticObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "StaticObject.h"

#include "server/zone/Zone.h"

#include "server/zone/templates/SharedObjectTemplate.h"

/*
 *	StaticObjectStub
 */

enum {RPC_SENDBASELINESTO__SCENEOBJECT_};

StaticObject::StaticObject() : SceneObject(DummyConstructorParameter::instance()) {
	StaticObjectImplementation* _implementation = new StaticObjectImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

StaticObject::StaticObject(DummyConstructorParameter* param) : SceneObject(param) {
}

StaticObject::~StaticObject() {
}


void StaticObject::loadTemplateData(SharedObjectTemplate* templateData) {
	StaticObjectImplementation* _implementation = (StaticObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->loadTemplateData(templateData);
}

void StaticObject::sendBaselinesTo(SceneObject* player) {
	StaticObjectImplementation* _implementation = (StaticObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDBASELINESTO__SCENEOBJECT_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendBaselinesTo(player);
}

DistributedObjectServant* StaticObject::_getImplementation() {

	_updated = true;
	return _impl;
}

void StaticObject::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	StaticObjectImplementation
 */

StaticObjectImplementation::StaticObjectImplementation(DummyConstructorParameter* param) : SceneObjectImplementation(param) {
	_initializeImplementation();
}


StaticObjectImplementation::~StaticObjectImplementation() {
}


void StaticObjectImplementation::finalize() {
}

void StaticObjectImplementation::_initializeImplementation() {
	_setClassHelper(StaticObjectHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void StaticObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (StaticObject*) stub;
	SceneObjectImplementation::_setStub(stub);
}

DistributedObjectStub* StaticObjectImplementation::_getStub() {
	return _this;
}

StaticObjectImplementation::operator const StaticObject*() {
	return _this;
}

void StaticObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void StaticObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void StaticObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void StaticObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void StaticObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void StaticObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void StaticObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void StaticObjectImplementation::_serializationHelperMethod() {
	SceneObjectImplementation::_serializationHelperMethod();

	_setClassName("StaticObject");

}

void StaticObjectImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(StaticObjectImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool StaticObjectImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (SceneObjectImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void StaticObjectImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = StaticObjectImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int StaticObjectImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + SceneObjectImplementation::writeObjectMembers(stream);
}

StaticObjectImplementation::StaticObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/staticobject/StaticObject.idl():  		Logger.setLoggingName("StaticObject");
	Logger::setLoggingName("StaticObject");
	// server/zone/objects/staticobject/StaticObject.idl():  		Logger.setLogging(false);
	Logger::setLogging(false);
	// server/zone/objects/staticobject/StaticObject.idl():  		Logger.setGlobalLogging(true);
	Logger::setGlobalLogging(true);
}

void StaticObjectImplementation::loadTemplateData(SharedObjectTemplate* templateData) {
	// server/zone/objects/staticobject/StaticObject.idl():  		super.loadTemplateData(templateData);
	SceneObjectImplementation::loadTemplateData(templateData);
}

/*
 *	StaticObjectAdapter
 */

StaticObjectAdapter::StaticObjectAdapter(StaticObjectImplementation* obj) : SceneObjectAdapter(obj) {
}

Packet* StaticObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_SENDBASELINESTO__SCENEOBJECT_:
		sendBaselinesTo((SceneObject*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void StaticObjectAdapter::sendBaselinesTo(SceneObject* player) {
	((StaticObjectImplementation*) impl)->sendBaselinesTo(player);
}

/*
 *	StaticObjectHelper
 */

StaticObjectHelper* StaticObjectHelper::staticInitializer = StaticObjectHelper::instance();

StaticObjectHelper::StaticObjectHelper() {
	className = "StaticObject";

	Core::getObjectBroker()->registerClass(className, this);
}

void StaticObjectHelper::finalizeHelper() {
	StaticObjectHelper::finalize();
}

DistributedObject* StaticObjectHelper::instantiateObject() {
	return new StaticObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* StaticObjectHelper::instantiateServant() {
	return new StaticObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* StaticObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new StaticObjectAdapter((StaticObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}
