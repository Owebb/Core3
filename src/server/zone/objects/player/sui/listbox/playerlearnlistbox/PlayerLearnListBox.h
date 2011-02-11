/*
 *	server/zone/objects/player/sui/listbox/playerlearnlistbox/PlayerLearnListBox.h generated by engine3 IDL compiler 0.60
 */

#ifndef PLAYERLEARNLISTBOX_H_
#define PLAYERLEARNLISTBOX_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace professions {

class SkillBox;

} // namespace professions
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::professions;

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerCreature;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

#include "server/zone/objects/player/sui/listbox/SuiListBox.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace listbox {

class PlayerLearnListBox : public SuiListBox {
public:
	PlayerLearnListBox(PlayerCreature* player);

	void setTeacher(PlayerCreature* teacher);

	PlayerCreature* getTeacher();

	void setTeachingOffer(const String& name);

	const String getTeachingOffer();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	PlayerLearnListBox(DummyConstructorParameter* param);

	virtual ~PlayerLearnListBox();

	friend class PlayerLearnListBoxHelper;
};

} // namespace listbox
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::listbox;

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace listbox {

class PlayerLearnListBoxImplementation : public SuiListBoxImplementation {
	ManagedReference<PlayerCreature* > teacherPlayer;

	String teachingOffer;

public:
	PlayerLearnListBoxImplementation(PlayerCreature* player);

	PlayerLearnListBoxImplementation(DummyConstructorParameter* param);

private:
	void init();

public:
	void setTeacher(PlayerCreature* teacher);

	PlayerCreature* getTeacher();

	void setTeachingOffer(const String& name);

	const String getTeachingOffer();

	PlayerLearnListBox* _this;

	operator const PlayerLearnListBox*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~PlayerLearnListBoxImplementation();

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
	bool readObjectMember(ObjectInputStream* stream, const String& name);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class PlayerLearnListBox;
};

class PlayerLearnListBoxAdapter : public SuiListBoxAdapter {
public:
	PlayerLearnListBoxAdapter(PlayerLearnListBoxImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void setTeacher(PlayerCreature* teacher);

	void setTeachingOffer(const String& name);

protected:
	String _param0_setTeachingOffer__String_;
};

class PlayerLearnListBoxHelper : public DistributedObjectClassHelper, public Singleton<PlayerLearnListBoxHelper> {
	static PlayerLearnListBoxHelper* staticInitializer;

public:
	PlayerLearnListBoxHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<PlayerLearnListBoxHelper>;
};

} // namespace listbox
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::listbox;

#endif /*PLAYERLEARNLISTBOX_H_*/