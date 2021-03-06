/*
 *	server/zone/managers/loot/LootManager.cpp generated by engine3 IDL compiler 0.60
 */

#include "LootManager.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/creature/AiAgent.h"

#include "server/zone/managers/crafting/CraftingManager.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/tangible/TangibleObject.h"

/*
 *	LootManagerStub
 */

enum {RPC_INITIALIZE__ = 6,RPC_GETRANDOMLOOTABLEMOD__,RPC_CALCULATELOOTCREDITS__INT_,RPC_CREATELOOT__SCENEOBJECT_AIAGENT_,RPC_CREATELOOT__SCENEOBJECT_STRING_INT_};

LootManager::LootManager(CraftingManager* craftman, ObjectManager* objMan, ZoneServer* server) : ManagedService(DummyConstructorParameter::instance()) {
	LootManagerImplementation* _implementation = new LootManagerImplementation(craftman, objMan, server);
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("LootManager");
}

LootManager::LootManager(DummyConstructorParameter* param) : ManagedService(param) {
	_setClassName("LootManager");
}

LootManager::~LootManager() {
}



void LootManager::initialize() {
	LootManagerImplementation* _implementation = static_cast<LootManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZE__);

		method.executeWithVoidReturn();
	} else
		_implementation->initialize();
}

String LootManager::getRandomLootableMod() {
	LootManagerImplementation* _implementation = static_cast<LootManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETRANDOMLOOTABLEMOD__);

		String _return_getRandomLootableMod;
		method.executeWithAsciiReturn(_return_getRandomLootableMod);
		return _return_getRandomLootableMod;
	} else
		return _implementation->getRandomLootableMod();
}

TangibleObject* LootManager::createLootObject(LootItemTemplate* templateObject, int level) {
	LootManagerImplementation* _implementation = static_cast<LootManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->createLootObject(templateObject, level);
}

int LootManager::calculateLootCredits(int level) {
	LootManagerImplementation* _implementation = static_cast<LootManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CALCULATELOOTCREDITS__INT_);
		method.addSignedIntParameter(level);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->calculateLootCredits(level);
}

bool LootManager::createLoot(SceneObject* container, AiAgent* creature) {
	LootManagerImplementation* _implementation = static_cast<LootManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CREATELOOT__SCENEOBJECT_AIAGENT_);
		method.addObjectParameter(container);
		method.addObjectParameter(creature);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->createLoot(container, creature);
}

bool LootManager::createLootFromCollection(SceneObject* container, LootGroupCollection* collection, int level) {
	LootManagerImplementation* _implementation = static_cast<LootManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->createLootFromCollection(container, collection, level);
}

bool LootManager::createLoot(SceneObject* container, const String& lootGroup, int level) {
	LootManagerImplementation* _implementation = static_cast<LootManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CREATELOOT__SCENEOBJECT_STRING_INT_);
		method.addObjectParameter(container);
		method.addAsciiParameter(lootGroup);
		method.addSignedIntParameter(level);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->createLoot(container, lootGroup, level);
}

DistributedObjectServant* LootManager::_getImplementation() {

	 if (!_updated) _updated = true;
	return _impl;
}

DistributedObjectServant* LootManager::_getImplementationForRead() {
	return _impl;
}

void LootManager::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	LootManagerImplementation
 */

LootManagerImplementation::LootManagerImplementation(DummyConstructorParameter* param) : ManagedServiceImplementation(param) {
	_initializeImplementation();
}


LootManagerImplementation::~LootManagerImplementation() {
}


void LootManagerImplementation::finalize() {
}

void LootManagerImplementation::_initializeImplementation() {
	_setClassHelper(LootManagerHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void LootManagerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<LootManager*>(stub);
	ManagedServiceImplementation::_setStub(stub);
}

DistributedObjectStub* LootManagerImplementation::_getStub() {
	return _this.get();
}

LootManagerImplementation::operator const LootManager*() {
	return _this.get();
}

void LootManagerImplementation::lock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->lock(doLock);
}

void LootManagerImplementation::lock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->lock(obj);
}

void LootManagerImplementation::rlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->rlock(doLock);
}

void LootManagerImplementation::wlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->wlock(doLock);
}

void LootManagerImplementation::wlock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->wlock(obj);
}

void LootManagerImplementation::unlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->unlock(doLock);
}

void LootManagerImplementation::runlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->runlock(doLock);
}

void LootManagerImplementation::_serializationHelperMethod() {
	ManagedServiceImplementation::_serializationHelperMethod();

	_setClassName("LootManager");

}

void LootManagerImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		uint32 _nameHashCode;
		TypeInfo<uint32>::parseFromBinaryStream(&_nameHashCode, stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(LootManagerImplementation::readObjectMember(stream, _nameHashCode)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool LootManagerImplementation::readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode) {
	if (ManagedServiceImplementation::readObjectMember(stream, nameHashCode))
		return true;

	switch(nameHashCode) {
	}

	return false;
}

void LootManagerImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = LootManagerImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int LootManagerImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ManagedServiceImplementation::writeObjectMembers(stream);

	uint32 _nameHashCode;
	int _offset;
	uint32 _totalSize;

	return _count + 0;
}

