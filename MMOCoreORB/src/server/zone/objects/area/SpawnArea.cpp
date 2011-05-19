/*
 *	server/zone/objects/area/SpawnArea.cpp generated by engine3 IDL compiler 0.60
 */

#include "SpawnArea.h"

#include "server/zone/objects/creature/aigroup/AiGroup.h"

#include "server/zone/objects/area/SpawnObserver.h"

/*
 *	SpawnAreaStub
 */

enum {RPC_REGISTEROBSERVERS__ = 6,RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_,RPC_ADDTEMPLATE__INT_,RPC_SETTIER__INT_,RPC_SETSPAWNCONSTANT__INT_,RPC_ISSTATICAREA__,RPC_ISDYNAMICAREA__};

SpawnArea::SpawnArea() : ActiveArea(DummyConstructorParameter::instance()) {
	SpawnAreaImplementation* _implementation = new SpawnAreaImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

SpawnArea::SpawnArea(DummyConstructorParameter* param) : ActiveArea(param) {
}

SpawnArea::~SpawnArea() {
}


void SpawnArea::registerObservers() {
	SpawnAreaImplementation* _implementation = (SpawnAreaImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_REGISTEROBSERVERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->registerObservers();
}

int SpawnArea::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	SpawnAreaImplementation* _implementation = (SpawnAreaImplementation*) _getImplementation();
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

void SpawnArea::addTemplate(unsigned int tempCRC) {
	SpawnAreaImplementation* _implementation = (SpawnAreaImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ADDTEMPLATE__INT_);
		method.addUnsignedIntParameter(tempCRC);

		method.executeWithVoidReturn();
	} else
		_implementation->addTemplate(tempCRC);
}

void SpawnArea::setTier(int n) {
	SpawnAreaImplementation* _implementation = (SpawnAreaImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETTIER__INT_);
		method.addSignedIntParameter(n);

		method.executeWithVoidReturn();
	} else
		_implementation->setTier(n);
}

void SpawnArea::setSpawnConstant(int n) {
	SpawnAreaImplementation* _implementation = (SpawnAreaImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETSPAWNCONSTANT__INT_);
		method.addSignedIntParameter(n);

		method.executeWithVoidReturn();
	} else
		_implementation->setSpawnConstant(n);
}

