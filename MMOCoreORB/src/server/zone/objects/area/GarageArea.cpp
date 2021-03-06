/*
 *	server/zone/objects/area/GarageArea.cpp generated by engine3 IDL compiler 0.60
 */

#include "GarageArea.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/creature/CreatureObject.h"

/*
 *	GarageAreaStub
 */

enum {RPC_NOTIFYENTER__SCENEOBJECT_ = 6};

GarageArea::GarageArea() : ActiveArea(DummyConstructorParameter::instance()) {
	GarageAreaImplementation* _implementation = new GarageAreaImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("GarageArea");
}

GarageArea::GarageArea(DummyConstructorParameter* param) : ActiveArea(param) {
	_setClassName("GarageArea");
}

GarageArea::~GarageArea() {
}



void GarageArea::notifyEnter(SceneObject* player) {
	GarageAreaImplementation* _implementation = static_cast<GarageAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYENTER__SCENEOBJECT_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->notifyEnter(player);
}

DistributedObjectServant* GarageArea::_getImplementation() {

	 if (!_updated) _updated = true;
	return _impl;
}

DistributedObjectServant* GarageArea::_getImplementationForRead() {
	return _impl;
}

void GarageArea::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	GarageAreaImplementation
 */

GarageAreaImplementation::GarageAreaImplementation(DummyConstructorParameter* param) : ActiveAreaImplementation(param) {
	_initializeImplementation();
}


GarageAreaImplementation::~GarageAreaImplementation() {
}


void GarageAreaImplementation::finalize() {
}

void GarageAreaImplementation::_initializeImplementation() {
	_setClassHelper(GarageAreaHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void GarageAreaImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<GarageArea*>(stub);
	ActiveAreaImplementation::_setStub(stub);
}

DistributedObjectStub* GarageAreaImplementation::_getStub() {
	return _this.get();
}

GarageAreaImplementation::operator const GarageArea*() {
	return _this.get();
}

void GarageAreaImplementation::lock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->lock(doLock);
}

void GarageAreaImplementation::lock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->lock(obj);
}

void GarageAreaImplementation::rlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->rlock(doLock);
}

void GarageAreaImplementation::wlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->wlock(doLock);
}

void GarageAreaImplementation::wlock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->wlock(obj);
}

void GarageAreaImplementation::unlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->unlock(doLock);
}

void GarageAreaImplementation::runlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->runlock(doLock);
}

void GarageAreaImplementation::_serializationHelperMethod() {
	ActiveAreaImplementation::_serializationHelperMethod();

	_setClassName("GarageArea");

}

void GarageAreaImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(GarageAreaImplementation::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool GarageAreaImplementation::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (ActiveAreaImplementation::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	}

	return false;
}

void GarageAreaImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = GarageAreaImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int GarageAreaImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ActiveAreaImplementation::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;

	return _count + 0;
}

GarageAreaImplementation::GarageAreaImplementation() {
	_initializeImplementation();
	// server/zone/objects/area/GarageArea.idl():  		Logger.setLoggingName("GarageArea");
	Logger::setLoggingName("GarageArea");
}

void GarageAreaImplementation::notifyEnter(SceneObject* player) {
	// server/zone/objects/area/GarageArea.idl():  	}
	if (player->isPlayerCreature()){
	// server/zone/objects/area/GarageArea.idl():  			CreatureObject playerCreature = (CreatureObject) player;
	ManagedReference<CreatureObject* > playerCreature = (CreatureObject*) player;
	// server/zone/objects/area/GarageArea.idl():  			SceneObject rootParent = playerCreature.getRootParent();
	ManagedReference<SceneObject* > rootParent = playerCreature->getRootParent();
	// server/zone/objects/area/GarageArea.idl():  			playerCreature.
	if (rootParent == NULL || !rootParent->isVehicleObject())	// server/zone/objects/area/GarageArea.idl():  				return;
	return;
	// server/zone/objects/area/GarageArea.idl():  			playerCreature.sendSystemMessage("@pet/pet_menu:garage_proximity");
	playerCreature->sendSystemMessage("@pet/pet_menu:garage_proximity");
}
}

/*
 *	GarageAreaAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


GarageAreaAdapter::GarageAreaAdapter(GarageArea* obj) : ActiveAreaAdapter(obj) {
}

void GarageAreaAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_NOTIFYENTER__SCENEOBJECT_:
		{
			notifyEnter(static_cast<SceneObject*>(inv->getObjectParameter()));
		}
		break;
	default:
		throw Exception("Method does not exists");
	}
}

void GarageAreaAdapter::notifyEnter(SceneObject* player) {
	(static_cast<GarageArea*>(stub))->notifyEnter(player);
}

/*
 *	GarageAreaHelper
 */

GarageAreaHelper* GarageAreaHelper::staticInitializer = GarageAreaHelper::instance();

GarageAreaHelper::GarageAreaHelper() {
	className = "GarageArea";

	Core::getObjectBroker()->registerClass(className, this);
}

void GarageAreaHelper::finalizeHelper() {
	GarageAreaHelper::finalize();
}

DistributedObject* GarageAreaHelper::instantiateObject() {
	return new GarageArea(DummyConstructorParameter::instance());
}

DistributedObjectServant* GarageAreaHelper::instantiateServant() {
	return new GarageAreaImplementation();
}

DistributedObjectAdapter* GarageAreaHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new GarageAreaAdapter(static_cast<GarageArea*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

