/*
 *	server/zone/objects/intangible/ControlDevice.cpp generated by engine3 IDL compiler 0.60
 */

#include "ControlDevice.h"

#include "server/zone/objects/creature/VehicleObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

/*
 *	ControlDeviceStub
 */

enum {RPC_UPDATETODATABASEALLOBJECTS__BOOL_ = 6,RPC_STOREOBJECT__PLAYERCREATURE_,RPC_GENERATEOBJECT__PLAYERCREATURE_,RPC_SETCONTROLLEDOBJECT__TANGIBLEOBJECT_,RPC_GETCONTROLLEDOBJECT__,RPC_ISCONTROLDEVICE__};

ControlDevice::ControlDevice() : IntangibleObject(DummyConstructorParameter::instance()) {
	ControlDeviceImplementation* _implementation = new ControlDeviceImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

ControlDevice::ControlDevice(DummyConstructorParameter* param) : IntangibleObject(param) {
}

ControlDevice::~ControlDevice() {
}


void ControlDevice::updateToDatabaseAllObjects(bool startTask) {
	ControlDeviceImplementation* _implementation = (ControlDeviceImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_UPDATETODATABASEALLOBJECTS__BOOL_);
		method.addBooleanParameter(startTask);

		method.executeWithVoidReturn();
	} else
		_implementation->updateToDatabaseAllObjects(startTask);
}

void ControlDevice::storeObject(PlayerCreature* player) {
	ControlDeviceImplementation* _implementation = (ControlDeviceImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_STOREOBJECT__PLAYERCREATURE_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->storeObject(player);
}

void ControlDevice::generateObject(PlayerCreature* player) {
	ControlDeviceImplementation* _implementation = (ControlDeviceImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GENERATEOBJECT__PLAYERCREATURE_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->generateObject(player);
}

void ControlDevice::setControlledObject(TangibleObject* object) {
	ControlDeviceImplementation* _implementation = (ControlDeviceImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETCONTROLLEDOBJECT__TANGIBLEOBJECT_);
		method.addObjectParameter(object);

		method.executeWithVoidReturn();
	} else
		_implementation->setControlledObject(object);
}

TangibleObject* ControlDevice::getControlledObject() {
	ControlDeviceImplementation* _implementation = (ControlDeviceImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETCONTROLLEDOBJECT__);

		return (TangibleObject*) method.executeWithObjectReturn();
	} else
		return _implementation->getControlledObject();
}

