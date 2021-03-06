/*
 *	server/zone/managers/loot/LootManager.h generated by engine3 IDL compiler 0.60
 */

#ifndef LOOTMANAGER_H_
#define LOOTMANAGER_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObject;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class AiAgent;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace managers {
namespace crafting {

class CraftingManager;

} // namespace crafting
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::crafting;

namespace server {
namespace zone {
namespace managers {
namespace object {

class ObjectManager;

} // namespace object
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::object;

namespace server {
namespace zone {

class ZoneServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class TangibleObject;

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

#include "server/zone/managers/loot/LootGroupMap.h"

#include "server/zone/managers/loot/lootgroup/LootGroupCollection.h"

#include "server/zone/templates/LootItemTemplate.h"

#include "server/zone/objects/manufactureschematic/craftingvalues/CraftingValues.h"

#include "server/zone/objects/tangible/weapon/WeaponObject.h"

#include "system/util/VectorMap.h"

#include "engine/core/ManagedService.h"

#include "engine/lua/Lua.h"

namespace server {
namespace zone {
namespace managers {
namespace loot {

class LootManager : public ManagedService {
public:
	LootManager(CraftingManager* craftman, ObjectManager* objMan, ZoneServer* server);

	void initialize();

	String getRandomLootableMod();

	TangibleObject* createLootObject(LootItemTemplate* templateObject, int level);

	int calculateLootCredits(int level);

	bool createLoot(SceneObject* container, AiAgent* creature);

	bool createLootFromCollection(SceneObject* container, LootGroupCollection* collection, int level);

	bool createLoot(SceneObject* container, const String& lootGroup, int level = -1);

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	LootManager(DummyConstructorParameter* param);

	virtual ~LootManager();

	friend class LootManagerHelper;
};

} // namespace loot
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::loot;

namespace server {
namespace zone {
namespace managers {
namespace loot {

class LootManagerImplementation : public ManagedServiceImplementation, public Logger {
	ManagedReference<CraftingManager* > craftingManager;

	Reference<Lua* > lua;

	ManagedReference<ZoneServer* > zoneServer;

	Reference<ObjectManager* > objectManager;

	Reference<LootGroupMap* > lootGroupMap;

	float exceptionalChance;

	float exceptionalModifier;

	float legendaryChance;

	float legendaryModifier;

	float dotChance;

	VectorMap<unsigned long long, unsigned long long> dotGatesPoison;

	VectorMap<unsigned long long, unsigned long long> dotGatesDisease;

	VectorMap<unsigned long long, unsigned long long> dotGatesFire;

	SortedVector<String> lootableMods;

	SortedVector<String> lootableDots;

public:
	LootManagerImplementation(CraftingManager* craftman, ObjectManager* objMan, ZoneServer* server);

	LootManagerImplementation(DummyConstructorParameter* param);

	void initialize();

private:
	bool loadConfigFile();

	bool loadConfigData();

	void loadDefaultConfig();

public:
	String getRandomLootableMod();

private:
	void setInitialObjectStats(LootItemTemplate* templateObject, CraftingValues* craftingValues, TangibleObject* prototype);

	void setSkillMods(TangibleObject* object, LootItemTemplate* templateObject);

	void setCustomObjectName(TangibleObject* object, LootItemTemplate* templateObject);

	void setSockets(TangibleObject* object, CraftingValues* craftingValues);

	void addDots(TangibleObject* object, int creatureLevel);

	void addConditionDamage(TangibleObject* loot, CraftingValues* craftingValues);

public:
	TangibleObject* createLootObject(LootItemTemplate* templateObject, int level);

	int calculateLootCredits(int level);

	bool createLoot(SceneObject* container, AiAgent* creature);

	bool createLootFromCollection(SceneObject* container, LootGroupCollection* collection, int level);

	bool createLoot(SceneObject* container, const String& lootGroup, int level = -1);

	WeakReference<LootManager*> _this;

	operator const LootManager*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~LootManagerImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class LootManager;
};

class LootManagerAdapter : public ManagedServiceAdapter {
public:
	LootManagerAdapter(LootManager* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initialize();

	String getRandomLootableMod();

	int calculateLootCredits(int level);

	bool createLoot(SceneObject* container, AiAgent* creature);

	bool createLoot(SceneObject* container, const String& lootGroup, int level);

};

class LootManagerHelper : public DistributedObjectClassHelper, public Singleton<LootManagerHelper> {
	static LootManagerHelper* staticInitializer;

public:
	LootManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<LootManagerHelper>;
};

} // namespace loot
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::loot;

#endif /*LOOTMANAGER_H_*/
