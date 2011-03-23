/*
 *	server/zone/objects/tangible/ticket/TicketObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "TicketObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

/*
 *	TicketObjectStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 6,RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_,RPC_SETDEPARTUREPLANET__STRING_,RPC_SETDEPARTUREPOINT__STRING_,RPC_SETARRIVALPLANET__STRING_,RPC_SETARRIVALPOINT__STRING_,RPC_GETDEPARTUREPLANET__,RPC_GETDEPARTUREPOINT__,RPC_GETARRIVALPLANET__,RPC_GETARRIVALPOINT__,RPC_ISTICKETOBJECT__};

TicketObject::TicketObject() : TangibleObject(DummyConstructorParameter::instance()) {
	TicketObjectImplementation* _implementation = new TicketObjectImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

TicketObject::TicketObject(DummyConstructorParameter* param) : TangibleObject(param) {
}

TicketObject::~TicketObject() {
}


void TicketObject::initializeTransientMembers() {
	TicketObjectImplementation* _implementation = (TicketObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

void TicketObject::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	TicketObjectImplementation* _implementation = (TicketObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillAttributeList(msg, object);
}

int TicketObject::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	TicketObjectImplementation* _implementation = (TicketObjectImplementation*) _getImplementation();
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

void TicketObject::setDeparturePlanet(const String& departureplanet) {
	TicketObjectImplementation* _implementation = (TicketObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETDEPARTUREPLANET__STRING_);
		method.addAsciiParameter(departureplanet);

		method.executeWithVoidReturn();
	} else
		_implementation->setDeparturePlanet(departureplanet);
}

void TicketObject::setDeparturePoint(const String& departurepoint) {
	TicketObjectImplementation* _implementation = (TicketObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETDEPARTUREPOINT__STRING_);
		method.addAsciiParameter(departurepoint);

		method.executeWithVoidReturn();
	} else
		_implementation->setDeparturePoint(departurepoint);
}

void TicketObject::setArrivalPlanet(const String& arrival) {
	TicketObjectImplementation* _implementation = (TicketObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETARRIVALPLANET__STRING_);
		method.addAsciiParameter(arrival);

		method.executeWithVoidReturn();
	} else
		_implementation->setArrivalPlanet(arrival);
}

void TicketObject::setArrivalPoint(const String& arrival) {
	TicketObjectImplementation* _implementation = (TicketObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETARRIVALPOINT__STRING_);
		method.addAsciiParameter(arrival);

		method.executeWithVoidReturn();
	} else
		_implementation->setArrivalPoint(arrival);
}

String TicketObject::getDeparturePlanet() {
	TicketObjectImplementation* _implementation = (TicketObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETDEPARTUREPLANET__);

		method.executeWithAsciiReturn(_return_getDeparturePlanet);
		return _return_getDeparturePlanet;
	} else
		return _implementation->getDeparturePlanet();
}

String TicketObject::getDeparturePoint() {
	TicketObjectImplementation* _implementation = (TicketObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETDEPARTUREPOINT__);

		method.executeWithAsciiReturn(_return_getDeparturePoint);
		return _return_getDeparturePoint;
	} else
		return _implementation->getDeparturePoint();
}

String TicketObject::getArrivalPlanet() {
	TicketObjectImplementation* _implementation = (TicketObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETARRIVALPLANET__);

		method.executeWithAsciiReturn(_return_getArrivalPlanet);
		return _return_getArrivalPlanet;
	} else
		return _implementation->getArrivalPlanet();
}

String TicketObject::getArrivalPoint() {
	TicketObjectImplementation* _implementation = (TicketObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETARRIVALPOINT__);

		method.executeWithAsciiReturn(_return_getArrivalPoint);
		return _return_getArrivalPoint;
	} else
		return _implementation->getArrivalPoint();
}

bool TicketObject::isTicketObject() {
	TicketObjectImplementation* _implementation = (TicketObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISTICKETOBJECT__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isTicketObject();
}

DistributedObjectServant* TicketObject::_getImplementation() {

	_updated = true;
	return _impl;
}

void TicketObject::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	TicketObjectImplementation
 */

