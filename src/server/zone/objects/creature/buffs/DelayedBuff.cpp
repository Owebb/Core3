/*
 *	server/zone/objects/creature/buffs/DelayedBuff.cpp generated by engine3 IDL compiler 0.60
 */

#include "DelayedBuff.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/creature/buffs/BuffDurationEvent.h"

/*
 *	DelayedBuffStub
 */

DelayedBuff::DelayedBuff(CreatureObject* creo, unsigned int buffcrc, int duration) : Buff(DummyConstructorParameter::instance()) {
	DelayedBuffImplementation* _implementation = new DelayedBuffImplementation(creo, buffcrc, duration);
	_impl = _implementation;
	_impl->_setStub(this);
}

DelayedBuff::DelayedBuff(DummyConstructorParameter* param) : Buff(param) {
}

DelayedBuff::~DelayedBuff() {
}


void DelayedBuff::activate() {
	DelayedBuffImplementation* _implementation = (DelayedBuffImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		_implementation->activate();
}

void DelayedBuff::deactivate() {
	DelayedBuffImplementation* _implementation = (DelayedBuffImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithVoidReturn();
	} else
		_implementation->deactivate();
}

void DelayedBuff::useCharge(CreatureObject* creature) {
	DelayedBuffImplementation* _implementation = (DelayedBuffImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(creature);

		method.executeWithVoidReturn();
	} else
		_implementation->useCharge(creature);
}

void DelayedBuff::setUsesRemaining(int uses) {
	DelayedBuffImplementation* _implementation = (DelayedBuffImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addSignedIntParameter(uses);

		method.executeWithVoidReturn();
	} else
		_implementation->setUsesRemaining(uses);
}

DistributedObjectServant* DelayedBuff::_getImplementation() {

	_updated = true;
	return _impl;
}

void DelayedBuff::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	DelayedBuffImplementation
 */

DelayedBuffImplementation::DelayedBuffImplementation(DummyConstructorParameter* param) : BuffImplementation(param) {
	_initializeImplementation();
}


DelayedBuffImplementation::~DelayedBuffImplementation() {
}


void DelayedBuffImplementation::finalize() {
}

void DelayedBuffImplementation::_initializeImplementation() {
	_setClassHelper(DelayedBuffHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void DelayedBuffImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (DelayedBuff*) stub;
	BuffImplementation::_setStub(stub);
}

DistributedObjectStub* DelayedBuffImplementation::_getStub() {
	return _this;
}

DelayedBuffImplementation::operator const DelayedBuff*() {
	return _this;
}

void DelayedBuffImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void DelayedBuffImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void DelayedBuffImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void DelayedBuffImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void DelayedBuffImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void DelayedBuffImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void DelayedBuffImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void DelayedBuffImplementation::_serializationHelperMethod() {
	BuffImplementation::_serializationHelperMethod();

	_setClassName("DelayedBuff");

}

void DelayedBuffImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(DelayedBuffImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool DelayedBuffImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (BuffImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "usesRemaining") {
		TypeInfo<int >::parseFromBinaryStream(&usesRemaining, stream);
		return true;
	}


	return false;
}

void DelayedBuffImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = DelayedBuffImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int DelayedBuffImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "usesRemaining";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&usesRemaining, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + BuffImplementation::writeObjectMembers(stream);
}

DelayedBuffImplementation::DelayedBuffImplementation(CreatureObject* creo, unsigned int buffcrc, int duration) : BuffImplementation(creo, buffcrc, 1380, BuffType::FOOD) {
	_initializeImplementation();
	// server/zone/objects/creature/buffs/DelayedBuff.idl(66):  		usesRemaining = duration;
	usesRemaining = duration;
}

void DelayedBuffImplementation::activate() {
	// server/zone/objects/creature/buffs/DelayedBuff.idl(73):  		super.activate(false);
	BuffImplementation::activate(false);
}

void DelayedBuffImplementation::deactivate() {
	// server/zone/objects/creature/buffs/DelayedBuff.idl(77):  		super.deactivate(false);
	BuffImplementation::deactivate(false);
}

void DelayedBuffImplementation::useCharge(CreatureObject* creature) {
	// server/zone/objects/creature/buffs/DelayedBuff.idl(81):  		usesRemaining = usesRemaining - 1;
	usesRemaining = usesRemaining - 1;
	// server/zone/objects/creature/buffs/DelayedBuff.idl(83):  	}
	if (usesRemaining < 1){
	// server/zone/objects/creature/buffs/DelayedBuff.idl(84):  			creature.removeBuff(this);
	creature->removeBuff(_this);
}
}

void DelayedBuffImplementation::setUsesRemaining(int uses) {
	// server/zone/objects/creature/buffs/DelayedBuff.idl(89):  		usesRemaining = uses;
	usesRemaining = uses;
}

/*
 *	DelayedBuffAdapter
 */

DelayedBuffAdapter::DelayedBuffAdapter(DelayedBuffImplementation* obj) : BuffAdapter(obj) {
}

Packet* DelayedBuffAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		activate();
		break;
	case 7:
		deactivate();
		break;
	case 8:
		useCharge((CreatureObject*) inv->getObjectParameter());
		break;
	case 9:
		setUsesRemaining(inv->getSignedIntParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void DelayedBuffAdapter::activate() {
	((DelayedBuffImplementation*) impl)->activate();
}

void DelayedBuffAdapter::deactivate() {
	((DelayedBuffImplementation*) impl)->deactivate();
}

void DelayedBuffAdapter::useCharge(CreatureObject* creature) {
	((DelayedBuffImplementation*) impl)->useCharge(creature);
}

void DelayedBuffAdapter::setUsesRemaining(int uses) {
	((DelayedBuffImplementation*) impl)->setUsesRemaining(uses);
}

/*
 *	DelayedBuffHelper
 */

DelayedBuffHelper* DelayedBuffHelper::staticInitializer = DelayedBuffHelper::instance();

DelayedBuffHelper::DelayedBuffHelper() {
	className = "DelayedBuff";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void DelayedBuffHelper::finalizeHelper() {
	DelayedBuffHelper::finalize();
}

DistributedObject* DelayedBuffHelper::instantiateObject() {
	return new DelayedBuff(DummyConstructorParameter::instance());
}

DistributedObjectServant* DelayedBuffHelper::instantiateServant() {
	return new DelayedBuffImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* DelayedBuffHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new DelayedBuffAdapter((DelayedBuffImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}
