/*
 *	server/zone/objects/tangible/components/TangibleObjectMenuComponent.cpp generated by engine3 IDL compiler 0.60
 */

#include "TangibleObjectMenuComponent.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/player/PlayerCreature.h"

/*
 *	TangibleObjectMenuComponentStub
 */

enum {RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_};

TangibleObjectMenuComponent::TangibleObjectMenuComponent() : ObjectMenuComponent(DummyConstructorParameter::instance()) {
	TangibleObjectMenuComponentImplementation* _implementation = new TangibleObjectMenuComponentImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

TangibleObjectMenuComponent::TangibleObjectMenuComponent(DummyConstructorParameter* param) : ObjectMenuComponent(param) {
}

TangibleObjectMenuComponent::~TangibleObjectMenuComponent() {
}


void TangibleObjectMenuComponent::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player) {
	TangibleObjectMenuComponentImplementation* _implementation = (TangibleObjectMenuComponentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillObjectMenuResponse(menuResponse, player);
}

int TangibleObjectMenuComponent::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	TangibleObjectMenuComponentImplementation* _implementation = (TangibleObjectMenuComponentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->handleObjectMenuSelect(player, selectedID);
}

DistributedObjectServant* TangibleObjectMenuComponent::_getImplementation() {

	_updated = true;
	return _impl;
}

void TangibleObjectMenuComponent::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	TangibleObjectMenuComponentImplementation
 */

TangibleObjectMenuComponentImplementation::TangibleObjectMenuComponentImplementation(DummyConstructorParameter* param) : ObjectMenuComponentImplementation(param) {
	_initializeImplementation();
}


TangibleObjectMenuComponentImplementation::~TangibleObjectMenuComponentImplementation() {
}


void TangibleObjectMenuComponentImplementation::finalize() {
}

void TangibleObjectMenuComponentImplementation::_initializeImplementation() {
	_setClassHelper(TangibleObjectMenuComponentHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void TangibleObjectMenuComponentImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (TangibleObjectMenuComponent*) stub;
	ObjectMenuComponentImplementation::_setStub(stub);
}

DistributedObjectStub* TangibleObjectMenuComponentImplementation::_getStub() {
	return _this;
}

TangibleObjectMenuComponentImplementation::operator const TangibleObjectMenuComponent*() {
	return _this;
}

void TangibleObjectMenuComponentImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void TangibleObjectMenuComponentImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void TangibleObjectMenuComponentImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void TangibleObjectMenuComponentImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void TangibleObjectMenuComponentImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void TangibleObjectMenuComponentImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void TangibleObjectMenuComponentImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void TangibleObjectMenuComponentImplementation::_serializationHelperMethod() {
	ObjectMenuComponentImplementation::_serializationHelperMethod();

	_setClassName("TangibleObjectMenuComponent");

}

void TangibleObjectMenuComponentImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(TangibleObjectMenuComponentImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool TangibleObjectMenuComponentImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ObjectMenuComponentImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void TangibleObjectMenuComponentImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = TangibleObjectMenuComponentImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int TangibleObjectMenuComponentImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + ObjectMenuComponentImplementation::writeObjectMembers(stream);
}

TangibleObjectMenuComponentImplementation::TangibleObjectMenuComponentImplementation() : ObjectMenuComponentImplementation() {
	_initializeImplementation();
}

/*
 *	TangibleObjectMenuComponentAdapter
 */

TangibleObjectMenuComponentAdapter::TangibleObjectMenuComponentAdapter(TangibleObjectMenuComponentImplementation* obj) : ObjectMenuComponentAdapter(obj) {
}

Packet* TangibleObjectMenuComponentAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

int TangibleObjectMenuComponentAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((TangibleObjectMenuComponentImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

/*
 *	TangibleObjectMenuComponentHelper
 */

TangibleObjectMenuComponentHelper* TangibleObjectMenuComponentHelper::staticInitializer = TangibleObjectMenuComponentHelper::instance();

TangibleObjectMenuComponentHelper::TangibleObjectMenuComponentHelper() {
	className = "TangibleObjectMenuComponent";

	Core::getObjectBroker()->registerClass(className, this);
}

void TangibleObjectMenuComponentHelper::finalizeHelper() {
	TangibleObjectMenuComponentHelper::finalize();
}

DistributedObject* TangibleObjectMenuComponentHelper::instantiateObject() {
	return new TangibleObjectMenuComponent(DummyConstructorParameter::instance());
}

DistributedObjectServant* TangibleObjectMenuComponentHelper::instantiateServant() {
	return new TangibleObjectMenuComponentImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* TangibleObjectMenuComponentHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new TangibleObjectMenuComponentAdapter((TangibleObjectMenuComponentImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}