TicketObjectImplementation::TicketObjectImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}


TicketObjectImplementation::~TicketObjectImplementation() {
}


void TicketObjectImplementation::finalize() {
}

void TicketObjectImplementation::_initializeImplementation() {
	_setClassHelper(TicketObjectHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void TicketObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (TicketObject*) stub;
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* TicketObjectImplementation::_getStub() {
	return _this;
}

TicketObjectImplementation::operator const TicketObject*() {
	return _this;
}

void TicketObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void TicketObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void TicketObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void TicketObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void TicketObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void TicketObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void TicketObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void TicketObjectImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("TicketObject");

}

void TicketObjectImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(TicketObjectImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool TicketObjectImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (TangibleObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "departurePlanet") {
		TypeInfo<String >::parseFromBinaryStream(&departurePlanet, stream);
		return true;
	}

	if (_name == "departurePoint") {
		TypeInfo<String >::parseFromBinaryStream(&departurePoint, stream);
		return true;
	}

	if (_name == "arrivalPlanet") {
		TypeInfo<String >::parseFromBinaryStream(&arrivalPlanet, stream);
		return true;
	}

	if (_name == "arrivalPoint") {
		TypeInfo<String >::parseFromBinaryStream(&arrivalPoint, stream);
		return true;
	}


	return false;
}

void TicketObjectImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = TicketObjectImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int TicketObjectImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "departurePlanet";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<String >::toBinaryStream(&departurePlanet, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "departurePoint";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<String >::toBinaryStream(&departurePoint, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "arrivalPlanet";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<String >::toBinaryStream(&arrivalPlanet, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "arrivalPoint";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<String >::toBinaryStream(&arrivalPoint, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 4 + TangibleObjectImplementation::writeObjectMembers(stream);
}

TicketObjectImplementation::TicketObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/ticket/TicketObject.idl():  		Logger.setLoggingName("TicketObject");
	Logger::setLoggingName("TicketObject");
}

void TicketObjectImplementation::initializeTransientMembers() {
	// server/zone/objects/tangible/ticket/TicketObject.idl():  		super.initializeTransientMembers();
	TangibleObjectImplementation::initializeTransientMembers();
	// server/zone/objects/tangible/ticket/TicketObject.idl():  		Logger.setLoggingName("TicketObject");
	Logger::setLoggingName("TicketObject");
}

void TicketObjectImplementation::setDeparturePlanet(const String& departureplanet) {
	// server/zone/objects/tangible/ticket/TicketObject.idl():  		departurePlanet = departureplanet;
	departurePlanet = departureplanet;
}

void TicketObjectImplementation::setDeparturePoint(const String& departurepoint) {
	// server/zone/objects/tangible/ticket/TicketObject.idl():  		departurePoint = departurepoint;
	departurePoint = departurepoint;
}

void TicketObjectImplementation::setArrivalPlanet(const String& arrival) {
	// server/zone/objects/tangible/ticket/TicketObject.idl():  		arrivalPlanet = arrival;
	arrivalPlanet = arrival;
}

void TicketObjectImplementation::setArrivalPoint(const String& arrival) {
	// server/zone/objects/tangible/ticket/TicketObject.idl():  		arrivalPoint = arrival;
	arrivalPoint = arrival;
}

String TicketObjectImplementation::getDeparturePlanet() {
	// server/zone/objects/tangible/ticket/TicketObject.idl():  		return departurePlanet;
	return departurePlanet;
}

String TicketObjectImplementation::getDeparturePoint() {
	// server/zone/objects/tangible/ticket/TicketObject.idl():  		return departurePoint;
	return departurePoint;
}

String TicketObjectImplementation::getArrivalPlanet() {
	// server/zone/objects/tangible/ticket/TicketObject.idl():  		return arrivalPlanet;
	return arrivalPlanet;
}

String TicketObjectImplementation::getArrivalPoint() {
	// server/zone/objects/tangible/ticket/TicketObject.idl():  		return arrivalPoint;
	return arrivalPoint;
}

bool TicketObjectImplementation::isTicketObject() {
	// server/zone/objects/tangible/ticket/TicketObject.idl():  		return true;
	return true;
}

/*
 *	TicketObjectAdapter
 */

TicketObjectAdapter::TicketObjectAdapter(TicketObjectImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* TicketObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		initializeTransientMembers();
		break;
	case RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	case RPC_SETDEPARTUREPLANET__STRING_:
		setDeparturePlanet(inv->getAsciiParameter(_param0_setDeparturePlanet__String_));
		break;
	case RPC_SETDEPARTUREPOINT__STRING_:
		setDeparturePoint(inv->getAsciiParameter(_param0_setDeparturePoint__String_));
		break;
	case RPC_SETARRIVALPLANET__STRING_:
		setArrivalPlanet(inv->getAsciiParameter(_param0_setArrivalPlanet__String_));
		break;
	case RPC_SETARRIVALPOINT__STRING_:
		setArrivalPoint(inv->getAsciiParameter(_param0_setArrivalPoint__String_));
		break;
	case RPC_GETDEPARTUREPLANET__:
		resp->insertAscii(getDeparturePlanet());
		break;
	case RPC_GETDEPARTUREPOINT__:
		resp->insertAscii(getDeparturePoint());
		break;
	case RPC_GETARRIVALPLANET__:
		resp->insertAscii(getArrivalPlanet());
		break;
	case RPC_GETARRIVALPOINT__:
		resp->insertAscii(getArrivalPoint());
		break;
	case RPC_ISTICKETOBJECT__:
		resp->insertBoolean(isTicketObject());
		break;
	default:
		return NULL;
	}

	return resp;
}

void TicketObjectAdapter::initializeTransientMembers() {
	((TicketObjectImplementation*) impl)->initializeTransientMembers();
}

int TicketObjectAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((TicketObjectImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

void TicketObjectAdapter::setDeparturePlanet(const String& departureplanet) {
	((TicketObjectImplementation*) impl)->setDeparturePlanet(departureplanet);
}

void TicketObjectAdapter::setDeparturePoint(const String& departurepoint) {
	((TicketObjectImplementation*) impl)->setDeparturePoint(departurepoint);
}

void TicketObjectAdapter::setArrivalPlanet(const String& arrival) {
	((TicketObjectImplementation*) impl)->setArrivalPlanet(arrival);
}

void TicketObjectAdapter::setArrivalPoint(const String& arrival) {
	((TicketObjectImplementation*) impl)->setArrivalPoint(arrival);
}

String TicketObjectAdapter::getDeparturePlanet() {
	return ((TicketObjectImplementation*) impl)->getDeparturePlanet();
}

String TicketObjectAdapter::getDeparturePoint() {
	return ((TicketObjectImplementation*) impl)->getDeparturePoint();
}

String TicketObjectAdapter::getArrivalPlanet() {
	return ((TicketObjectImplementation*) impl)->getArrivalPlanet();
}

String TicketObjectAdapter::getArrivalPoint() {
	return ((TicketObjectImplementation*) impl)->getArrivalPoint();
}

bool TicketObjectAdapter::isTicketObject() {
	return ((TicketObjectImplementation*) impl)->isTicketObject();
}

/*
 *	TicketObjectHelper
 */

TicketObjectHelper* TicketObjectHelper::staticInitializer = TicketObjectHelper::instance();

TicketObjectHelper::TicketObjectHelper() {
	className = "TicketObject";

	Core::getObjectBroker()->registerClass(className, this);
}

void TicketObjectHelper::finalizeHelper() {
	TicketObjectHelper::finalize();
}

DistributedObject* TicketObjectHelper::instantiateObject() {
	return new TicketObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* TicketObjectHelper::instantiateServant() {
	return new TicketObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* TicketObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new TicketObjectAdapter((TicketObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}
