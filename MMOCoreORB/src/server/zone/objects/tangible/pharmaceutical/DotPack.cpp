/*
 *	server/zone/objects/tangible/pharmaceutical/DotPack.cpp generated by engine3 IDL compiler 0.60
 */

#include "DotPack.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

/*
 *	DotPackStub
 */

enum {RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_,RPC_CALCULATEPOWER__CREATUREOBJECT_,RPC_ISPOISONDELIVERYUNIT__,RPC_ISDISEASEDELIVERYUNIT__,RPC_GETEFFECTIVENESS__,RPC_GETRANGE__,RPC_GETAREA__,RPC_GETRANGEMOD__,RPC_GETPOTENCY__,RPC_GETDURATION__,RPC_ISAREA__,RPC_GETPOOL__,RPC_GETDOTTYPE__};

DotPack::DotPack() : PharmaceuticalObject(DummyConstructorParameter::instance()) {
	DotPackImplementation* _implementation = new DotPackImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("DotPack");
}

DotPack::DotPack(DummyConstructorParameter* param) : PharmaceuticalObject(param) {
	_setClassName("DotPack");
}

DotPack::~DotPack() {
}



void DotPack::updateCraftingValues(CraftingValues* values, bool firstUpdate) {
	DotPackImplementation* _implementation = static_cast<DotPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->updateCraftingValues(values, firstUpdate);
}

void DotPack::loadTemplateData(SharedObjectTemplate* templateData) {
	DotPackImplementation* _implementation = static_cast<DotPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->loadTemplateData(templateData);
}

void DotPack::fillAttributeList(AttributeListMessage* msg, CreatureObject* object) {
	DotPackImplementation* _implementation = static_cast<DotPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillAttributeList(msg, object);
}

int DotPack::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	DotPackImplementation* _implementation = static_cast<DotPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->handleObjectMenuSelect(player, selectedID);
}

int DotPack::calculatePower(CreatureObject* creature) {
	DotPackImplementation* _implementation = static_cast<DotPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CALCULATEPOWER__CREATUREOBJECT_);
		method.addObjectParameter(creature);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->calculatePower(creature);
}

bool DotPack::isPoisonDeliveryUnit() {
	DotPackImplementation* _implementation = static_cast<DotPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISPOISONDELIVERYUNIT__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isPoisonDeliveryUnit();
}

bool DotPack::isDiseaseDeliveryUnit() {
	DotPackImplementation* _implementation = static_cast<DotPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISDISEASEDELIVERYUNIT__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isDiseaseDeliveryUnit();
}

float DotPack::getEffectiveness() {
	DotPackImplementation* _implementation = static_cast<DotPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETEFFECTIVENESS__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getEffectiveness();
}

float DotPack::getRange() {
	DotPackImplementation* _implementation = static_cast<DotPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETRANGE__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getRange();
}

float DotPack::getArea() {
	DotPackImplementation* _implementation = static_cast<DotPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETAREA__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getArea();
}

float DotPack::getRangeMod() {
	DotPackImplementation* _implementation = static_cast<DotPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETRANGEMOD__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getRangeMod();
}

float DotPack::getPotency() {
	DotPackImplementation* _implementation = static_cast<DotPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETPOTENCY__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getPotency();
}

unsigned int DotPack::getDuration() {
	DotPackImplementation* _implementation = static_cast<DotPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETDURATION__);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->getDuration();
}

bool DotPack::isArea() {
	DotPackImplementation* _implementation = static_cast<DotPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISAREA__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isArea();
}

unsigned int DotPack::getPool() {
	DotPackImplementation* _implementation = static_cast<DotPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETPOOL__);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->getPool();
}

unsigned int DotPack::getDotType() {
	DotPackImplementation* _implementation = static_cast<DotPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETDOTTYPE__);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->getDotType();
}

DistributedObjectServant* DotPack::_getImplementation() {

	 if (!_updated) _updated = true;
	return _impl;
}

DistributedObjectServant* DotPack::_getImplementationForRead() {
	return _impl;
}

void DotPack::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	DotPackImplementation
 */

