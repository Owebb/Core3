/*
 *	server/zone/objects/tangible/pharmaceutical/RevivePack.cpp generated by engine3 IDL compiler 0.60
 */

#include "RevivePack.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

/*
 *	RevivePackStub
 */

RevivePack::RevivePack() : PharmaceuticalObject(DummyConstructorParameter::instance()) {
	RevivePackImplementation* _implementation = new RevivePackImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

RevivePack::RevivePack(DummyConstructorParameter* param) : PharmaceuticalObject(param) {
}

RevivePack::~RevivePack() {
}


void RevivePack::updateCraftingValues(ManufactureSchematic* schematic) {
	RevivePackImplementation* _implementation = (RevivePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->updateCraftingValues(schematic);
}

void RevivePack::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	RevivePackImplementation* _implementation = (RevivePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillAttributeList(msg, object);
}

int RevivePack::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	RevivePackImplementation* _implementation = (RevivePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->handleObjectMenuSelect(player, selectedID);
}

float RevivePack::getHealthWoundHealed() {
	RevivePackImplementation* _implementation = (RevivePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getHealthWoundHealed();
}

float RevivePack::getHealthHealed() {
	RevivePackImplementation* _implementation = (RevivePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getHealthHealed();
}

float RevivePack::getActionWoundHealed() {
	RevivePackImplementation* _implementation = (RevivePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getActionWoundHealed();
}

float RevivePack::getActionHealed() {
	RevivePackImplementation* _implementation = (RevivePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getActionHealed();
}

float RevivePack::getMindWoundHealed() {
	RevivePackImplementation* _implementation = (RevivePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getMindWoundHealed();
}

float RevivePack::getMindHealed() {
	RevivePackImplementation* _implementation = (RevivePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getMindHealed();
}

bool RevivePack::isRevivePack() {
	RevivePackImplementation* _implementation = (RevivePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isRevivePack();
}

DistributedObjectServant* RevivePack::_getImplementation() {

	_updated = true;
	return _impl;
}

void RevivePack::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	RevivePackImplementation
 */

RevivePackImplementation::RevivePackImplementation(DummyConstructorParameter* param) : PharmaceuticalObjectImplementation(param) {
	_initializeImplementation();
}


RevivePackImplementation::~RevivePackImplementation() {
}


void RevivePackImplementation::finalize() {
}

void RevivePackImplementation::_initializeImplementation() {
	_setClassHelper(RevivePackHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void RevivePackImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (RevivePack*) stub;
	PharmaceuticalObjectImplementation::_setStub(stub);
}

DistributedObjectStub* RevivePackImplementation::_getStub() {
	return _this;
}

RevivePackImplementation::operator const RevivePack*() {
	return _this;
}

void RevivePackImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void RevivePackImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void RevivePackImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void RevivePackImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void RevivePackImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void RevivePackImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void RevivePackImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void RevivePackImplementation::_serializationHelperMethod() {
	PharmaceuticalObjectImplementation::_serializationHelperMethod();

	_setClassName("RevivePack");

}

void RevivePackImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(RevivePackImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool RevivePackImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (PharmaceuticalObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "healthWoundHealed") {
		TypeInfo<float >::parseFromBinaryStream(&healthWoundHealed, stream);
		return true;
	}

	if (_name == "healthHealed") {
		TypeInfo<float >::parseFromBinaryStream(&healthHealed, stream);
		return true;
	}

	if (_name == "actionWoundHealed") {
		TypeInfo<float >::parseFromBinaryStream(&actionWoundHealed, stream);
		return true;
	}

	if (_name == "actionHealed") {
		TypeInfo<float >::parseFromBinaryStream(&actionHealed, stream);
		return true;
	}

	if (_name == "mindWoundHealed") {
		TypeInfo<float >::parseFromBinaryStream(&mindWoundHealed, stream);
		return true;
	}

	if (_name == "mindHealed") {
		TypeInfo<float >::parseFromBinaryStream(&mindHealed, stream);
		return true;
	}


	return false;
}

void RevivePackImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = RevivePackImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int RevivePackImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "healthWoundHealed";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&healthWoundHealed, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "healthHealed";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&healthHealed, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "actionWoundHealed";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&actionWoundHealed, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "actionHealed";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&actionHealed, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "mindWoundHealed";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&mindWoundHealed, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "mindHealed";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&mindHealed, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 6 + PharmaceuticalObjectImplementation::writeObjectMembers(stream);
}

RevivePackImplementation::RevivePackImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(69):  		setLoggingName("RevivePack");
	setLoggingName("RevivePack");
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(71):  		healthWoundHealed = 100;
	healthWoundHealed = 100;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(72):  		healthHealed = 100;
	healthHealed = 100;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(73):  		actionWoundHealed = 100;
	actionWoundHealed = 100;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(74):  		actionHealed = 100;
	actionHealed = 100;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(75):  		mindWoundHealed = 100;
	mindWoundHealed = 100;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(76):  		mindHealed = 100;
	mindHealed = 100;
}

void RevivePackImplementation::updateCraftingValues(ManufactureSchematic* schematic) {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(81):  		CraftingValues craftingValues = schematic.getCraftingValues();
	CraftingValues* craftingValues = schematic->getCraftingValues();
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(83):  		float effectiveness = craftingValues.getCurrentValue("power");
	float effectiveness = craftingValues->getCurrentValue("power");
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(84):  		super.medicineUseRequired = craftingValues.getCurrentValue("skillmodmin");
	PharmaceuticalObjectImplementation::medicineUseRequired = craftingValues->getCurrentValue("skillmodmin");
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(85):  		setUseCount(craftingValues.getCurrentValue("charges"));
	setUseCount(craftingValues->getCurrentValue("charges"));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(87):  		craftingValues.setHidden("power");
	craftingValues->setHidden("power");
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(89):  		float health = 2 * effectiveness;
	float health = 2 * effectiveness;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(90):  		healthWoundHealed = health;
	healthWoundHealed = health;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(91):  		healthHealed = 2 * effectiveness - health;
	healthHealed = 2 * effectiveness - health;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(93):  		float action = 2 * effectiveness;
	float action = 2 * effectiveness;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(94):  		action = System.random(action / 4);
	action = System::random(action / 4);
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(95):  		action = action + effectiveness / 2;
	action = action + effectiveness / 2;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(97):  		actionWoundHealed = action;
	actionWoundHealed = action;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(98):  		actionHealed = 2 * effectiveness - action;
	actionHealed = 2 * effectiveness - action;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(100):  		float mind = 1.5 * effectiveness;
	float mind = 1.5 * effectiveness;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(101):  		mind = System.random(mind / 4);
	mind = System::random(mind / 4);
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(102):  		mind = mind + effectiveness / 2;
	mind = mind + effectiveness / 2;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(104):  		mindWoundHealed = mind;
	mindWoundHealed = mind;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(105):  		mindHealed = 1.5 * effectiveness - mind;
	mindHealed = 1.5 * effectiveness - mind;
}

void RevivePackImplementation::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(117):  		super.fillAttributeList(msg, object);
	PharmaceuticalObjectImplementation::fillAttributeList(msg, object);
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(119):  		msg.insertAttribute("examine_heal_wound_health", Math.getPrecision(healthWoundHealed, 0));
	msg->insertAttribute("examine_heal_wound_health", Math::getPrecision(healthWoundHealed, 0));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(120):  		msg.insertAttribute("examine_heal_damage_health", Math.getPrecision(healthHealed, 0));
	msg->insertAttribute("examine_heal_damage_health", Math::getPrecision(healthHealed, 0));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(122):  		msg.insertAttribute("examine_heal_wound_mind", Math.getPrecision(mindWoundHealed, 0));
	msg->insertAttribute("examine_heal_wound_mind", Math::getPrecision(mindWoundHealed, 0));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(123):  		msg.insertAttribute("examine_heal_damage_mind", Math.getPrecision(mindHealed, 0));
	msg->insertAttribute("examine_heal_damage_mind", Math::getPrecision(mindHealed, 0));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(125):  		msg.insertAttribute("examine_heal_wound_action", Math.getPrecision(actionWoundHealed, 0));
	msg->insertAttribute("examine_heal_wound_action", Math::getPrecision(actionWoundHealed, 0));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(126):  		msg.insertAttribute("examine_heal_damage_action", Math.getPrecision(actionHealed, 0));
	msg->insertAttribute("examine_heal_damage_action", Math::getPrecision(actionHealed, 0));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(128):  		msg.insertAttribute("healing_ability", super.medicineUseRequired);
	msg->insertAttribute("healing_ability", PharmaceuticalObjectImplementation::medicineUseRequired);
}

int RevivePackImplementation::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(140):  		if 
	if (selectedID != 20)	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(141):  			return 1;
	return 1;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(143):  
	if (player->getSkillMod("healing_ability") < PharmaceuticalObjectImplementation::medicineUseRequired){
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(144):  			player.sendSystemMessage("error_message", "insufficient_skill");
	player->sendSystemMessage("error_message", "insufficient_skill");
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(146):  			return 0;
	return 0;
}

	else {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(148):  			string command = "/reviveplayer ";
	String command = "/reviveplayer ";
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(149):  			command = command + String.valueOf(super.getObjectID());
	command = command + String::valueOf(PharmaceuticalObjectImplementation::getObjectID());
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(151):  			player.sendExecuteConsoleCommand(command);
	player->sendExecuteConsoleCommand(command);
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(153):  			return 0;
	return 0;
}
}

float RevivePackImplementation::getHealthWoundHealed() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(159):  		return healthWoundHealed;
	return healthWoundHealed;
}

float RevivePackImplementation::getHealthHealed() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(163):  		return healthHealed;
	return healthHealed;
}

float RevivePackImplementation::getActionWoundHealed() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(167):  		return actionWoundHealed;
	return actionWoundHealed;
}

float RevivePackImplementation::getActionHealed() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(171):  		return actionHealed;
	return actionHealed;
}

float RevivePackImplementation::getMindWoundHealed() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(175):  		return mindWoundHealed;
	return mindWoundHealed;
}

float RevivePackImplementation::getMindHealed() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(179):  		return mindHealed;
	return mindHealed;
}

