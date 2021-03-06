/*
 *	server/zone/objects/tangible/pharmaceutical/DotPack.h generated by engine3 IDL compiler 0.60
 */

#ifndef DOTPACK_H_
#define DOTPACK_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

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

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace packets {
namespace scene {

class AttributeListMessage;

} // namespace scene
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::scene;

namespace server {
namespace zone {
namespace packets {
namespace object {

class ObjectMenuResponse;

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;

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

class ZoneServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace manufactureschematic {

class ManufactureSchematic;

} // namespace manufactureschematic
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::manufactureschematic;

#include "server/zone/objects/creature/CreatureState.h"

#include "server/zone/objects/creature/CreatureAttribute.h"

#include "server/zone/objects/manufactureschematic/craftingvalues/CraftingValues.h"

#include "server/zone/templates/tangible/DotPackTemplate.h"

#include "engine/lua/LuaObject.h"

#include "server/zone/objects/tangible/pharmaceutical/PharmaceuticalObject.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace pharmaceutical {

class DotPack : public PharmaceuticalObject {
public:
	DotPack();

	void updateCraftingValues(CraftingValues* values, bool firstUpdate);

	void loadTemplateData(SharedObjectTemplate* templateData);

	void fillAttributeList(AttributeListMessage* msg, CreatureObject* object);

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	int calculatePower(CreatureObject* creature);

	bool isPoisonDeliveryUnit();

	bool isDiseaseDeliveryUnit();

	float getEffectiveness();

	float getRange();

	float getArea();

	float getRangeMod();

	float getPotency();

	unsigned int getDuration();

	bool isArea();

	unsigned int getPool();

	unsigned int getDotType();

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	DotPack(DummyConstructorParameter* param);

	virtual ~DotPack();

	friend class DotPackHelper;
};

} // namespace pharmaceutical
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::pharmaceutical;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace pharmaceutical {

class DotPackImplementation : public PharmaceuticalObjectImplementation {
protected:
	float effectiveness;

	float range;

	float area;

	bool hasArea;

	float rangeMod;

	float potency;

	String commandToExecute;

	unsigned int duration;

	unsigned int pool;

	unsigned int dotType;

public:
	DotPackImplementation();

	DotPackImplementation(DummyConstructorParameter* param);

	void updateCraftingValues(CraftingValues* values, bool firstUpdate);

	void loadTemplateData(SharedObjectTemplate* templateData);

	void fillAttributeList(AttributeListMessage* msg, CreatureObject* object);

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	int calculatePower(CreatureObject* creature);

	bool isPoisonDeliveryUnit();

	bool isDiseaseDeliveryUnit();

	float getEffectiveness();

	float getRange();

	float getArea();

	float getRangeMod();

	float getPotency();

	unsigned int getDuration();

	bool isArea();

	unsigned int getPool();

	unsigned int getDotType();

	WeakReference<DotPack*> _this;

	operator const DotPack*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~DotPackImplementation();

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

	friend class DotPack;
};

class DotPackAdapter : public PharmaceuticalObjectAdapter {
public:
	DotPackAdapter(DotPack* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	int calculatePower(CreatureObject* creature);

	bool isPoisonDeliveryUnit();

	bool isDiseaseDeliveryUnit();

	float getEffectiveness();

	float getRange();

	float getArea();

	float getRangeMod();

	float getPotency();

	unsigned int getDuration();

	bool isArea();

	unsigned int getPool();

	unsigned int getDotType();

};

class DotPackHelper : public DistributedObjectClassHelper, public Singleton<DotPackHelper> {
	static DotPackHelper* staticInitializer;

public:
	DotPackHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<DotPackHelper>;
};

} // namespace pharmaceutical
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::pharmaceutical;

#endif /*DOTPACK_H_*/
