/*
 *	server/zone/managers/structure/StructureManager.cpp generated by engine3 IDL compiler 0.60
 */

#include "StructureManager.h"

#include "server/zone/Zone.h"

#include "server/zone/ZoneProcessServer.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/structure/StructureObject.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

/*
 *	StructureManagerStub
 */

StructureManager::StructureManager(Zone* zone, ZoneProcessServer* processor) : ManagedService(DummyConstructorParameter::instance()) {
	StructureManagerImplementation* _implementation = new StructureManagerImplementation(zone, processor);
	_impl = _implementation;
	_impl->_setStub(this);
}

StructureManager::StructureManager(DummyConstructorParameter* param) : ManagedService(param) {
}

StructureManager::~StructureManager() {
}


void StructureManager::loadStructures() {
	StructureManagerImplementation* _implementation = (StructureManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		_implementation->loadStructures();
}

int StructureManager::placeStructureFromDeed(PlayerCreature* player, unsigned long long deedID, float x, float y, int angle) {
	StructureManagerImplementation* _implementation = (StructureManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);
		method.addUnsignedLongParameter(deedID);
		method.addFloatParameter(x);
		method.addFloatParameter(y);
		method.addSignedIntParameter(angle);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->placeStructureFromDeed(player, deedID, x, y, angle);
}

int StructureManager::placeStructure(PlayerCreature* player, StructureObject* structureObject, SharedStructureObjectTemplate* structureTemplate, unsigned long long deedID, float x, float y, const Quaternion& direction) {
	StructureManagerImplementation* _implementation = (StructureManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->placeStructure(player, structureObject, structureTemplate, deedID, x, y, direction);
}

int StructureManager::constructStructure(PlayerCreature* player, StructureObject* structureObject, SharedStructureObjectTemplate* structureTemplate, unsigned long long deedID, float x, float y, const Quaternion& direction) {
	StructureManagerImplementation* _implementation = (StructureManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->constructStructure(player, structureObject, structureTemplate, deedID, x, y, direction);
}

int StructureManager::destroyStructure(PlayerCreature* player, StructureObject* structureObject) {
	StructureManagerImplementation* _implementation = (StructureManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);
		method.addObjectParameter(structureObject);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->destroyStructure(player, structureObject);
}

int StructureManager::redeedStructure(PlayerCreature* player, StructureObject* structureObject, bool destroy) {
	StructureManagerImplementation* _implementation = (StructureManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(player);
		method.addObjectParameter(structureObject);
		method.addBooleanParameter(destroy);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->redeedStructure(player, structureObject, destroy);
}

int StructureManager::declareResidence(PlayerCreature* player, StructureObject* structureObject) {
	StructureManagerImplementation* _implementation = (StructureManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addObjectParameter(player);
		method.addObjectParameter(structureObject);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->declareResidence(player, structureObject);
}

int StructureManager::changePrivacy(PlayerCreature* player, StructureObject* structureObject) {
	StructureManagerImplementation* _implementation = (StructureManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addObjectParameter(player);
		method.addObjectParameter(structureObject);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->changePrivacy(player, structureObject);
}

String StructureManager::getTimeString(unsigned int timestamp) {
	StructureManagerImplementation* _implementation = (StructureManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addUnsignedIntParameter(timestamp);

		method.executeWithAsciiReturn(_return_getTimeString);
		return _return_getTimeString;
	} else
		return _implementation->getTimeString(timestamp);
}

SceneObject* StructureManager::getInRangeParkingGarage(SceneObject* obj, int range) {
	StructureManagerImplementation* _implementation = (StructureManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addObjectParameter(obj);
		method.addSignedIntParameter(range);

		return (SceneObject*) method.executeWithObjectReturn();
	} else
		return _implementation->getInRangeParkingGarage(obj, range);
}

DistributedObjectServant* StructureManager::_getImplementation() {

	_updated = true;
	return _impl;
}

void StructureManager::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	StructureManagerImplementation
 */

StructureManagerImplementation::StructureManagerImplementation(DummyConstructorParameter* param) : ManagedServiceImplementation(param) {
	_initializeImplementation();
}


StructureManagerImplementation::~StructureManagerImplementation() {
}


void StructureManagerImplementation::finalize() {
}

void StructureManagerImplementation::_initializeImplementation() {
	_setClassHelper(StructureManagerHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void StructureManagerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (StructureManager*) stub;
	ManagedServiceImplementation::_setStub(stub);
}

DistributedObjectStub* StructureManagerImplementation::_getStub() {
	return _this;
}

StructureManagerImplementation::operator const StructureManager*() {
	return _this;
}

void StructureManagerImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void StructureManagerImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void StructureManagerImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void StructureManagerImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void StructureManagerImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void StructureManagerImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void StructureManagerImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void StructureManagerImplementation::_serializationHelperMethod() {
	ManagedServiceImplementation::_serializationHelperMethod();

	_setClassName("StructureManager");

}

void StructureManagerImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(StructureManagerImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool StructureManagerImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ManagedServiceImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "zone") {
		TypeInfo<ManagedWeakReference<Zone* > >::parseFromBinaryStream(&zone, stream);
		return true;
	}


	return false;
}

void StructureManagerImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = StructureManagerImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int StructureManagerImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "zone";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedWeakReference<Zone* > >::toBinaryStream(&zone, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + ManagedServiceImplementation::writeObjectMembers(stream);
}

void StructureManagerImplementation::loadStructures() {
	// server/zone/managers/structure/StructureManager.idl(101):  		Logger.info("loading structures...", true);
	Logger::info("loading structures...", true);
	// server/zone/managers/structure/StructureManager.idl(103):  		listOfStaticBuildings.setNoDuplicateInsertPlan();
	(&listOfStaticBuildings)->setNoDuplicateInsertPlan();
	// server/zone/managers/structure/StructureManager.idl(105):  		loadStaticBuildings();
	loadStaticBuildings();
	// server/zone/managers/structure/StructureManager.idl(106):  		loadPlayerStructures();
	loadPlayerStructures();
	// server/zone/managers/structure/StructureManager.idl(107):  		loadStaticBanks();
	loadStaticBanks();
	// server/zone/managers/structure/StructureManager.idl(108):  		loadStaticBazaars();
	loadStaticBazaars();
	// server/zone/managers/structure/StructureManager.idl(109):  		loadStaticMissionTerminals();
	loadStaticMissionTerminals();
	// server/zone/managers/structure/StructureManager.idl(110):  		loadStaticGamblingTerminals();
	loadStaticGamblingTerminals();
	// server/zone/managers/structure/StructureManager.idl(111):  		loadStaticCraftingStations();
	loadStaticCraftingStations();
	// server/zone/managers/structure/StructureManager.idl(112):  		loadStaticElevatorTerminals();
	loadStaticElevatorTerminals();
	// server/zone/managers/structure/StructureManager.idl(113):  		loadStaticGarages();
	loadStaticGarages();
	// server/zone/managers/structure/StructureManager.idl(114):  		loadStaticClientObjects();
	loadStaticClientObjects();
}

/*
 *	StructureManagerAdapter
 */

StructureManagerAdapter::StructureManagerAdapter(StructureManagerImplementation* obj) : ManagedServiceAdapter(obj) {
}

Packet* StructureManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		loadStructures();
		break;
	case 7:
		resp->insertSignedInt(placeStructureFromDeed((PlayerCreature*) inv->getObjectParameter(), inv->getUnsignedLongParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getSignedIntParameter()));
		break;
	case 8:
		resp->insertSignedInt(destroyStructure((PlayerCreature*) inv->getObjectParameter(), (StructureObject*) inv->getObjectParameter()));
		break;
	case 9:
		resp->insertSignedInt(redeedStructure((PlayerCreature*) inv->getObjectParameter(), (StructureObject*) inv->getObjectParameter(), inv->getBooleanParameter()));
		break;
	case 10:
		resp->insertSignedInt(declareResidence((PlayerCreature*) inv->getObjectParameter(), (StructureObject*) inv->getObjectParameter()));
		break;
	case 11:
		resp->insertSignedInt(changePrivacy((PlayerCreature*) inv->getObjectParameter(), (StructureObject*) inv->getObjectParameter()));
		break;
	case 12:
		resp->insertAscii(getTimeString(inv->getUnsignedIntParameter()));
		break;
	case 13:
		resp->insertLong(getInRangeParkingGarage((SceneObject*) inv->getObjectParameter(), inv->getSignedIntParameter())->_getObjectID());
		break;
	default:
		return NULL;
	}

	return resp;
}

void StructureManagerAdapter::loadStructures() {
	((StructureManagerImplementation*) impl)->loadStructures();
}

int StructureManagerAdapter::placeStructureFromDeed(PlayerCreature* player, unsigned long long deedID, float x, float y, int angle) {
	return ((StructureManagerImplementation*) impl)->placeStructureFromDeed(player, deedID, x, y, angle);
}

int StructureManagerAdapter::destroyStructure(PlayerCreature* player, StructureObject* structureObject) {
	return ((StructureManagerImplementation*) impl)->destroyStructure(player, structureObject);
}

int StructureManagerAdapter::redeedStructure(PlayerCreature* player, StructureObject* structureObject, bool destroy) {
	return ((StructureManagerImplementation*) impl)->redeedStructure(player, structureObject, destroy);
}

int StructureManagerAdapter::declareResidence(PlayerCreature* player, StructureObject* structureObject) {
	return ((StructureManagerImplementation*) impl)->declareResidence(player, structureObject);
}

int StructureManagerAdapter::changePrivacy(PlayerCreature* player, StructureObject* structureObject) {
	return ((StructureManagerImplementation*) impl)->changePrivacy(player, structureObject);
}

String StructureManagerAdapter::getTimeString(unsigned int timestamp) {
	return ((StructureManagerImplementation*) impl)->getTimeString(timestamp);
}

SceneObject* StructureManagerAdapter::getInRangeParkingGarage(SceneObject* obj, int range) {
	return ((StructureManagerImplementation*) impl)->getInRangeParkingGarage(obj, range);
}

/*
 *	StructureManagerHelper
 */

StructureManagerHelper* StructureManagerHelper::staticInitializer = StructureManagerHelper::instance();

StructureManagerHelper::StructureManagerHelper() {
	className = "StructureManager";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void StructureManagerHelper::finalizeHelper() {
	StructureManagerHelper::finalize();
}

DistributedObject* StructureManagerHelper::instantiateObject() {
	return new StructureManager(DummyConstructorParameter::instance());
}

DistributedObjectServant* StructureManagerHelper::instantiateServant() {
	return new StructureManagerImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* StructureManagerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new StructureManagerAdapter((StructureManagerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

