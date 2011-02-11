/*
 *	server/zone/objects/tangible/terminal/elevator/ElevatorTerminal.cpp generated by engine3 IDL compiler 0.60
 */

#include "ElevatorTerminal.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/Zone.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

/*
 *	ElevatorTerminalStub
 */

ElevatorTerminal::ElevatorTerminal() : Terminal(DummyConstructorParameter::instance()) {
	ElevatorTerminalImplementation* _implementation = new ElevatorTerminalImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

ElevatorTerminal::ElevatorTerminal(DummyConstructorParameter* param) : Terminal(param) {
}

ElevatorTerminal::~ElevatorTerminal() {
}


void ElevatorTerminal::notifyInsert(QuadTreeEntry* obj) {
	ElevatorTerminalImplementation* _implementation = (ElevatorTerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->notifyInsert(obj);
}

void ElevatorTerminal::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player) {
	ElevatorTerminalImplementation* _implementation = (ElevatorTerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(menuResponse);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->fillObjectMenuResponse(menuResponse, player);
}

int ElevatorTerminal::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	ElevatorTerminalImplementation* _implementation = (ElevatorTerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->handleObjectMenuSelect(player, selectedID);
}

bool ElevatorTerminal::isElevatorTerminal() {
	ElevatorTerminalImplementation* _implementation = (ElevatorTerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isElevatorTerminal();
}

DistributedObjectServant* ElevatorTerminal::_getImplementation() {

	_updated = true;
	return _impl;
}

void ElevatorTerminal::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	ElevatorTerminalImplementation
 */

ElevatorTerminalImplementation::ElevatorTerminalImplementation(DummyConstructorParameter* param) : TerminalImplementation(param) {
	_initializeImplementation();
}


ElevatorTerminalImplementation::~ElevatorTerminalImplementation() {
}


void ElevatorTerminalImplementation::finalize() {
}

void ElevatorTerminalImplementation::_initializeImplementation() {
	_setClassHelper(ElevatorTerminalHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void ElevatorTerminalImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (ElevatorTerminal*) stub;
	TerminalImplementation::_setStub(stub);
}

DistributedObjectStub* ElevatorTerminalImplementation::_getStub() {
	return _this;
}

ElevatorTerminalImplementation::operator const ElevatorTerminal*() {
	return _this;
}

void ElevatorTerminalImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void ElevatorTerminalImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void ElevatorTerminalImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void ElevatorTerminalImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void ElevatorTerminalImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void ElevatorTerminalImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void ElevatorTerminalImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void ElevatorTerminalImplementation::_serializationHelperMethod() {
	TerminalImplementation::_serializationHelperMethod();

	_setClassName("ElevatorTerminal");

}

void ElevatorTerminalImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(ElevatorTerminalImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool ElevatorTerminalImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (TerminalImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "elevatorUp") {
		TypeInfo<ManagedReference<ElevatorTerminal* > >::parseFromBinaryStream(&elevatorUp, stream);
		return true;
	}

	if (_name == "elevatorDown") {
		TypeInfo<ManagedReference<ElevatorTerminal* > >::parseFromBinaryStream(&elevatorDown, stream);
		return true;
	}


	return false;
}

void ElevatorTerminalImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = ElevatorTerminalImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int ElevatorTerminalImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "elevatorUp";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedReference<ElevatorTerminal* > >::toBinaryStream(&elevatorUp, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "elevatorDown";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedReference<ElevatorTerminal* > >::toBinaryStream(&elevatorDown, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 2 + TerminalImplementation::writeObjectMembers(stream);
}

ElevatorTerminalImplementation::ElevatorTerminalImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/terminal/elevator/ElevatorTerminal.idl(61):  		Logger.setLoggingName("ElevatorTerminal");
	Logger::setLoggingName("ElevatorTerminal");
	// server/zone/objects/tangible/terminal/elevator/ElevatorTerminal.idl(63):  		elevatorUp = null;
	elevatorUp = NULL;
	// server/zone/objects/tangible/terminal/elevator/ElevatorTerminal.idl(64):  		elevatorDown = null;
	elevatorDown = NULL;
}

bool ElevatorTerminalImplementation::isElevatorTerminal() {
	// server/zone/objects/tangible/terminal/elevator/ElevatorTerminal.idl(82):  		return true;
	return true;
}

/*
 *	ElevatorTerminalAdapter
 */

ElevatorTerminalAdapter::ElevatorTerminalAdapter(ElevatorTerminalImplementation* obj) : TerminalAdapter(obj) {
}

Packet* ElevatorTerminalAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		fillObjectMenuResponse((ObjectMenuResponse*) inv->getObjectParameter(), (PlayerCreature*) inv->getObjectParameter());
		break;
	case 7:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	case 8:
		resp->insertBoolean(isElevatorTerminal());
		break;
	default:
		return NULL;
	}

	return resp;
}

void ElevatorTerminalAdapter::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player) {
	((ElevatorTerminalImplementation*) impl)->fillObjectMenuResponse(menuResponse, player);
}

int ElevatorTerminalAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((ElevatorTerminalImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

bool ElevatorTerminalAdapter::isElevatorTerminal() {
	return ((ElevatorTerminalImplementation*) impl)->isElevatorTerminal();
}

/*
 *	ElevatorTerminalHelper
 */

ElevatorTerminalHelper* ElevatorTerminalHelper::staticInitializer = ElevatorTerminalHelper::instance();

ElevatorTerminalHelper::ElevatorTerminalHelper() {
	className = "ElevatorTerminal";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ElevatorTerminalHelper::finalizeHelper() {
	ElevatorTerminalHelper::finalize();
}

DistributedObject* ElevatorTerminalHelper::instantiateObject() {
	return new ElevatorTerminal(DummyConstructorParameter::instance());
}

DistributedObjectServant* ElevatorTerminalHelper::instantiateServant() {
	return new ElevatorTerminalImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ElevatorTerminalHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ElevatorTerminalAdapter((ElevatorTerminalImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}