bool ControlDevice::isControlDevice() {
	ControlDeviceImplementation* _implementation = (ControlDeviceImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISCONTROLDEVICE__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isControlDevice();
}

DistributedObjectServant* ControlDevice::_getImplementation() {

	_updated = true;
	return _impl;
}

void ControlDevice::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	ControlDeviceImplementation
 */

ControlDeviceImplementation::ControlDeviceImplementation(DummyConstructorParameter* param) : IntangibleObjectImplementation(param) {
	_initializeImplementation();
}


ControlDeviceImplementation::~ControlDeviceImplementation() {
}


void ControlDeviceImplementation::finalize() {
}

void ControlDeviceImplementation::_initializeImplementation() {
	_setClassHelper(ControlDeviceHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void ControlDeviceImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (ControlDevice*) stub;
	IntangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* ControlDeviceImplementation::_getStub() {
	return _this;
}

ControlDeviceImplementation::operator const ControlDevice*() {
	return _this;
}

void ControlDeviceImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void ControlDeviceImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void ControlDeviceImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void ControlDeviceImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void ControlDeviceImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void ControlDeviceImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void ControlDeviceImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void ControlDeviceImplementation::_serializationHelperMethod() {
	IntangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("ControlDevice");

}

void ControlDeviceImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(ControlDeviceImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool ControlDeviceImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (IntangibleObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "controlledObject") {
		TypeInfo<ManagedReference<TangibleObject* > >::parseFromBinaryStream(&controlledObject, stream);
		return true;
	}


	return false;
}

void ControlDeviceImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = ControlDeviceImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int ControlDeviceImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "controlledObject";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedReference<TangibleObject* > >::toBinaryStream(&controlledObject, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + IntangibleObjectImplementation::writeObjectMembers(stream);
}

ControlDeviceImplementation::ControlDeviceImplementation() {
	_initializeImplementation();
	// server/zone/objects/intangible/ControlDevice.idl():  		controlledObject = null;
	controlledObject = NULL;
	// server/zone/objects/intangible/ControlDevice.idl():  		Logger.setLoggingName("ControlDevice");
	Logger::setLoggingName("ControlDevice");
	// server/zone/objects/intangible/ControlDevice.idl():  		Logger.setLogging(false);
	Logger::setLogging(false);
	// server/zone/objects/intangible/ControlDevice.idl():  		Logger.setGlobalLogging(true);
	Logger::setGlobalLogging(true);
}

void ControlDeviceImplementation::updateToDatabaseAllObjects(bool startTask) {
	// server/zone/objects/intangible/ControlDevice.idl():  		}
	if (controlledObject != NULL){
	// server/zone/objects/intangible/ControlDevice.idl():  			controlledObject.updateToDatabaseWithoutChildren();
	controlledObject->updateToDatabaseWithoutChildren();
	// server/zone/objects/intangible/ControlDevice.idl():  			super.updateToDatabaseAllObjects(startTask);
	IntangibleObjectImplementation::updateToDatabaseAllObjects(startTask);
}

	else {
	// server/zone/objects/intangible/ControlDevice.idl():  			super.updateToDatabaseAllObjects(startTask);
	IntangibleObjectImplementation::updateToDatabaseAllObjects(startTask);
}
}

void ControlDeviceImplementation::storeObject(PlayerCreature* player) {
	// server/zone/objects/intangible/ControlDevice.idl():  		Logger.error("called storeObject on an abstract method");
	Logger::error("called storeObject on an abstract method");
}

void ControlDeviceImplementation::generateObject(PlayerCreature* player) {
	// server/zone/objects/intangible/ControlDevice.idl():  		Logger.error("called generateObject on an abstract method");
	Logger::error("called generateObject on an abstract method");
}

void ControlDeviceImplementation::setControlledObject(TangibleObject* object) {
	// server/zone/objects/intangible/ControlDevice.idl():  		controlledObject = object;
	controlledObject = object;
}

TangibleObject* ControlDeviceImplementation::getControlledObject() {
	// server/zone/objects/intangible/ControlDevice.idl():  		return controlledObject;
	return controlledObject;
}

bool ControlDeviceImplementation::isControlDevice() {
	// server/zone/objects/intangible/ControlDevice.idl():  		return true;
	return true;
}

/*
 *	ControlDeviceAdapter
 */

ControlDeviceAdapter::ControlDeviceAdapter(ControlDeviceImplementation* obj) : IntangibleObjectAdapter(obj) {
}

Packet* ControlDeviceAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_UPDATETODATABASEALLOBJECTS__BOOL_:
		updateToDatabaseAllObjects(inv->getBooleanParameter());
		break;
	case RPC_STOREOBJECT__PLAYERCREATURE_:
		storeObject((PlayerCreature*) inv->getObjectParameter());
		break;
	case RPC_GENERATEOBJECT__PLAYERCREATURE_:
		generateObject((PlayerCreature*) inv->getObjectParameter());
		break;
	case RPC_SETCONTROLLEDOBJECT__TANGIBLEOBJECT_:
		setControlledObject((TangibleObject*) inv->getObjectParameter());
		break;
	case RPC_GETCONTROLLEDOBJECT__:
		resp->insertLong(getControlledObject()->_getObjectID());
		break;
	case RPC_ISCONTROLDEVICE__:
		resp->insertBoolean(isControlDevice());
		break;
	default:
		return NULL;
	}

	return resp;
}

void ControlDeviceAdapter::updateToDatabaseAllObjects(bool startTask) {
	((ControlDeviceImplementation*) impl)->updateToDatabaseAllObjects(startTask);
}

void ControlDeviceAdapter::storeObject(PlayerCreature* player) {
	((ControlDeviceImplementation*) impl)->storeObject(player);
}

void ControlDeviceAdapter::generateObject(PlayerCreature* player) {
	((ControlDeviceImplementation*) impl)->generateObject(player);
}

void ControlDeviceAdapter::setControlledObject(TangibleObject* object) {
	((ControlDeviceImplementation*) impl)->setControlledObject(object);
}

TangibleObject* ControlDeviceAdapter::getControlledObject() {
	return ((ControlDeviceImplementation*) impl)->getControlledObject();
}

bool ControlDeviceAdapter::isControlDevice() {
	return ((ControlDeviceImplementation*) impl)->isControlDevice();
}

/*
 *	ControlDeviceHelper
 */

ControlDeviceHelper* ControlDeviceHelper::staticInitializer = ControlDeviceHelper::instance();

ControlDeviceHelper::ControlDeviceHelper() {
	className = "ControlDevice";

	Core::getObjectBroker()->registerClass(className, this);
}

void ControlDeviceHelper::finalizeHelper() {
	ControlDeviceHelper::finalize();
}

DistributedObject* ControlDeviceHelper::instantiateObject() {
	return new ControlDevice(DummyConstructorParameter::instance());
}

DistributedObjectServant* ControlDeviceHelper::instantiateServant() {
	return new ControlDeviceImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ControlDeviceHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ControlDeviceAdapter((ControlDeviceImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}
