/*
 *	server/zone/managers/loot/lootgroup/LootObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "LootObject.h"

/*
 *	LootObjectStub
 */

LootObject::LootObject(unsigned int loID, String& n, unsigned int tCRC, unsigned int lootG, int ch) : ManagedObject(DummyConstructorParameter::instance()) {
	LootObjectImplementation* _implementation = new LootObjectImplementation(loID, n, tCRC, lootG, ch);
	_impl = _implementation;
	_impl->_setStub(this);
}

LootObject::LootObject(DummyConstructorParameter* param) : ManagedObject(param) {
}

LootObject::~LootObject() {
}


void LootObject::check(String& newName, unsigned int newTemplateCRC, int newChance) {
	LootObjectImplementation* _implementation = (LootObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addAsciiParameter(newName);
		method.addUnsignedIntParameter(newTemplateCRC);
		method.addSignedIntParameter(newChance);

		method.executeWithVoidReturn();
	} else
		_implementation->check(newName, newTemplateCRC, newChance);
}

unsigned int LootObject::getTemplateCRC() {
	LootObjectImplementation* _implementation = (LootObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->getTemplateCRC();
}

int LootObject::getChance() {
	LootObjectImplementation* _implementation = (LootObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getChance();
}

DistributedObjectServant* LootObject::_getImplementation() {

	_updated = true;
	return _impl;
}

void LootObject::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	LootObjectImplementation
 */

LootObjectImplementation::LootObjectImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


LootObjectImplementation::~LootObjectImplementation() {
}


void LootObjectImplementation::finalize() {
}

void LootObjectImplementation::_initializeImplementation() {
	_setClassHelper(LootObjectHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void LootObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (LootObject*) stub;
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* LootObjectImplementation::_getStub() {
	return _this;
}

LootObjectImplementation::operator const LootObject*() {
	return _this;
}

void LootObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void LootObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void LootObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void LootObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void LootObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void LootObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void LootObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void LootObjectImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("LootObject");

}

void LootObjectImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(LootObjectImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool LootObjectImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ManagedObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "templateCRC") {
		TypeInfo<unsigned int >::parseFromBinaryStream(&templateCRC, stream);
		return true;
	}

	if (_name == "lootGroup") {
		TypeInfo<unsigned int >::parseFromBinaryStream(&lootGroup, stream);
		return true;
	}

	if (_name == "name") {
		TypeInfo<String >::parseFromBinaryStream(&name, stream);
		return true;
	}

	if (_name == "lootObjectID") {
		TypeInfo<unsigned int >::parseFromBinaryStream(&lootObjectID, stream);
		return true;
	}

	if (_name == "chance") {
		TypeInfo<int >::parseFromBinaryStream(&chance, stream);
		return true;
	}


	return false;
}

void LootObjectImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = LootObjectImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int LootObjectImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "templateCRC";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<unsigned int >::toBinaryStream(&templateCRC, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "lootGroup";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<unsigned int >::toBinaryStream(&lootGroup, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "name";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<String >::toBinaryStream(&name, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "lootObjectID";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<unsigned int >::toBinaryStream(&lootObjectID, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "chance";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&chance, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 5 + ManagedObjectImplementation::writeObjectMembers(stream);
}

LootObjectImplementation::LootObjectImplementation(unsigned int loID, String& n, unsigned int tCRC, unsigned int lootG, int ch) {
	_initializeImplementation();
	// server/zone/managers/loot/lootgroup/LootObject.idl(61):  		lootObjectID = loID;
	lootObjectID = loID;
	// server/zone/managers/loot/lootgroup/LootObject.idl(62):  		name = n;
	name = n;
	// server/zone/managers/loot/lootgroup/LootObject.idl(63):  		templateCRC = tCRC;
	templateCRC = tCRC;
	// server/zone/managers/loot/lootgroup/LootObject.idl(64):  		lootGroup = lootG;
	lootGroup = lootG;
	// server/zone/managers/loot/lootgroup/LootObject.idl(65):  		chance = ch;
	chance = ch;
}

void LootObjectImplementation::check(String& newName, unsigned int newTemplateCRC, int newChance) {
	// server/zone/managers/loot/lootgroup/LootObject.idl(69):  		name = newName;
	name = newName;
	// server/zone/managers/loot/lootgroup/LootObject.idl(70):  		templateCRC = newTemplateCRC;
	templateCRC = newTemplateCRC;
	// server/zone/managers/loot/lootgroup/LootObject.idl(71):  		chance = newChance;
	chance = newChance;
}

unsigned int LootObjectImplementation::getTemplateCRC() {
	// server/zone/managers/loot/lootgroup/LootObject.idl(75):  		return templateCRC;
	return templateCRC;
}

int LootObjectImplementation::getChance() {
	// server/zone/managers/loot/lootgroup/LootObject.idl(79):  		return chance;
	return chance;
}

/*
 *	LootObjectAdapter
 */

LootObjectAdapter::LootObjectAdapter(LootObjectImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* LootObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		check(inv->getAsciiParameter(_param0_check__String_int_int_), inv->getUnsignedIntParameter(), inv->getSignedIntParameter());
		break;
	case 7:
		resp->insertInt(getTemplateCRC());
		break;
	case 8:
		resp->insertSignedInt(getChance());
		break;
	default:
		return NULL;
	}

	return resp;
}

void LootObjectAdapter::check(String& newName, unsigned int newTemplateCRC, int newChance) {
	((LootObjectImplementation*) impl)->check(newName, newTemplateCRC, newChance);
}

unsigned int LootObjectAdapter::getTemplateCRC() {
	return ((LootObjectImplementation*) impl)->getTemplateCRC();
}

int LootObjectAdapter::getChance() {
	return ((LootObjectImplementation*) impl)->getChance();
}

/*
 *	LootObjectHelper
 */

LootObjectHelper* LootObjectHelper::staticInitializer = LootObjectHelper::instance();

LootObjectHelper::LootObjectHelper() {
	className = "LootObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void LootObjectHelper::finalizeHelper() {
	LootObjectHelper::finalize();
}

DistributedObject* LootObjectHelper::instantiateObject() {
	return new LootObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* LootObjectHelper::instantiateServant() {
	return new LootObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* LootObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new LootObjectAdapter((LootObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}