bool RevivePackImplementation::isRevivePack() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl(183):  		return true;
	return true;
}

/*
 *	RevivePackAdapter
 */

RevivePackAdapter::RevivePackAdapter(RevivePackImplementation* obj) : PharmaceuticalObjectAdapter(obj) {
}

Packet* RevivePackAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	case 7:
		resp->insertFloat(getHealthWoundHealed());
		break;
	case 8:
		resp->insertFloat(getHealthHealed());
		break;
	case 9:
		resp->insertFloat(getActionWoundHealed());
		break;
	case 10:
		resp->insertFloat(getActionHealed());
		break;
	case 11:
		resp->insertFloat(getMindWoundHealed());
		break;
	case 12:
		resp->insertFloat(getMindHealed());
		break;
	case 13:
		resp->insertBoolean(isRevivePack());
		break;
	default:
		return NULL;
	}

	return resp;
}

int RevivePackAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((RevivePackImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

float RevivePackAdapter::getHealthWoundHealed() {
	return ((RevivePackImplementation*) impl)->getHealthWoundHealed();
}

float RevivePackAdapter::getHealthHealed() {
	return ((RevivePackImplementation*) impl)->getHealthHealed();
}

float RevivePackAdapter::getActionWoundHealed() {
	return ((RevivePackImplementation*) impl)->getActionWoundHealed();
}

float RevivePackAdapter::getActionHealed() {
	return ((RevivePackImplementation*) impl)->getActionHealed();
}

float RevivePackAdapter::getMindWoundHealed() {
	return ((RevivePackImplementation*) impl)->getMindWoundHealed();
}

float RevivePackAdapter::getMindHealed() {
	return ((RevivePackImplementation*) impl)->getMindHealed();
}

bool RevivePackAdapter::isRevivePack() {
	return ((RevivePackImplementation*) impl)->isRevivePack();
}

/*
 *	RevivePackHelper
 */

RevivePackHelper* RevivePackHelper::staticInitializer = RevivePackHelper::instance();

RevivePackHelper::RevivePackHelper() {
	className = "RevivePack";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void RevivePackHelper::finalizeHelper() {
	RevivePackHelper::finalize();
}

DistributedObject* RevivePackHelper::instantiateObject() {
	return new RevivePack(DummyConstructorParameter::instance());
}

DistributedObjectServant* RevivePackHelper::instantiateServant() {
	return new RevivePackImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* RevivePackHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new RevivePackAdapter((RevivePackImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}