bool SpawnArea::isStaticArea() {
	SpawnAreaImplementation* _implementation = (SpawnAreaImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISSTATICAREA__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isStaticArea();
}

bool SpawnArea::isDynamicArea() {
	SpawnAreaImplementation* _implementation = (SpawnAreaImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISDYNAMICAREA__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isDynamicArea();
}

DistributedObjectServant* SpawnArea::_getImplementation() {

	_updated = true;
	return _impl;
}

void SpawnArea::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	SpawnAreaImplementation
 */

SpawnAreaImplementation::SpawnAreaImplementation(DummyConstructorParameter* param) : ActiveAreaImplementation(param) {
	_initializeImplementation();
}


SpawnAreaImplementation::~SpawnAreaImplementation() {
}


void SpawnAreaImplementation::finalize() {
}

void SpawnAreaImplementation::_initializeImplementation() {
	_setClassHelper(SpawnAreaHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void SpawnAreaImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (SpawnArea*) stub;
	ActiveAreaImplementation::_setStub(stub);
}

DistributedObjectStub* SpawnAreaImplementation::_getStub() {
	return _this;
}

SpawnAreaImplementation::operator const SpawnArea*() {
	return _this;
}

void SpawnAreaImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void SpawnAreaImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void SpawnAreaImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void SpawnAreaImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void SpawnAreaImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void SpawnAreaImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void SpawnAreaImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void SpawnAreaImplementation::_serializationHelperMethod() {
	ActiveAreaImplementation::_serializationHelperMethod();

	_setClassName("SpawnArea");

}

void SpawnAreaImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(SpawnAreaImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool SpawnAreaImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ActiveAreaImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "spawnCreatureTemplates") {
		TypeInfo<SortedVector<unsigned int> >::parseFromBinaryStream(&spawnCreatureTemplates, stream);
		return true;
	}

	if (_name == "observers") {
		TypeInfo<SortedVector<ManagedReference<SpawnObserver* > > >::parseFromBinaryStream(&observers, stream);
		return true;
	}

	if (_name == "tier") {
		TypeInfo<int >::parseFromBinaryStream(&tier, stream);
		return true;
	}

	if (_name == "spawnConstant") {
		TypeInfo<int >::parseFromBinaryStream(&spawnConstant, stream);
		return true;
	}


	return false;
}

void SpawnAreaImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = SpawnAreaImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int SpawnAreaImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "spawnCreatureTemplates";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<SortedVector<unsigned int> >::toBinaryStream(&spawnCreatureTemplates, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "observers";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<SortedVector<ManagedReference<SpawnObserver* > > >::toBinaryStream(&observers, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "tier";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&tier, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "spawnConstant";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&spawnConstant, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 4 + ActiveAreaImplementation::writeObjectMembers(stream);
}

SpawnAreaImplementation::SpawnAreaImplementation() {
	_initializeImplementation();
	// server/zone/objects/area/SpawnArea.idl():  		spawnConstant = 0;
	spawnConstant = 0;
	// server/zone/objects/area/SpawnArea.idl():  		Logger.setLoggingName("SpawnArea");
	Logger::setLoggingName("SpawnArea");
}

void SpawnAreaImplementation::registerObservers() {
}

int SpawnAreaImplementation::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	// server/zone/objects/area/SpawnArea.idl():  		return 1;
	return 1;
}

void SpawnAreaImplementation::addTemplate(unsigned int tempCRC) {
	// server/zone/objects/area/SpawnArea.idl():  		spawnCreatureTemplates.add(tempCRC);
	(&spawnCreatureTemplates)->add(tempCRC);
}

void SpawnAreaImplementation::setTier(int n) {
	// server/zone/objects/area/SpawnArea.idl():  		tier = n;
	tier = n;
}

void SpawnAreaImplementation::setSpawnConstant(int n) {
	// server/zone/objects/area/SpawnArea.idl():  		spawnConstant = n;
	spawnConstant = n;
}

bool SpawnAreaImplementation::isStaticArea() {
	// server/zone/objects/area/SpawnArea.idl():  		return false;
	return false;
}

bool SpawnAreaImplementation::isDynamicArea() {
	// server/zone/objects/area/SpawnArea.idl():  		return false;
	return false;
}

/*
 *	SpawnAreaAdapter
 */

SpawnAreaAdapter::SpawnAreaAdapter(SpawnAreaImplementation* obj) : ActiveAreaAdapter(obj) {
}

Packet* SpawnAreaAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_REGISTEROBSERVERS__:
		registerObservers();
		break;
	case RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_:
		resp->insertSignedInt(notifyObserverEvent(inv->getUnsignedIntParameter(), (Observable*) inv->getObjectParameter(), (ManagedObject*) inv->getObjectParameter(), inv->getSignedLongParameter()));
		break;
	case RPC_ADDTEMPLATE__INT_:
		addTemplate(inv->getUnsignedIntParameter());
		break;
	case RPC_SETTIER__INT_:
		setTier(inv->getSignedIntParameter());
		break;
	case RPC_SETSPAWNCONSTANT__INT_:
		setSpawnConstant(inv->getSignedIntParameter());
		break;
	case RPC_ISSTATICAREA__:
		resp->insertBoolean(isStaticArea());
		break;
	case RPC_ISDYNAMICAREA__:
		resp->insertBoolean(isDynamicArea());
		break;
	default:
		return NULL;
	}

	return resp;
}

void SpawnAreaAdapter::registerObservers() {
	((SpawnAreaImplementation*) impl)->registerObservers();
}

int SpawnAreaAdapter::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	return ((SpawnAreaImplementation*) impl)->notifyObserverEvent(eventType, observable, arg1, arg2);
}

void SpawnAreaAdapter::addTemplate(unsigned int tempCRC) {
	((SpawnAreaImplementation*) impl)->addTemplate(tempCRC);
}

void SpawnAreaAdapter::setTier(int n) {
	((SpawnAreaImplementation*) impl)->setTier(n);
}

void SpawnAreaAdapter::setSpawnConstant(int n) {
	((SpawnAreaImplementation*) impl)->setSpawnConstant(n);
}

bool SpawnAreaAdapter::isStaticArea() {
	return ((SpawnAreaImplementation*) impl)->isStaticArea();
}

bool SpawnAreaAdapter::isDynamicArea() {
	return ((SpawnAreaImplementation*) impl)->isDynamicArea();
}

/*
 *	SpawnAreaHelper
 */

SpawnAreaHelper* SpawnAreaHelper::staticInitializer = SpawnAreaHelper::instance();

SpawnAreaHelper::SpawnAreaHelper() {
	className = "SpawnArea";

	Core::getObjectBroker()->registerClass(className, this);
}

void SpawnAreaHelper::finalizeHelper() {
	SpawnAreaHelper::finalize();
}

DistributedObject* SpawnAreaHelper::instantiateObject() {
	return new SpawnArea(DummyConstructorParameter::instance());
}

DistributedObjectServant* SpawnAreaHelper::instantiateServant() {
	return new SpawnAreaImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* SpawnAreaHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new SpawnAreaAdapter((SpawnAreaImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}
