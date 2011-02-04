/*
 *	server/zone/objects/tangible/pharmaceutical/PharmaceuticalObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "PharmaceuticalObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/ZoneServer.h"

/*
 *	PharmaceuticalObjectStub
 */

PharmaceuticalObject::PharmaceuticalObject() : TangibleObject(DummyConstructorParameter::instance()) {
	PharmaceuticalObjectImplementation* _implementation = new PharmaceuticalObjectImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

PharmaceuticalObject::PharmaceuticalObject(DummyConstructorParameter* param) : TangibleObject(param) {
}

PharmaceuticalObject::~PharmaceuticalObject() {
}


int PharmaceuticalObject::getMedicineUseRequired() {
	PharmaceuticalObjectImplementation* _implementation = (PharmaceuticalObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getMedicineUseRequired();
}

float PharmaceuticalObject::getRange(CreatureObject* creature) {
	PharmaceuticalObjectImplementation* _implementation = (PharmaceuticalObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(creature);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getRange(creature);
}

bool PharmaceuticalObject::isArea() {
	PharmaceuticalObjectImplementation* _implementation = (PharmaceuticalObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isArea();
}

float PharmaceuticalObject::getArea() {
	PharmaceuticalObjectImplementation* _implementation = (PharmaceuticalObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getArea();
}

bool PharmaceuticalObject::isPharmaceuticalObject() {
	PharmaceuticalObjectImplementation* _implementation = (PharmaceuticalObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isPharmaceuticalObject();
}

bool PharmaceuticalObject::isStimPack() {
	PharmaceuticalObjectImplementation* _implementation = (PharmaceuticalObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isStimPack();
}

bool PharmaceuticalObject::isRangedStimPack() {
	PharmaceuticalObjectImplementation* _implementation = (PharmaceuticalObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isRangedStimPack();
}

bool PharmaceuticalObject::isEnhancePack() {
	PharmaceuticalObjectImplementation* _implementation = (PharmaceuticalObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isEnhancePack();
}

bool PharmaceuticalObject::isWoundPack() {
	PharmaceuticalObjectImplementation* _implementation = (PharmaceuticalObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isWoundPack();
}

bool PharmaceuticalObject::isCurePack() {
	PharmaceuticalObjectImplementation* _implementation = (PharmaceuticalObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isCurePack();
}

bool PharmaceuticalObject::isStatePack() {
	PharmaceuticalObjectImplementation* _implementation = (PharmaceuticalObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isStatePack();
}

bool PharmaceuticalObject::isRevivePack() {
	PharmaceuticalObjectImplementation* _implementation = (PharmaceuticalObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isRevivePack();
}

DistributedObjectServant* PharmaceuticalObject::_getImplementation() {

	_updated = true;
	return _impl;
}

void PharmaceuticalObject::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	PharmaceuticalObjectImplementation
 */

PharmaceuticalObjectImplementation::PharmaceuticalObjectImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}


PharmaceuticalObjectImplementation::~PharmaceuticalObjectImplementation() {
}


void PharmaceuticalObjectImplementation::finalize() {
}

void PharmaceuticalObjectImplementation::_initializeImplementation() {
	_setClassHelper(PharmaceuticalObjectHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void PharmaceuticalObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (PharmaceuticalObject*) stub;
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* PharmaceuticalObjectImplementation::_getStub() {
	return _this;
}

PharmaceuticalObjectImplementation::operator const PharmaceuticalObject*() {
	return _this;
}

void PharmaceuticalObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void PharmaceuticalObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void PharmaceuticalObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void PharmaceuticalObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void PharmaceuticalObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void PharmaceuticalObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void PharmaceuticalObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void PharmaceuticalObjectImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("PharmaceuticalObject");

}

void PharmaceuticalObjectImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(PharmaceuticalObjectImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool PharmaceuticalObjectImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (TangibleObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "medicineUseRequired") {
		TypeInfo<int >::parseFromBinaryStream(&medicineUseRequired, stream);
		return true;
	}


	return false;
}

void PharmaceuticalObjectImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = PharmaceuticalObjectImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int PharmaceuticalObjectImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "medicineUseRequired";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&medicineUseRequired, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + TangibleObjectImplementation::writeObjectMembers(stream);
}

PharmaceuticalObjectImplementation::PharmaceuticalObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/pharmaceutical/PharmaceuticalObject.idl(61):  		setLoggingName("PharmaceuticalObject");
	setLoggingName("PharmaceuticalObject");
	// server/zone/objects/tangible/pharmaceutical/PharmaceuticalObject.idl(63):  		medicineUseRequired = 0;
	medicineUseRequired = 0;
}

int PharmaceuticalObjectImplementation::getMedicineUseRequired() {
	// server/zone/objects/tangible/pharmaceutical/PharmaceuticalObject.idl(67):  		return medicineUseRequired;
	return medicineUseRequired;
}

float PharmaceuticalObjectImplementation::getRange(CreatureObject* creature) {
	// server/zone/objects/tangible/pharmaceutical/PharmaceuticalObject.idl(71):  		return 5;
	return 5;
}

bool PharmaceuticalObjectImplementation::isArea() {
	// server/zone/objects/tangible/pharmaceutical/PharmaceuticalObject.idl(75):  		return false;
	return false;
}

float PharmaceuticalObjectImplementation::getArea() {
	// server/zone/objects/tangible/pharmaceutical/PharmaceuticalObject.idl(79):  		return 0;
	return 0;
}

bool PharmaceuticalObjectImplementation::isPharmaceuticalObject() {
	// server/zone/objects/tangible/pharmaceutical/PharmaceuticalObject.idl(83):  		return true;
	return true;
}

bool PharmaceuticalObjectImplementation::isStimPack() {
	// server/zone/objects/tangible/pharmaceutical/PharmaceuticalObject.idl(87):  		return false;
	return false;
}

bool PharmaceuticalObjectImplementation::isRangedStimPack() {
	// server/zone/objects/tangible/pharmaceutical/PharmaceuticalObject.idl(91):  		return false;
	return false;
}

bool PharmaceuticalObjectImplementation::isEnhancePack() {
	// server/zone/objects/tangible/pharmaceutical/PharmaceuticalObject.idl(95):  		return false;
	return false;
}

bool PharmaceuticalObjectImplementation::isWoundPack() {
	// server/zone/objects/tangible/pharmaceutical/PharmaceuticalObject.idl(99):  		return false;
	return false;
}

bool PharmaceuticalObjectImplementation::isCurePack() {
	// server/zone/objects/tangible/pharmaceutical/PharmaceuticalObject.idl(103):  		return false;
	return false;
}

bool PharmaceuticalObjectImplementation::isStatePack() {
	// server/zone/objects/tangible/pharmaceutical/PharmaceuticalObject.idl(107):  		return false;
	return false;
}

bool PharmaceuticalObjectImplementation::isRevivePack() {
	// server/zone/objects/tangible/pharmaceutical/PharmaceuticalObject.idl(111):  		return false;
	return false;
}

/*
 *	PharmaceuticalObjectAdapter
 */

PharmaceuticalObjectAdapter::PharmaceuticalObjectAdapter(PharmaceuticalObjectImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* PharmaceuticalObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertSignedInt(getMedicineUseRequired());
		break;
	case 7:
		resp->insertFloat(getRange((CreatureObject*) inv->getObjectParameter()));
		break;
	case 8:
		resp->insertBoolean(isArea());
		break;
	case 9:
		resp->insertFloat(getArea());
		break;
	case 10:
		resp->insertBoolean(isPharmaceuticalObject());
		break;
	case 11:
		resp->insertBoolean(isStimPack());
		break;
	case 12:
		resp->insertBoolean(isRangedStimPack());
		break;
	case 13:
		resp->insertBoolean(isEnhancePack());
		break;
	case 14:
		resp->insertBoolean(isWoundPack());
		break;
	case 15:
		resp->insertBoolean(isCurePack());
		break;
	case 16:
		resp->insertBoolean(isStatePack());
		break;
	case 17:
		resp->insertBoolean(isRevivePack());
		break;
	default:
		return NULL;
	}

	return resp;
}

int PharmaceuticalObjectAdapter::getMedicineUseRequired() {
	return ((PharmaceuticalObjectImplementation*) impl)->getMedicineUseRequired();
}

float PharmaceuticalObjectAdapter::getRange(CreatureObject* creature) {
	return ((PharmaceuticalObjectImplementation*) impl)->getRange(creature);
}

bool PharmaceuticalObjectAdapter::isArea() {
	return ((PharmaceuticalObjectImplementation*) impl)->isArea();
}

float PharmaceuticalObjectAdapter::getArea() {
	return ((PharmaceuticalObjectImplementation*) impl)->getArea();
}

bool PharmaceuticalObjectAdapter::isPharmaceuticalObject() {
	return ((PharmaceuticalObjectImplementation*) impl)->isPharmaceuticalObject();
}

bool PharmaceuticalObjectAdapter::isStimPack() {
	return ((PharmaceuticalObjectImplementation*) impl)->isStimPack();
}

bool PharmaceuticalObjectAdapter::isRangedStimPack() {
	return ((PharmaceuticalObjectImplementation*) impl)->isRangedStimPack();
}

bool PharmaceuticalObjectAdapter::isEnhancePack() {
	return ((PharmaceuticalObjectImplementation*) impl)->isEnhancePack();
}

bool PharmaceuticalObjectAdapter::isWoundPack() {
	return ((PharmaceuticalObjectImplementation*) impl)->isWoundPack();
}

bool PharmaceuticalObjectAdapter::isCurePack() {
	return ((PharmaceuticalObjectImplementation*) impl)->isCurePack();
}

bool PharmaceuticalObjectAdapter::isStatePack() {
	return ((PharmaceuticalObjectImplementation*) impl)->isStatePack();
}

bool PharmaceuticalObjectAdapter::isRevivePack() {
	return ((PharmaceuticalObjectImplementation*) impl)->isRevivePack();
}

/*
 *	PharmaceuticalObjectHelper
 */

PharmaceuticalObjectHelper* PharmaceuticalObjectHelper::staticInitializer = PharmaceuticalObjectHelper::instance();

PharmaceuticalObjectHelper::PharmaceuticalObjectHelper() {
	className = "PharmaceuticalObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void PharmaceuticalObjectHelper::finalizeHelper() {
	PharmaceuticalObjectHelper::finalize();
}

DistributedObject* PharmaceuticalObjectHelper::instantiateObject() {
	return new PharmaceuticalObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* PharmaceuticalObjectHelper::instantiateServant() {
	return new PharmaceuticalObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* PharmaceuticalObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new PharmaceuticalObjectAdapter((PharmaceuticalObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}
