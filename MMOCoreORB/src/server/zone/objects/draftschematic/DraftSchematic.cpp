/*
 *	server/zone/objects/draftschematic/DraftSchematic.cpp generated by engine3 IDL compiler 0.60
 */

#include "DraftSchematic.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/area/ActiveArea.h"

/*
 *	DraftSchematicStub
 */

DraftSchematic::DraftSchematic() : IntangibleObject(DummyConstructorParameter::instance()) {
	DraftSchematicImplementation* _implementation = new DraftSchematicImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

DraftSchematic::DraftSchematic(DummyConstructorParameter* param) : IntangibleObject(param) {
}

DraftSchematic::~DraftSchematic() {
}


void DraftSchematic::initializeTransientMembers() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

void DraftSchematic::loadTemplateData(SharedObjectTemplate* templateData) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->loadTemplateData(templateData);
}

void DraftSchematic::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillAttributeList(msg, object);
}

void DraftSchematic::sendBaselinesTo(SceneObject* player) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendBaselinesTo(player);
}

void DraftSchematic::sendDraftSlotsTo(PlayerCreature* player) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendDraftSlotsTo(player);
}

void DraftSchematic::sendResourceWeightsTo(PlayerCreature* player) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendResourceWeightsTo(player);
}

SceneObject* DraftSchematic::createManufactureSchematic(SceneObject* craftingTool) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addObjectParameter(craftingTool);

		return (SceneObject*) method.executeWithObjectReturn();
	} else
		return _implementation->createManufactureSchematic(craftingTool);
}

void DraftSchematic::setSchematicID(unsigned int id) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addUnsignedIntParameter(id);

		method.executeWithVoidReturn();
	} else
		_implementation->setSchematicID(id);
}

unsigned int DraftSchematic::getSchematicID() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->getSchematicID();
}

int DraftSchematic::getDraftSlotCount() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getDraftSlotCount();
}

bool DraftSchematic::isValidDraftSchematic() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isValidDraftSchematic();
}

DraftSlot* DraftSchematic::getDraftSlot(int i) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getDraftSlot(i);
}

int DraftSchematic::getResourceWeightCount() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getResourceWeightCount();
}

ResourceWeight* DraftSchematic::getResourceWeight(int i) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getResourceWeight(i);
}

float DraftSchematic::getComplexity() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getComplexity();
}

unsigned int DraftSchematic::getToolTab() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->getToolTab();
}

float DraftSchematic::getSize() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getSize();
}

String DraftSchematic::getXpType() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);

		method.executeWithAsciiReturn(_return_getXpType);
		return _return_getXpType;
	} else
		return _implementation->getXpType();
}

int DraftSchematic::getXpAmount() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getXpAmount();
}

String DraftSchematic::getAssemblySkill() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);

		method.executeWithAsciiReturn(_return_getAssemblySkill);
		return _return_getAssemblySkill;
	} else
		return _implementation->getAssemblySkill();
}

String DraftSchematic::getExperimentationSkill() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);

		method.executeWithAsciiReturn(_return_getExperimentationSkill);
		return _return_getExperimentationSkill;
	} else
		return _implementation->getExperimentationSkill();
}

String DraftSchematic::getCustomizationSkill() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);

		method.executeWithAsciiReturn(_return_getCustomizationSkill);
		return _return_getCustomizationSkill;
	} else
		return _implementation->getCustomizationSkill();
}

Vector<byte>* DraftSchematic::getCustomizationOptions() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getCustomizationOptions();
}

Vector<String>* DraftSchematic::getCustomizationStringNames() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getCustomizationStringNames();
}

Vector<byte>* DraftSchematic::getCustomizationDefaultValues() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getCustomizationDefaultValues();
}

String DraftSchematic::getCustomName() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);

		method.executeWithAsciiReturn(_return_getCustomName);
		return _return_getCustomName;
	} else
		return _implementation->getCustomName();
}

unsigned int DraftSchematic::getTanoCRC() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 25);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->getTanoCRC();
}

String DraftSchematic::getGroupName() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 26);

		method.executeWithAsciiReturn(_return_getGroupName);
		return _return_getGroupName;
	} else
		return _implementation->getGroupName();
}

int DraftSchematic::getUseCount() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 27);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getUseCount();
}

void DraftSchematic::setUseCount(int count) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 28);
		method.addSignedIntParameter(count);

		method.executeWithVoidReturn();
	} else
		_implementation->setUseCount(count);
}

void DraftSchematic::decreaseUseCount(int count) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 29);
		method.addSignedIntParameter(count);

		method.executeWithVoidReturn();
	} else
		_implementation->decreaseUseCount(count);
}

void DraftSchematic::increaseUseCount(int count) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 30);
		method.addSignedIntParameter(count);

		method.executeWithVoidReturn();
	} else
		_implementation->increaseUseCount(count);
}

DistributedObjectServant* DraftSchematic::_getImplementation() {

	_updated = true;
	return _impl;
}

void DraftSchematic::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	DraftSchematicImplementation
 */

