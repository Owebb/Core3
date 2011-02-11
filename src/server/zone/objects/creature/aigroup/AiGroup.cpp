/*
 *	server/zone/objects/creature/aigroup/AiGroup.cpp generated by engine3 IDL compiler 0.60
 */

#include "AiGroup.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/creature/AiAgent.h"

#include "server/zone/managers/creature/StaticSpawnGroup.h"

#include "server/zone/managers/creature/DynamicSpawnGroup.h"

#include "server/zone/objects/creature/aigroup/AiGroupObserver.h"

/*
 *	AiGroupStub
 */

AiGroup::AiGroup() : SceneObject(DummyConstructorParameter::instance()) {
	AiGroupImplementation* _implementation = new AiGroupImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

AiGroup::AiGroup(DummyConstructorParameter* param) : SceneObject(param) {
}

AiGroup::~AiGroup() {
}


void AiGroup::setPatrolPoints() {
	AiGroupImplementation* _implementation = (AiGroupImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		_implementation->setPatrolPoints();
}

void AiGroup::setPatrolPoint(AiAgent* member) {
	AiGroupImplementation* _implementation = (AiGroupImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(member);

		method.executeWithVoidReturn();
	} else
		_implementation->setPatrolPoint(member);
}

void AiGroup::setup(StaticSpawnGroup* templ) {
	AiGroupImplementation* _implementation = (AiGroupImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->setup(templ);
}

void AiGroup::setup(DynamicSpawnGroup* templ) {
	AiGroupImplementation* _implementation = (AiGroupImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->setup(templ);
}

int AiGroup::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	AiGroupImplementation* _implementation = (AiGroupImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addUnsignedIntParameter(eventType);
		method.addObjectParameter(observable);
		method.addObjectParameter(arg1);
		method.addSignedLongParameter(arg2);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->notifyObserverEvent(eventType, observable, arg1, arg2);
}

bool AiGroup::isHerdGroup() {
	AiGroupImplementation* _implementation = (AiGroupImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isHerdGroup();
}

bool AiGroup::isPackGroup() {
	AiGroupImplementation* _implementation = (AiGroupImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isPackGroup();
}

bool AiGroup::isLairGroup() {
	AiGroupImplementation* _implementation = (AiGroupImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isLairGroup();
}

DistributedObjectServant* AiGroup::_getImplementation() {

	_updated = true;
	return _impl;
}

void AiGroup::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	AiGroupImplementation
 */

AiGroupImplementation::AiGroupImplementation(DummyConstructorParameter* param) : SceneObjectImplementation(param) {
	_initializeImplementation();
}


AiGroupImplementation::~AiGroupImplementation() {
}


void AiGroupImplementation::finalize() {
}

void AiGroupImplementation::_initializeImplementation() {
	_setClassHelper(AiGroupHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void AiGroupImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (AiGroup*) stub;
	SceneObjectImplementation::_setStub(stub);
}

DistributedObjectStub* AiGroupImplementation::_getStub() {
	return _this;
}

AiGroupImplementation::operator const AiGroup*() {
	return _this;
}

void AiGroupImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void AiGroupImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void AiGroupImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void AiGroupImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void AiGroupImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void AiGroupImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void AiGroupImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void AiGroupImplementation::_serializationHelperMethod() {
	SceneObjectImplementation::_serializationHelperMethod();

	_setClassName("AiGroup");

}

void AiGroupImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(AiGroupImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool AiGroupImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (SceneObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "leader") {
		TypeInfo<ManagedReference<SceneObject* > >::parseFromBinaryStream(&leader, stream);
		return true;
	}

	if (_name == "scouts") {
		TypeInfo<SortedVector<ManagedReference<AiAgent* > > >::parseFromBinaryStream(&scouts, stream);
		return true;
	}

	if (_name == "scoutTemps") {
		TypeInfo<Vector<String> >::parseFromBinaryStream(&scoutTemps, stream);
		return true;
	}

	if (_name == "protectors") {
		TypeInfo<SortedVector<ManagedReference<AiAgent* > > >::parseFromBinaryStream(&protectors, stream);
		return true;
	}

	if (_name == "protectorTemps") {
		TypeInfo<Vector<String> >::parseFromBinaryStream(&protectorTemps, stream);
		return true;
	}

	if (_name == "babies") {
		TypeInfo<SortedVector<ManagedReference<AiAgent* > > >::parseFromBinaryStream(&babies, stream);
		return true;
	}

	if (_name == "babyTemps") {
		TypeInfo<Vector<String> >::parseFromBinaryStream(&babyTemps, stream);
		return true;
	}

	if (_name == "subgroups") {
		TypeInfo<SortedVector<ManagedReference<AiGroup* > > >::parseFromBinaryStream(&subgroups, stream);
		return true;
	}

	if (_name == "observers") {
		TypeInfo<SortedVector<ManagedReference<AiGroupObserver* > > >::parseFromBinaryStream(&observers, stream);
		return true;
	}

	if (_name == "commandLevel") {
		TypeInfo<int >::parseFromBinaryStream(&commandLevel, stream);
		return true;
	}

	if (_name == "wanderRadius") {
		TypeInfo<float >::parseFromBinaryStream(&wanderRadius, stream);
		return true;
	}

	if (_name == "size") {
		TypeInfo<int >::parseFromBinaryStream(&size, stream);
		return true;
	}

	if (_name == "scoutWeight") {
		TypeInfo<float >::parseFromBinaryStream(&scoutWeight, stream);
		return true;
	}

	if (_name == "protectorWeight") {
		TypeInfo<float >::parseFromBinaryStream(&protectorWeight, stream);
		return true;
	}

	if (_name == "babyWeight") {
		TypeInfo<float >::parseFromBinaryStream(&babyWeight, stream);
		return true;
	}

	if (_name == "isStatic") {
		TypeInfo<bool >::parseFromBinaryStream(&isStatic, stream);
		return true;
	}


	return false;
}

void AiGroupImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = AiGroupImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int AiGroupImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "leader";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedReference<SceneObject* > >::toBinaryStream(&leader, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "scouts";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<SortedVector<ManagedReference<AiAgent* > > >::toBinaryStream(&scouts, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "scoutTemps";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<Vector<String> >::toBinaryStream(&scoutTemps, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "protectors";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<SortedVector<ManagedReference<AiAgent* > > >::toBinaryStream(&protectors, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "protectorTemps";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<Vector<String> >::toBinaryStream(&protectorTemps, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "babies";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<SortedVector<ManagedReference<AiAgent* > > >::toBinaryStream(&babies, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "babyTemps";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<Vector<String> >::toBinaryStream(&babyTemps, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "subgroups";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<SortedVector<ManagedReference<AiGroup* > > >::toBinaryStream(&subgroups, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "observers";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<SortedVector<ManagedReference<AiGroupObserver* > > >::toBinaryStream(&observers, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "commandLevel";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&commandLevel, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "wanderRadius";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&wanderRadius, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "size";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&size, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "scoutWeight";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&scoutWeight, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "protectorWeight";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&protectorWeight, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "babyWeight";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&babyWeight, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "isStatic";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<bool >::toBinaryStream(&isStatic, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 16 + SceneObjectImplementation::writeObjectMembers(stream);
}

AiGroupImplementation::AiGroupImplementation() {
	_initializeImplementation();
	// server/zone/objects/creature/aigroup/AiGroup.idl(97):  		Logger.setLoggingName("AiGroup");
	Logger::setLoggingName("AiGroup");
	// server/zone/objects/creature/aigroup/AiGroup.idl(99):  		commandLevel = 0;
	commandLevel = 0;
	// server/zone/objects/creature/aigroup/AiGroup.idl(100):  		wanderRadius = 0;
	wanderRadius = 0;
	// server/zone/objects/creature/aigroup/AiGroup.idl(101):  		size = 0;
	size = 0;
	// server/zone/objects/creature/aigroup/AiGroup.idl(103):  		isStatic = true;
	isStatic = true;
}

bool AiGroupImplementation::isHerdGroup() {
	// server/zone/objects/creature/aigroup/AiGroup.idl(118):  		return false;
	return false;
}

bool AiGroupImplementation::isPackGroup() {
	// server/zone/objects/creature/aigroup/AiGroup.idl(122):  		return false;
	return false;
}

bool AiGroupImplementation::isLairGroup() {
	// server/zone/objects/creature/aigroup/AiGroup.idl(126):  		return false;
	return false;
}

/*
 *	AiGroupAdapter
 */

AiGroupAdapter::AiGroupAdapter(AiGroupImplementation* obj) : SceneObjectAdapter(obj) {
}

Packet* AiGroupAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		setPatrolPoints();
		break;
	case 7:
		setPatrolPoint((AiAgent*) inv->getObjectParameter());
		break;
	case 8:
		resp->insertSignedInt(notifyObserverEvent(inv->getUnsignedIntParameter(), (Observable*) inv->getObjectParameter(), (ManagedObject*) inv->getObjectParameter(), inv->getSignedLongParameter()));
		break;
	case 9:
		resp->insertBoolean(isHerdGroup());
		break;
	case 10:
		resp->insertBoolean(isPackGroup());
		break;
	case 11:
		resp->insertBoolean(isLairGroup());
		break;
	default:
		return NULL;
	}

	return resp;
}

void AiGroupAdapter::setPatrolPoints() {
	((AiGroupImplementation*) impl)->setPatrolPoints();
}

void AiGroupAdapter::setPatrolPoint(AiAgent* member) {
	((AiGroupImplementation*) impl)->setPatrolPoint(member);
}

int AiGroupAdapter::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	return ((AiGroupImplementation*) impl)->notifyObserverEvent(eventType, observable, arg1, arg2);
}

bool AiGroupAdapter::isHerdGroup() {
	return ((AiGroupImplementation*) impl)->isHerdGroup();
}

bool AiGroupAdapter::isPackGroup() {
	return ((AiGroupImplementation*) impl)->isPackGroup();
}

bool AiGroupAdapter::isLairGroup() {
	return ((AiGroupImplementation*) impl)->isLairGroup();
}

/*
 *	AiGroupHelper
 */

AiGroupHelper* AiGroupHelper::staticInitializer = AiGroupHelper::instance();

AiGroupHelper::AiGroupHelper() {
	className = "AiGroup";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void AiGroupHelper::finalizeHelper() {
	AiGroupHelper::finalize();
}

DistributedObject* AiGroupHelper::instantiateObject() {
	return new AiGroup(DummyConstructorParameter::instance());
}

DistributedObjectServant* AiGroupHelper::instantiateServant() {
	return new AiGroupImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* AiGroupHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new AiGroupAdapter((AiGroupImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}
