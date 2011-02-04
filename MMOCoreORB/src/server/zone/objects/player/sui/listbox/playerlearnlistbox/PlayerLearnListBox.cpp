/*
 *	server/zone/objects/player/sui/listbox/playerlearnlistbox/PlayerLearnListBox.cpp generated by engine3 IDL compiler 0.60
 */

#include "PlayerLearnListBox.h"

#include "server/zone/objects/creature/professions/SkillBox.h"

#include "server/zone/objects/player/PlayerCreature.h"

/*
 *	PlayerLearnListBoxStub
 */

PlayerLearnListBox::PlayerLearnListBox(PlayerCreature* player) : SuiListBox(DummyConstructorParameter::instance()) {
	PlayerLearnListBoxImplementation* _implementation = new PlayerLearnListBoxImplementation(player);
	_impl = _implementation;
	_impl->_setStub(this);
}

PlayerLearnListBox::PlayerLearnListBox(DummyConstructorParameter* param) : SuiListBox(param) {
}

PlayerLearnListBox::~PlayerLearnListBox() {
}


void PlayerLearnListBox::setTeacher(PlayerCreature* teacher) {
	PlayerLearnListBoxImplementation* _implementation = (PlayerLearnListBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(teacher);

		method.executeWithVoidReturn();
	} else
		_implementation->setTeacher(teacher);
}

PlayerCreature* PlayerLearnListBox::getTeacher() {
	PlayerLearnListBoxImplementation* _implementation = (PlayerLearnListBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getTeacher();
}

void PlayerLearnListBox::setTeachingOffer(const String& name) {
	PlayerLearnListBoxImplementation* _implementation = (PlayerLearnListBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addAsciiParameter(name);

		method.executeWithVoidReturn();
	} else
		_implementation->setTeachingOffer(name);
}

const String PlayerLearnListBox::getTeachingOffer() {
	PlayerLearnListBoxImplementation* _implementation = (PlayerLearnListBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getTeachingOffer();
}

DistributedObjectServant* PlayerLearnListBox::_getImplementation() {

	_updated = true;
	return _impl;
}

void PlayerLearnListBox::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	PlayerLearnListBoxImplementation
 */

PlayerLearnListBoxImplementation::PlayerLearnListBoxImplementation(DummyConstructorParameter* param) : SuiListBoxImplementation(param) {
	_initializeImplementation();
}


PlayerLearnListBoxImplementation::~PlayerLearnListBoxImplementation() {
}


void PlayerLearnListBoxImplementation::finalize() {
}

void PlayerLearnListBoxImplementation::_initializeImplementation() {
	_setClassHelper(PlayerLearnListBoxHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void PlayerLearnListBoxImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (PlayerLearnListBox*) stub;
	SuiListBoxImplementation::_setStub(stub);
}

DistributedObjectStub* PlayerLearnListBoxImplementation::_getStub() {
	return _this;
}

PlayerLearnListBoxImplementation::operator const PlayerLearnListBox*() {
	return _this;
}

void PlayerLearnListBoxImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void PlayerLearnListBoxImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void PlayerLearnListBoxImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void PlayerLearnListBoxImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void PlayerLearnListBoxImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void PlayerLearnListBoxImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void PlayerLearnListBoxImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void PlayerLearnListBoxImplementation::_serializationHelperMethod() {
	SuiListBoxImplementation::_serializationHelperMethod();

	_setClassName("PlayerLearnListBox");

}

void PlayerLearnListBoxImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(PlayerLearnListBoxImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool PlayerLearnListBoxImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (SuiListBoxImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "teacherPlayer") {
		TypeInfo<ManagedReference<PlayerCreature* > >::parseFromBinaryStream(&teacherPlayer, stream);
		return true;
	}

	if (_name == "teachingOffer") {
		TypeInfo<String >::parseFromBinaryStream(&teachingOffer, stream);
		return true;
	}


	return false;
}

void PlayerLearnListBoxImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = PlayerLearnListBoxImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int PlayerLearnListBoxImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "teacherPlayer";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedReference<PlayerCreature* > >::toBinaryStream(&teacherPlayer, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "teachingOffer";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<String >::toBinaryStream(&teachingOffer, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 2 + SuiListBoxImplementation::writeObjectMembers(stream);
}

PlayerLearnListBoxImplementation::PlayerLearnListBoxImplementation(PlayerCreature* player) : SuiListBoxImplementation(player, 35, 0) {
	_initializeImplementation();
}

void PlayerLearnListBoxImplementation::setTeacher(PlayerCreature* teacher) {
	// server/zone/objects/player/sui/listbox/playerlearnlistbox/PlayerLearnListBox.idl(65):   teacherPlayer = teacher;
	teacherPlayer = teacher;
}

PlayerCreature* PlayerLearnListBoxImplementation::getTeacher() {
	// server/zone/objects/player/sui/listbox/playerlearnlistbox/PlayerLearnListBox.idl(70):   return teacherPlayer;
	return teacherPlayer;
}

void PlayerLearnListBoxImplementation::setTeachingOffer(const String& name) {
	// server/zone/objects/player/sui/listbox/playerlearnlistbox/PlayerLearnListBox.idl(74):   teachingOffer = name;
	teachingOffer = name;
}

const String PlayerLearnListBoxImplementation::getTeachingOffer() {
	// server/zone/objects/player/sui/listbox/playerlearnlistbox/PlayerLearnListBox.idl(79):   return teachingOffer;
	return teachingOffer;
}

/*
 *	PlayerLearnListBoxAdapter
 */

PlayerLearnListBoxAdapter::PlayerLearnListBoxAdapter(PlayerLearnListBoxImplementation* obj) : SuiListBoxAdapter(obj) {
}

Packet* PlayerLearnListBoxAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		setTeacher((PlayerCreature*) inv->getObjectParameter());
		break;
	case 7:
		setTeachingOffer(inv->getAsciiParameter(_param0_setTeachingOffer__String_));
		break;
	default:
		return NULL;
	}

	return resp;
}

void PlayerLearnListBoxAdapter::setTeacher(PlayerCreature* teacher) {
	((PlayerLearnListBoxImplementation*) impl)->setTeacher(teacher);
}

void PlayerLearnListBoxAdapter::setTeachingOffer(const String& name) {
	((PlayerLearnListBoxImplementation*) impl)->setTeachingOffer(name);
}

/*
 *	PlayerLearnListBoxHelper
 */

PlayerLearnListBoxHelper* PlayerLearnListBoxHelper::staticInitializer = PlayerLearnListBoxHelper::instance();

PlayerLearnListBoxHelper::PlayerLearnListBoxHelper() {
	className = "PlayerLearnListBox";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void PlayerLearnListBoxHelper::finalizeHelper() {
	PlayerLearnListBoxHelper::finalize();
}

DistributedObject* PlayerLearnListBoxHelper::instantiateObject() {
	return new PlayerLearnListBox(DummyConstructorParameter::instance());
}

DistributedObjectServant* PlayerLearnListBoxHelper::instantiateServant() {
	return new PlayerLearnListBoxImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* PlayerLearnListBoxHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new PlayerLearnListBoxAdapter((PlayerLearnListBoxImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}