DraftSchematicImplementation::DraftSchematicImplementation(DummyConstructorParameter* param) : IntangibleObjectImplementation(param) {
	_initializeImplementation();
}


DraftSchematicImplementation::~DraftSchematicImplementation() {
}


void DraftSchematicImplementation::finalize() {
}

void DraftSchematicImplementation::_initializeImplementation() {
	_setClassHelper(DraftSchematicHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void DraftSchematicImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (DraftSchematic*) stub;
	IntangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* DraftSchematicImplementation::_getStub() {
	return _this;
}

DraftSchematicImplementation::operator const DraftSchematic*() {
	return _this;
}

void DraftSchematicImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void DraftSchematicImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void DraftSchematicImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void DraftSchematicImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void DraftSchematicImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void DraftSchematicImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void DraftSchematicImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void DraftSchematicImplementation::_serializationHelperMethod() {
	IntangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("DraftSchematic");

}

void DraftSchematicImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(DraftSchematicImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool DraftSchematicImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (IntangibleObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "schematicID") {
		TypeInfo<unsigned int >::parseFromBinaryStream(&schematicID, stream);
		return true;
	}

	if (_name == "useCount") {
		TypeInfo<int >::parseFromBinaryStream(&useCount, stream);
		return true;
	}


	return false;
}

void DraftSchematicImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = DraftSchematicImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int DraftSchematicImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "schematicID";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<unsigned int >::toBinaryStream(&schematicID, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "useCount";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&useCount, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 2 + IntangibleObjectImplementation::writeObjectMembers(stream);
}

DraftSchematicImplementation::DraftSchematicImplementation() {
	_initializeImplementation();
	// server/zone/objects/draftschematic/DraftSchematic.idl(70):  		schematicTemplate = null;
	schematicTemplate = NULL;
	// server/zone/objects/draftschematic/DraftSchematic.idl(71):  		useCount = 0;
	useCount = 0;
	// server/zone/objects/draftschematic/DraftSchematic.idl(72):  		schematicID = 0;
	schematicID = 0;
	// server/zone/objects/draftschematic/DraftSchematic.idl(74):  		Logger.setLoggingName("DraftSchematic");
	Logger::setLoggingName("DraftSchematic");
}

void DraftSchematicImplementation::setSchematicID(unsigned int id) {
	// server/zone/objects/draftschematic/DraftSchematic.idl(132):  		schematicID = id;
	schematicID = id;
}

unsigned int DraftSchematicImplementation::getSchematicID() {
	// server/zone/objects/draftschematic/DraftSchematic.idl(140):  		return schematicID;
	return schematicID;
}

bool DraftSchematicImplementation::isValidDraftSchematic() {
	// server/zone/objects/draftschematic/DraftSchematic.idl(146):  		return schematicTemplate != null;
	return schematicTemplate != NULL;
}

int DraftSchematicImplementation::getUseCount() {
	// server/zone/objects/draftschematic/DraftSchematic.idl(217):  		return useCount;
	return useCount;
}

void DraftSchematicImplementation::setUseCount(int count) {
	// server/zone/objects/draftschematic/DraftSchematic.idl(221):  		useCount = count;
	useCount = count;
}

void DraftSchematicImplementation::decreaseUseCount(int count) {
	// server/zone/objects/draftschematic/DraftSchematic.idl(225):  		setUseCount(useCount - 1);
	setUseCount(useCount - 1);
}

void DraftSchematicImplementation::increaseUseCount(int count) {
	// server/zone/objects/draftschematic/DraftSchematic.idl(229):  		setUseCount(useCount + count);
	setUseCount(useCount + count);
}

/*
 *	DraftSchematicAdapter
 */

DraftSchematicAdapter::DraftSchematicAdapter(DraftSchematicImplementation* obj) : IntangibleObjectAdapter(obj) {
}

Packet* DraftSchematicAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializeTransientMembers();
		break;
	case 7:
		sendBaselinesTo((SceneObject*) inv->getObjectParameter());
		break;
	case 8:
		sendDraftSlotsTo((PlayerCreature*) inv->getObjectParameter());
		break;
	case 9:
		sendResourceWeightsTo((PlayerCreature*) inv->getObjectParameter());
		break;
	case 10:
		resp->insertLong(createManufactureSchematic((SceneObject*) inv->getObjectParameter())->_getObjectID());
		break;
	case 11:
		setSchematicID(inv->getUnsignedIntParameter());
		break;
	case 12:
		resp->insertInt(getSchematicID());
		break;
	case 13:
		resp->insertSignedInt(getDraftSlotCount());
		break;
	case 14:
		resp->insertBoolean(isValidDraftSchematic());
		break;
	case 15:
		resp->insertSignedInt(getResourceWeightCount());
		break;
	case 16:
		resp->insertFloat(getComplexity());
		break;
	case 17:
		resp->insertInt(getToolTab());
		break;
	case 18:
		resp->insertFloat(getSize());
		break;
	case 19:
		resp->insertAscii(getXpType());
		break;
	case 20:
		resp->insertSignedInt(getXpAmount());
		break;
	case 21:
		resp->insertAscii(getAssemblySkill());
		break;
	case 22:
		resp->insertAscii(getExperimentationSkill());
		break;
	case 23:
		resp->insertAscii(getCustomizationSkill());
		break;
	case 24:
		resp->insertAscii(getCustomName());
		break;
	case 25:
		resp->insertInt(getTanoCRC());
		break;
	case 26:
		resp->insertAscii(getGroupName());
		break;
	case 27:
		resp->insertSignedInt(getUseCount());
		break;
	case 28:
		setUseCount(inv->getSignedIntParameter());
		break;
	case 29:
		decreaseUseCount(inv->getSignedIntParameter());
		break;
	case 30:
		increaseUseCount(inv->getSignedIntParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void DraftSchematicAdapter::initializeTransientMembers() {
	((DraftSchematicImplementation*) impl)->initializeTransientMembers();
}

void DraftSchematicAdapter::sendBaselinesTo(SceneObject* player) {
	((DraftSchematicImplementation*) impl)->sendBaselinesTo(player);
}

void DraftSchematicAdapter::sendDraftSlotsTo(PlayerCreature* player) {
	((DraftSchematicImplementation*) impl)->sendDraftSlotsTo(player);
}

void DraftSchematicAdapter::sendResourceWeightsTo(PlayerCreature* player) {
	((DraftSchematicImplementation*) impl)->sendResourceWeightsTo(player);
}

SceneObject* DraftSchematicAdapter::createManufactureSchematic(SceneObject* craftingTool) {
	return ((DraftSchematicImplementation*) impl)->createManufactureSchematic(craftingTool);
}

void DraftSchematicAdapter::setSchematicID(unsigned int id) {
	((DraftSchematicImplementation*) impl)->setSchematicID(id);
}

unsigned int DraftSchematicAdapter::getSchematicID() {
	return ((DraftSchematicImplementation*) impl)->getSchematicID();
}

int DraftSchematicAdapter::getDraftSlotCount() {
	return ((DraftSchematicImplementation*) impl)->getDraftSlotCount();
}

bool DraftSchematicAdapter::isValidDraftSchematic() {
	return ((DraftSchematicImplementation*) impl)->isValidDraftSchematic();
}

int DraftSchematicAdapter::getResourceWeightCount() {
	return ((DraftSchematicImplementation*) impl)->getResourceWeightCount();
}

float DraftSchematicAdapter::getComplexity() {
	return ((DraftSchematicImplementation*) impl)->getComplexity();
}

unsigned int DraftSchematicAdapter::getToolTab() {
	return ((DraftSchematicImplementation*) impl)->getToolTab();
}

float DraftSchematicAdapter::getSize() {
	return ((DraftSchematicImplementation*) impl)->getSize();
}

String DraftSchematicAdapter::getXpType() {
	return ((DraftSchematicImplementation*) impl)->getXpType();
}

int DraftSchematicAdapter::getXpAmount() {
	return ((DraftSchematicImplementation*) impl)->getXpAmount();
}

String DraftSchematicAdapter::getAssemblySkill() {
	return ((DraftSchematicImplementation*) impl)->getAssemblySkill();
}

String DraftSchematicAdapter::getExperimentationSkill() {
	return ((DraftSchematicImplementation*) impl)->getExperimentationSkill();
}

String DraftSchematicAdapter::getCustomizationSkill() {
	return ((DraftSchematicImplementation*) impl)->getCustomizationSkill();
}

String DraftSchematicAdapter::getCustomName() {
	return ((DraftSchematicImplementation*) impl)->getCustomName();
}

unsigned int DraftSchematicAdapter::getTanoCRC() {
	return ((DraftSchematicImplementation*) impl)->getTanoCRC();
}

String DraftSchematicAdapter::getGroupName() {
	return ((DraftSchematicImplementation*) impl)->getGroupName();
}

int DraftSchematicAdapter::getUseCount() {
	return ((DraftSchematicImplementation*) impl)->getUseCount();
}

void DraftSchematicAdapter::setUseCount(int count) {
	((DraftSchematicImplementation*) impl)->setUseCount(count);
}

void DraftSchematicAdapter::decreaseUseCount(int count) {
	((DraftSchematicImplementation*) impl)->decreaseUseCount(count);
}

void DraftSchematicAdapter::increaseUseCount(int count) {
	((DraftSchematicImplementation*) impl)->increaseUseCount(count);
}

/*
 *	DraftSchematicHelper
 */

DraftSchematicHelper* DraftSchematicHelper::staticInitializer = DraftSchematicHelper::instance();

DraftSchematicHelper::DraftSchematicHelper() {
	className = "DraftSchematic";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void DraftSchematicHelper::finalizeHelper() {
	DraftSchematicHelper::finalize();
}

DistributedObject* DraftSchematicHelper::instantiateObject() {
	return new DraftSchematic(DummyConstructorParameter::instance());
}

DistributedObjectServant* DraftSchematicHelper::instantiateServant() {
	return new DraftSchematicImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* DraftSchematicHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new DraftSchematicAdapter((DraftSchematicImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}
