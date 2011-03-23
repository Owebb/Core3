/*
 *	server/login/account/Account.h generated by engine3 IDL compiler 0.60
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace login {
namespace account {

class AccountManager;

} // namespace account
} // namespace login
} // namespace server

using namespace server::login::account;

namespace server {
namespace zone {

class ZoneClientSession;

} // namespace zone
} // namespace server

using namespace server::zone;

#include "engine/core/ManagedObject.h"

#include "engine/log/Logger.h"

#include "system/util/VectorMap.h"

#include "system/lang/Time.h"

#include "system/lang/System.h"

namespace server {
namespace login {
namespace account {

class Account : public ManagedObject {
public:
	Account(AccountManager* accManage, const String& usern, unsigned int accountid, unsigned int stationid);

	bool hasMaxOnlineCharacters();

	ZoneClientSession* getZoneSession(unsigned int sessionID);

	bool containsZoneSession(unsigned int sessionID);

	void addZoneSession(ZoneClientSession* client);

	void removeZoneSession(unsigned int sessionID);

	void setAccountID(unsigned int accountid);

	void setStationID(unsigned int stationid);

	void setAdminLevel(unsigned int adminlvl);

	void setUsername(const String& usern);

	void setTimeCreated(unsigned int seconds);

	unsigned int getAccountID();

	unsigned int getStationID();

	unsigned int getAdminLevel();

	String getUsername();

	unsigned int getTimeCreated();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	Account(DummyConstructorParameter* param);

	virtual ~Account();

	String _return_getUsername;

	friend class AccountHelper;
};

} // namespace account
} // namespace login
} // namespace server

using namespace server::login::account;

namespace server {
namespace login {
namespace account {

class AccountImplementation : public ManagedObjectImplementation, public Logger {
protected:
	VectorMap<unsigned int, ManagedReference<ZoneClientSession* > > zoneSessions;

	AccountManager* accountManager;

	String username;

	unsigned int accountID;

	unsigned int stationID;

	unsigned int adminLevel;

	unsigned int created;

public:
	AccountImplementation(AccountManager* accManage, const String& usern, unsigned int accountid, unsigned int stationid);

	AccountImplementation(DummyConstructorParameter* param);

	bool hasMaxOnlineCharacters();

	ZoneClientSession* getZoneSession(unsigned int sessionID);

	bool containsZoneSession(unsigned int sessionID);

	void addZoneSession(ZoneClientSession* client);

	void removeZoneSession(unsigned int sessionID);

	void setAccountID(unsigned int accountid);

	void setStationID(unsigned int stationid);

	void setAdminLevel(unsigned int adminlvl);

	void setUsername(const String& usern);

	void setTimeCreated(unsigned int seconds);

	unsigned int getAccountID();

	unsigned int getStationID();

	unsigned int getAdminLevel();

	String getUsername();

	unsigned int getTimeCreated();

	Account* _this;

	operator const Account*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~AccountImplementation();

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

	friend class Account;
};

class AccountAdapter : public ManagedObjectAdapter {
public:
	AccountAdapter(AccountImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	bool hasMaxOnlineCharacters();

	ZoneClientSession* getZoneSession(unsigned int sessionID);

	bool containsZoneSession(unsigned int sessionID);

	void addZoneSession(ZoneClientSession* client);

	void removeZoneSession(unsigned int sessionID);

	void setAccountID(unsigned int accountid);

	void setStationID(unsigned int stationid);

	void setAdminLevel(unsigned int adminlvl);

	void setUsername(const String& usern);

	void setTimeCreated(unsigned int seconds);

	unsigned int getAccountID();

	unsigned int getStationID();

	unsigned int getAdminLevel();

	String getUsername();

	unsigned int getTimeCreated();

protected:
	String _param0_setUsername__String_;
};

class AccountHelper : public DistributedObjectClassHelper, public Singleton<AccountHelper> {
	static AccountHelper* staticInitializer;

public:
	AccountHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<AccountHelper>;
};

} // namespace account
} // namespace login
} // namespace server

using namespace server::login::account;

#endif /*ACCOUNT_H_*/