DotPackImplementation::DotPackImplementation(DummyConstructorParameter* param) : PharmaceuticalObjectImplementation(param) {
	_initializeImplementation();
}


DotPackImplementation::~DotPackImplementation() {
}


void DotPackImplementation::finalize() {
}

void DotPackImplementation::_initializeImplementation() {
	_setClassHelper(DotPackHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void DotPackImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<DotPack*>(stub);
	PharmaceuticalObjectImplementation::_setStub(stub);
}

DistributedObjectStub* DotPackImplementation::_getStub() {
	return _this.get();
}

DotPackImplementation::operator const DotPack*() {
	return _this.get();
}

void DotPackImplementation::lock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->lock(doLock);
}

void DotPackImplementation::lock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->lock(obj);
}

void DotPackImplementation::rlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->rlock(doLock);
}

void DotPackImplementation::wlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->wlock(doLock);
}

void DotPackImplementation::wlock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->wlock(obj);
}

void DotPackImplementation::unlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->unlock(doLock);
}

void DotPackImplementation::runlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->runlock(doLock);
}

void DotPackImplementation::_serializationHelperMethod() {
	PharmaceuticalObjectImplementation::_serializationHelperMethod();

	_setClassName("DotPack");

}

void DotPackImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(DotPackImplementation::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool DotPackImplementation::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (PharmaceuticalObjectImplementation::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	case 0x75172fd4: //DotPack.effectiveness
		TypeInfo<float >::parseFromBinaryStream(&effectiveness, stream);
		return true;

	case 0xe90328b0: //DotPack.range
		TypeInfo<float >::parseFromBinaryStream(&range, stream);
		return true;

	case 0x3a3ef069: //DotPack.area
		TypeInfo<float >::parseFromBinaryStream(&area, stream);
		return true;

	case 0xad9fc0dc: //DotPack.hasArea
		TypeInfo<bool >::parseFromBinaryStream(&hasArea, stream);
		return true;

	case 0x87b93001: //DotPack.rangeMod
		TypeInfo<float >::parseFromBinaryStream(&rangeMod, stream);
		return true;

	case 0x4d79befc: //DotPack.potency
		TypeInfo<float >::parseFromBinaryStream(&potency, stream);
		return true;

	case 0xed5f30d5: //DotPack.commandToExecute
		TypeInfo<String >::parseFromBinaryStream(&commandToExecute, stream);
		return true;

	case 0xa141914e: //DotPack.duration
		TypeInfo<unsigned int >::parseFromBinaryStream(&duration, stream);
		return true;

	case 0x1fc5ae20: //DotPack.pool
		TypeInfo<unsigned int >::parseFromBinaryStream(&pool, stream);
		return true;

	case 0x50210e17: //DotPack.dotType
		TypeInfo<unsigned int >::parseFromBinaryStream(&dotType, stream);
		return true;

	}

	return false;
}

void DotPackImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = DotPackImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int DotPackImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = PharmaceuticalObjectImplementation::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;
	_nameHashCode = 0x75172fd4; //DotPack.effectiveness
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<float >::toBinaryStream(&effectiveness, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_nameHashCode = 0xe90328b0; //DotPack.range
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<float >::toBinaryStream(&range, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_nameHashCode = 0x3a3ef069; //DotPack.area
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<float >::toBinaryStream(&area, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_nameHashCode = 0xad9fc0dc; //DotPack.hasArea
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<bool >::toBinaryStream(&hasArea, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_nameHashCode = 0x87b93001; //DotPack.rangeMod
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<float >::toBinaryStream(&rangeMod, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_nameHashCode = 0x4d79befc; //DotPack.potency
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<float >::toBinaryStream(&potency, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_nameHashCode = 0xed5f30d5; //DotPack.commandToExecute
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<String >::toBinaryStream(&commandToExecute, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_nameHashCode = 0xa141914e; //DotPack.duration
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<unsigned int >::toBinaryStream(&duration, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_nameHashCode = 0x1fc5ae20; //DotPack.pool
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<unsigned int >::toBinaryStream(&pool, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_nameHashCode = 0x50210e17; //DotPack.dotType
	TypeInfo<uint32>::toBinaryStream(&_nameHashCode, stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<unsigned int >::toBinaryStream(&dotType, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);


	return _count + 10;
}

DotPackImplementation::DotPackImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		area = 0;
	area = 0;
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		range = 0;
	range = 0;
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		rangeMod = 0;
	rangeMod = 0;
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		potency = 0;
	potency = 0;
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		duration = 0;
	duration = 0;
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		pool = 0;
	pool = 0;
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		dotType = 0;
	dotType = 0;
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		effectiveness = 0;
	effectiveness = 0;
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		hasArea = false;
	hasArea = false;
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		setLoggingName("DotPack");
	setLoggingName("DotPack");
}

void DotPackImplementation::updateCraftingValues(CraftingValues* values, bool firstUpdate) {
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		effectiveness = values.getCurrentValue("power");
	effectiveness = values->getCurrentValue("power");
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		super.medicineUseRequired = values.getCurrentValue("skillmodmin");
	PharmaceuticalObjectImplementation::medicineUseRequired = values->getCurrentValue("skillmodmin");
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		setUseCount(values.getCurrentValue("charges"));
	setUseCount(values->getCurrentValue("charges"));
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		range = values.getCurrentValue("range");
	range = values->getCurrentValue("range");
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		area = values.getCurrentValue("area");
	area = values->getCurrentValue("area");
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		potency = values.getCurrentValue("potency");
	potency = values->getCurrentValue("potency");
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		duration = values.getCurrentValue("duration");
	duration = values->getCurrentValue("duration");
}

void DotPackImplementation::loadTemplateData(SharedObjectTemplate* templateData) {
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		super.loadTemplateData(templateData);
	PharmaceuticalObjectImplementation::loadTemplateData(templateData);
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		DotPackTemplate 
	if (!templateData->isDotPackTemplate())	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  			return;
	return;
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		DotPackTemplate stimPackTemplate = (DotPackTemplate) templateData;
	DotPackTemplate* stimPackTemplate = (DotPackTemplate*) templateData;
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		effectiveness = stimPackTemplate.getEffectiveness();
	effectiveness = stimPackTemplate->getEffectiveness();
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		super.medicineUseRequired = stimPackTemplate.getMedicineUse();
	PharmaceuticalObjectImplementation::medicineUseRequired = stimPackTemplate->getMedicineUse();
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		duration = stimPackTemplate.getDuration();
	duration = stimPackTemplate->getDuration();
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		area = stimPackTemplate.getArea();
	area = stimPackTemplate->getArea();
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		hasArea = stimPackTemplate.isArea();
	hasArea = stimPackTemplate->isArea();
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		range = stimPackTemplate.getRange();
	range = stimPackTemplate->getRange();
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		rangeMod = stimPackTemplate.getRangeMod();
	rangeMod = stimPackTemplate->getRangeMod();
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		pool = stimPackTemplate.getPool();
	pool = stimPackTemplate->getPool();
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		dotType = stimPackTemplate.getDotType();
	dotType = stimPackTemplate->getDotType();
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		potency = stimPackTemplate.getPotency();
	potency = stimPackTemplate->getPotency();
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		commandToExecute = stimPackTemplate.getCommandToExecute();
	commandToExecute = stimPackTemplate->getCommandToExecute();
}

void DotPackImplementation::fillAttributeList(AttributeListMessage* msg, CreatureObject* object) {
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		super.fillAttributeList(msg, object);
	PharmaceuticalObjectImplementation::fillAttributeList(msg, object);
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		msg.insertAttribute("examine_dot_attribute", CreatureAttribute.getName(pool, true));
	msg->insertAttribute("examine_dot_attribute", CreatureAttribute::getName(pool, true));
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		msg.insertAttribute("examine_dot_apply_power", Math.getPrecision(effectiveness, 0));
	msg->insertAttribute("examine_dot_apply_power", Math::getPrecision(effectiveness, 0));
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		}
	if (isPoisonDeliveryUnit()){
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  			msg.insertAttribute("examine_dot_apply", "Poison");
	msg->insertAttribute("examine_dot_apply", "Poison");
}

	else {
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  			msg.insertAttribute("examine_dot_apply", "Diseased");
	msg->insertAttribute("examine_dot_apply", "Diseased");
}
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		msg.insertAttribute("examine_dot_potency", Math.getPrecision(potency, 0));
	msg->insertAttribute("examine_dot_potency", Math::getPrecision(potency, 0));
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		msg.insertAttribute("examine_heal_range", Math.getPrecision(range, 0));
	msg->insertAttribute("examine_heal_range", Math::getPrecision(range, 0));
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		}
	if (isArea()){
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  			msg.insertAttribute("examine_heal_area", Math.getPrecision(area, 0));
	msg->insertAttribute("examine_heal_area", Math::getPrecision(area, 0));
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  			msg.insertAttribute("duration", Math.getPrecision(duration, 0));
	msg->insertAttribute("duration", Math::getPrecision(duration, 0));
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  			msg.insertAttribute("combat_healing_ability", super.getMedicineUseRequired());
	msg->insertAttribute("combat_healing_ability", PharmaceuticalObjectImplementation::getMedicineUseRequired());
}

	else {
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  			msg.insertAttribute("duration", Math.getPrecision(duration, 0));
	msg->insertAttribute("duration", Math::getPrecision(duration, 0));
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  			msg.insertAttribute("combat_healing_ability", super.getMedicineUseRequired());
	msg->insertAttribute("combat_healing_ability", PharmaceuticalObjectImplementation::getMedicineUseRequired());
}
}

int DotPackImplementation::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		if 
	if (!isASubChildOf(player))	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  			return 0;
	return 0;
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		if 
	if (selectedID != 20)	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  			return 1;
	return 1;
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		}
	if (player->getSkillMod("combat_healing_ability") < PharmaceuticalObjectImplementation::medicineUseRequired){
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  			player.sendSystemMessage("@error_message:insufficient_skill");
	player->sendSystemMessage("@error_message:insufficient_skill");
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  			return 0;
	return 0;
}

	else {
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  			string command = commandToExecute + " ";
	String command = commandToExecute + " ";
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  			command = command + String.valueOf(super.getObjectID());
	command = command + String::valueOf(PharmaceuticalObjectImplementation::getObjectID());
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  			player.sendExecuteConsoleCommand(command);
	player->sendExecuteConsoleCommand(command);
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  			return 0;
	return 0;
}
}

int DotPackImplementation::calculatePower(CreatureObject* creature) {
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		float modSkill = (float) creature.getSkillMod("combat_medic_effectiveness");
	float modSkill = (float) creature->getSkillMod("combat_medic_effectiveness");
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		return ((100 + modSkill) / 100 * effectiveness);
	return ((100 + modSkill) / 100 * effectiveness);
}

bool DotPackImplementation::isPoisonDeliveryUnit() {
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		return dotType == CreatureState.POISONED;
	return dotType == CreatureState::POISONED;
}

bool DotPackImplementation::isDiseaseDeliveryUnit() {
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		return dotType == CreatureState.DISEASED;
	return dotType == CreatureState::DISEASED;
}

float DotPackImplementation::getEffectiveness() {
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		return effectiveness;
	return effectiveness;
}

float DotPackImplementation::getRange() {
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		return range;
	return range;
}

float DotPackImplementation::getArea() {
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		return area;
	return area;
}

float DotPackImplementation::getRangeMod() {
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		return rangeMod;
	return rangeMod;
}

float DotPackImplementation::getPotency() {
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		return potency;
	return potency;
}

unsigned int DotPackImplementation::getDuration() {
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		return duration;
	return duration;
}

bool DotPackImplementation::isArea() {
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		return hasArea;
	return hasArea;
}

unsigned int DotPackImplementation::getPool() {
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		return pool;
	return pool;
}

unsigned int DotPackImplementation::getDotType() {
	// server/zone/objects/tangible/pharmaceutical/DotPack.idl():  		return dotType;
	return dotType;
}

/*
 *	DotPackAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


DotPackAdapter::DotPackAdapter(DotPack* obj) : PharmaceuticalObjectAdapter(obj) {
}

void DotPackAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_:
		{
			resp->insertSignedInt(handleObjectMenuSelect(static_cast<CreatureObject*>(inv->getObjectParameter()), inv->getByteParameter()));
		}
		break;
	case RPC_CALCULATEPOWER__CREATUREOBJECT_:
		{
			resp->insertSignedInt(calculatePower(static_cast<CreatureObject*>(inv->getObjectParameter())));
		}
		break;
	case RPC_ISPOISONDELIVERYUNIT__:
		{
			resp->insertBoolean(isPoisonDeliveryUnit());
		}
		break;
	case RPC_ISDISEASEDELIVERYUNIT__:
		{
			resp->insertBoolean(isDiseaseDeliveryUnit());
		}
		break;
	case RPC_GETEFFECTIVENESS__:
		{
			resp->insertFloat(getEffectiveness());
		}
		break;
	case RPC_GETRANGE__:
		{
			resp->insertFloat(getRange());
		}
		break;
	case RPC_GETAREA__:
		{
			resp->insertFloat(getArea());
		}
		break;
	case RPC_GETRANGEMOD__:
		{
			resp->insertFloat(getRangeMod());
		}
		break;
	case RPC_GETPOTENCY__:
		{
			resp->insertFloat(getPotency());
		}
		break;
	case RPC_GETDURATION__:
		{
			resp->insertInt(getDuration());
		}
		break;
	case RPC_ISAREA__:
		{
			resp->insertBoolean(isArea());
		}
		break;
	case RPC_GETPOOL__:
		{
			resp->insertInt(getPool());
		}
		break;
	case RPC_GETDOTTYPE__:
		{
			resp->insertInt(getDotType());
		}
		break;
	default:
		throw Exception("Method does not exists");
	}
}

int DotPackAdapter::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	return (static_cast<DotPack*>(stub))->handleObjectMenuSelect(player, selectedID);
}

int DotPackAdapter::calculatePower(CreatureObject* creature) {
	return (static_cast<DotPack*>(stub))->calculatePower(creature);
}

bool DotPackAdapter::isPoisonDeliveryUnit() {
	return (static_cast<DotPack*>(stub))->isPoisonDeliveryUnit();
}

bool DotPackAdapter::isDiseaseDeliveryUnit() {
	return (static_cast<DotPack*>(stub))->isDiseaseDeliveryUnit();
}

float DotPackAdapter::getEffectiveness() {
	return (static_cast<DotPack*>(stub))->getEffectiveness();
}

float DotPackAdapter::getRange() {
	return (static_cast<DotPack*>(stub))->getRange();
}

float DotPackAdapter::getArea() {
	return (static_cast<DotPack*>(stub))->getArea();
}

float DotPackAdapter::getRangeMod() {
	return (static_cast<DotPack*>(stub))->getRangeMod();
}

float DotPackAdapter::getPotency() {
	return (static_cast<DotPack*>(stub))->getPotency();
}

unsigned int DotPackAdapter::getDuration() {
	return (static_cast<DotPack*>(stub))->getDuration();
}

bool DotPackAdapter::isArea() {
	return (static_cast<DotPack*>(stub))->isArea();
}

unsigned int DotPackAdapter::getPool() {
	return (static_cast<DotPack*>(stub))->getPool();
}

unsigned int DotPackAdapter::getDotType() {
	return (static_cast<DotPack*>(stub))->getDotType();
}

/*
 *	DotPackHelper
 */

DotPackHelper* DotPackHelper::staticInitializer = DotPackHelper::instance();

DotPackHelper::DotPackHelper() {
	className = "DotPack";

	Core::getObjectBroker()->registerClass(className, this);
}

void DotPackHelper::finalizeHelper() {
	DotPackHelper::finalize();
}

DistributedObject* DotPackHelper::instantiateObject() {
	return new DotPack(DummyConstructorParameter::instance());
}

DistributedObjectServant* DotPackHelper::instantiateServant() {
	return new DotPackImplementation();
}

DistributedObjectAdapter* DotPackHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new DotPackAdapter(static_cast<DotPack*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

