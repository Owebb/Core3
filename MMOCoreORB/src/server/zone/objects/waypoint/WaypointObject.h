/*
 *	server/zone/objects/waypoint/WaypointObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef WAYPOINTOBJECT_H_
#define WAYPOINTOBJECT_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace templates {

class SharedObjectTemplate;

} // namespace templates
} // namespace zone
} // namespace server

using namespace server::zone::templates;

#include "system/lang/String.h"

#include "engine/lua/LuaObject.h"

#include "engine/core/ManagedReference.h"

#include "server/zone/objects/intangible/IntangibleObject.h"

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace objects {
namespace waypoint {

class WaypointObject : public IntangibleObject {
public:
	static const byte COLOR_WHITE = 0x00;

	static const byte COLOR_BLUE = 0x01;

	static const byte COLOR_GREEN = 0x02;

	static const byte COLOR_ORANGE = 0x03;

	static const byte COLOR_YELLOW = 0x04;

	static const byte COLOR_PURPLE = 0x05;

	static const int SPECIALTYPE_FIND = 1;

	static const int SPECIALTYPE_FINDFRIEND = 2;

	static const int SPECIALTYPE_FINDPLAYER = 3;

	static const int SPECIALTYPE_FINDMYTRAINER = 4;

	static const int SPECIALTYPE_FINDOBJECT = 5;

	static const int SPECIALTYPE_RESOURCE = 6;

	WaypointObject();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void insertToMessage(BaseMessage* msg);

	void setCellID(unsigned int id);

	void setPlanetCRC(unsigned int crc);

	unsigned int getPlanetCRC();

	void setColor(byte newColor);

	void setActive(byte newStatus);

	void setUnknown(unsigned long long id);

	void setSpecialTypeID(int id);

	int getSpecialTypeID();

	void toggleStatus();

	bool isActive();

	byte getColor();

	String getDetailedDescription();

	void setDetailedDescription(const String& desc);

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	WaypointObject(DummyConstructorParameter* param);

	virtual ~WaypointObject();

	friend class WaypointObjectHelper;
};

} // namespace waypoint
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::waypoint;

namespace server {
namespace zone {
namespace objects {
namespace waypoint {

class WaypointObjectImplementation : public IntangibleObjectImplementation {
protected:
	unsigned int cellID;

	unsigned long long unknown;

	unsigned int planetCRC;

	String detailedDescription;

	byte color;

	byte active;

	int specialTypeID;

public:
	static const byte COLOR_WHITE = 0x00;

	static const byte COLOR_BLUE = 0x01;

	static const byte COLOR_GREEN = 0x02;

	static const byte COLOR_ORANGE = 0x03;

	static const byte COLOR_YELLOW = 0x04;

	static const byte COLOR_PURPLE = 0x05;

	static const int SPECIALTYPE_FIND = 1;

	static const int SPECIALTYPE_FINDFRIEND = 2;

	static const int SPECIALTYPE_FINDPLAYER = 3;

	static const int SPECIALTYPE_FINDMYTRAINER = 4;

	static const int SPECIALTYPE_FINDOBJECT = 5;

	static const int SPECIALTYPE_RESOURCE = 6;

	WaypointObjectImplementation();

	WaypointObjectImplementation(DummyConstructorParameter* param);

	void loadTemplateData(SharedObjectTemplate* templateData);

	void insertToMessage(BaseMessage* msg);

	void setCellID(unsigned int id);

	void setPlanetCRC(unsigned int crc);

	unsigned int getPlanetCRC();

	void setColor(byte newColor);

	void setActive(byte newStatus);

	void setUnknown(unsigned long long id);

	void setSpecialTypeID(int id);

	int getSpecialTypeID();

	void toggleStatus();

	bool isActive();

	byte getColor();

	String getDetailedDescription();

	void setDetailedDescription(const String& desc);

	WeakReference<WaypointObject*> _this;

	operator const WaypointObject*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~WaypointObjectImplementation();

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

	friend class WaypointObject;
};

class WaypointObjectAdapter : public IntangibleObjectAdapter {
public:
	WaypointObjectAdapter(WaypointObject* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void setCellID(unsigned int id);

	void setPlanetCRC(unsigned int crc);

	unsigned int getPlanetCRC();

	void setColor(byte newColor);

	void setActive(byte newStatus);

	void setUnknown(unsigned long long id);

	void setSpecialTypeID(int id);

	int getSpecialTypeID();

	void toggleStatus();

	bool isActive();

	byte getColor();

	String getDetailedDescription();

	void setDetailedDescription(const String& desc);

};

class WaypointObjectHelper : public DistributedObjectClassHelper, public Singleton<WaypointObjectHelper> {
	static WaypointObjectHelper* staticInitializer;

public:
	WaypointObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<WaypointObjectHelper>;
};

} // namespace waypoint
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::waypoint;

#endif /*WAYPOINTOBJECT_H_*/