LootManagerImplementation::LootManagerImplementation(CraftingManager* craftman, ObjectManager* objMan, ZoneServer* server) {
	_initializeImplementation();
	// server/zone/managers/loot/LootManager.idl():  		craftingManager = craftman;
	craftingManager = craftman;
	// server/zone/managers/loot/LootManager.idl():  		objectManager = objMan;
	objectManager = objMan;
	// server/zone/managers/loot/LootManager.idl():  		zoneServer = server;
	zoneServer = server;
	// server/zone/managers/loot/LootManager.idl():  		lootGroupMap = null;
	lootGroupMap = NULL;
	// server/zone/managers/loot/LootManager.idl():  		lootableMods.setNoDuplicateInsertPlan();
	(&lootableMods)->setNoDuplicateInsertPlan();
	// server/zone/managers/loot/LootManager.idl():  		lootableDots.setNoDuplicateInsertPlan();
	(&lootableDots)->setNoDuplicateInsertPlan();
	// server/zone/managers/loot/LootManager.idl():  		exceptionalChance = 0.0;
	exceptionalChance = 0.0;
	// server/zone/managers/loot/LootManager.idl():  		exceptionalModifier = 0.0;
	exceptionalModifier = 0.0;
	// server/zone/managers/loot/LootManager.idl():  		legendaryChance = 0.0;
	legendaryChance = 0.0;
	// server/zone/managers/loot/LootManager.idl():  		legendaryModifier = 0.0;
	legendaryModifier = 0.0;
	// server/zone/managers/loot/LootManager.idl():  		dotChance = 0.0;
	dotChance = 0.0;
	// server/zone/managers/loot/LootManager.idl():  		Logger.setLoggingName("LootManager");
	Logger::setLoggingName("LootManager");
	// server/zone/managers/loot/LootManager.idl():  		Logger.setLogging(true);
	Logger::setLogging(true);
	// server/zone/managers/loot/LootManager.idl():  		Logger.setGlobalLogging(true);
	Logger::setGlobalLogging(true);
}

String LootManagerImplementation::getRandomLootableMod() {
	// server/zone/managers/loot/LootManager.idl():  		return lootableMods.get(System.random(lootableMods.size() - 1));
	return (&lootableMods)->get(System::random((&lootableMods)->size() - 1));
}

/*
 *	LootManagerAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


LootManagerAdapter::LootManagerAdapter(LootManager* obj) : ManagedServiceAdapter(obj) {
}

void LootManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_INITIALIZE__:
		{
			initialize();
		}
		break;
	case RPC_GETRANDOMLOOTABLEMOD__:
		{
			resp->insertAscii(getRandomLootableMod());
		}
		break;
	case RPC_CALCULATELOOTCREDITS__INT_:
		{
			resp->insertSignedInt(calculateLootCredits(inv->getSignedIntParameter()));
		}
		break;
	case RPC_CREATELOOT__SCENEOBJECT_AIAGENT_:
		{
			resp->insertBoolean(createLoot(static_cast<SceneObject*>(inv->getObjectParameter()), static_cast<AiAgent*>(inv->getObjectParameter())));
		}
		break;
	case RPC_CREATELOOT__SCENEOBJECT_STRING_INT_:
		{
			String lootGroup; 
			resp->insertBoolean(createLoot(static_cast<SceneObject*>(inv->getObjectParameter()), inv->getAsciiParameter(lootGroup), inv->getSignedIntParameter()));
		}
		break;
	default:
		throw Exception("Method does not exists");
	}
}

void LootManagerAdapter::initialize() {
	(static_cast<LootManager*>(stub))->initialize();
}

String LootManagerAdapter::getRandomLootableMod() {
	return (static_cast<LootManager*>(stub))->getRandomLootableMod();
}

int LootManagerAdapter::calculateLootCredits(int level) {
	return (static_cast<LootManager*>(stub))->calculateLootCredits(level);
}

bool LootManagerAdapter::createLoot(SceneObject* container, AiAgent* creature) {
	return (static_cast<LootManager*>(stub))->createLoot(container, creature);
}

bool LootManagerAdapter::createLoot(SceneObject* container, const String& lootGroup, int level) {
	return (static_cast<LootManager*>(stub))->createLoot(container, lootGroup, level);
}

/*
 *	LootManagerHelper
 */

LootManagerHelper* LootManagerHelper::staticInitializer = LootManagerHelper::instance();

LootManagerHelper::LootManagerHelper() {
	className = "LootManager";

	Core::getObjectBroker()->registerClass(className, this);
}

void LootManagerHelper::finalizeHelper() {
	LootManagerHelper::finalize();
}

DistributedObject* LootManagerHelper::instantiateObject() {
	return new LootManager(DummyConstructorParameter::instance());
}

DistributedObjectServant* LootManagerHelper::instantiateServant() {
	return new LootManagerImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* LootManagerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new LootManagerAdapter(static_cast<LootManager*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

