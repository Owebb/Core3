/*
 *	server/zone/ZoneServer.h generated by engine3 IDL compiler 0.60
 */

#ifndef ZONESERVER_H_
#define ZONESERVER_H_

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
namespace login {
namespace account {

class Account;

} // namespace account
} // namespace login
} // namespace server

using namespace server::login::account;

namespace server {
namespace zone {

class ZoneProcessServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {

class ZoneClientSession;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {

class ZoneHandler;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace chat {

class ChatManager;

} // namespace chat
} // namespace server

using namespace server::chat;

namespace server {
namespace conf {

class ConfigManager;

} // namespace conf
} // namespace server

using namespace server::conf;

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
namespace managers {
namespace player {

class PlayerManager;

} // namespace player
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::player;

namespace server {
namespace zone {
namespace managers {
namespace objectcontroller {

class ObjectController;

} // namespace objectcontroller
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::objectcontroller;

namespace server {
namespace zone {
namespace managers {
namespace radial {

class RadialManager;

} // namespace radial
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::radial;

namespace server {
namespace zone {
namespace managers {
namespace skill {

class SkillManager;

} // namespace skill
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::skill;

namespace server {
namespace zone {
namespace managers {
namespace resource {

class ResourceManager;

} // namespace resource
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::resource;

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
namespace loot {

class LootManager;

} // namespace loot
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::loot;

namespace server {
namespace zone {
namespace managers {
namespace auction {

class AuctionManager;

} // namespace auction
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::auction;

namespace server {
namespace zone {
namespace managers {
namespace minigames {

class FishingManager;

} // namespace minigames
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::minigames;

namespace server {
namespace zone {
namespace managers {
namespace mission {

class MissionManager;

} // namespace mission
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::mission;

namespace server {
namespace zone {
namespace managers {
namespace minigames {

class GamblingManager;

} // namespace minigames
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::minigames;

namespace server {
namespace zone {
namespace managers {
namespace minigames {

class ForageManager;

} // namespace minigames
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::minigames;

namespace server {
namespace zone {
namespace managers {
namespace stringid {

class StringIdManager;

} // namespace stringid
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::stringid;

namespace server {
namespace zone {
namespace managers {
namespace creature {

class CreatureTemplateManager;

} // namespace creature
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::creature;

namespace server {
namespace zone {
namespace managers {
namespace creature {

class DnaManager;

} // namespace creature
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::creature;

namespace server {
namespace zone {
namespace managers {
namespace guild {

class GuildManager;

} // namespace guild
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::guild;

namespace server {
namespace zone {
namespace managers {
namespace city {

class CityManager;

} // namespace city
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::city;

#include "engine/service/proto/BasePacketHandler.h"

#include "engine/service/DatagramServiceThread.h"

#include "engine/service/ServiceHandler.h"

#include "engine/service/ServiceClient.h"

#include "engine/service/Message.h"

#include "engine/core/ManagedService.h"

#include "engine/core/TaskManager.h"

#include "engine/log/Logger.h"

#include "system/lang/Exception.h"

#include "system/lang/Time.h"

#include "system/lang/ref/Reference.h"

#include "system/util/Vector.h"

#include "system/util/VectorMap.h"

#include "system/net/Socket.h"

#include "system/net/SocketAddress.h"

#include "system/net/Packet.h"

#include "system/thread/atomic/AtomicInteger.h"

namespace server {
namespace zone {

class ZoneServer : public ManagedService {
public:
	static const int OFFLINE = 0;

	static const int LOADING = 1;

	static const int ONLINE = 2;

	static const int LOCKED = 3;

	ZoneServer(ConfigManager* config);

	void initializeTransientMembers();

	ZoneClientSession* createConnection(Socket* sock, SocketAddress& addr);

	void initialize();

	void shutdown();

	void startManagers();

	void startZones();

	void stopManagers();

	void start(int p, int mconn = 10);

	void stop();

	void timedShutdown(int minutes);

	void handleMessage(ZoneClientSession* client, Packet* message);

	void processMessage(Message* message);

	bool handleError(ZoneClientSession* client, Exception& e);

	void addTotalSentPacket(int count);

	void addTotalResentPacket(int count);

	void printInfo();

	String getInfo();

	void printEvents();

	SceneObject* getObject(unsigned long long objectID, bool doLock = true);

	SceneObject* createObject(unsigned int templateCRC, const String& dbname, int persistenceLevel = 2);

	SceneObject* createObject(unsigned int templateCRC, int persistenceLevel = 2, unsigned long long objectID = 0);

	SceneObject* createClientObject(unsigned int templateCRC, unsigned long long objectID = 0);

	void updateObjectToDatabase(SceneObject* object);

	void updateObjectToStaticDatabase(SceneObject* object);

	void destroyObjectFromDatabase(unsigned long long objectID);

	void lock(bool doLock = true);

	void unlock(bool doLock = true);

	void fixScheduler();

	void changeUserCap(int amount = 50);

	int getConnectionCount();

	void increaseOnlinePlayers();

	void decreaseOnlinePlayers();

	void increaseTotalDeletedPlayers();

	int getGalaxyID();

	String getGalaxyName();

	void setGalaxyName(const String& name);

	bool isServerLocked();

	bool isServerOnline();

	bool isServerOffline();

	bool isServerLoading();

	int getServerCap();

	int getServerState();

	Zone* getZone(const String& terrainName);

	Zone* getZone(int idx);

	int getZoneCount();

	int getMaxPlayers();

	int getTotalPlayers();

	int getDeletedPlayers();

	ObjectManager* getObjectManager();

	PlayerManager* getPlayerManager();

	ChatManager* getChatManager();

	CityManager* getCityManager();

	ObjectController* getObjectController();

	MissionManager* getMissionManager();

	RadialManager* getRadialManager();

	GuildManager* getGuildManager();

	ResourceManager* getResourceManager();

	CraftingManager* getCraftingManager();

	LootManager* getLootManager();

	AuctionManager* getAuctionManager();

	SkillManager* getSkillManager();

	Time* getStartTimestamp();

	void setGalaxyID(int galaxyid);

	void setServerState(int state);

	void setServerStateLocked();

	void setServerStateOnline();

	void loadLoginMessage();

	void changeLoginMessage(const String& motd);

	String getLoginMessage();

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	ZoneServer(DummyConstructorParameter* param);

	virtual ~ZoneServer();

	friend class ZoneServerHelper;
};

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {

class ZoneServerImplementation : public ManagedServiceImplementation, public Logger {
	Reference<DatagramServiceThread* > datagramService;

	Reference<BasePacketHandler* > phandler;

	Reference<ConfigManager* > configManager;

	Reference<ZoneHandler* > zoneHandler;

	ManagedReference<ZoneProcessServer* > processor;

	Reference<VectorMap<String, ManagedReference<Zone* > >* > zones;

	Reference<ObjectManager* > objectManager;

	ManagedReference<PlayerManager* > playerManager;

	ManagedReference<ChatManager* > chatManager;

	ManagedReference<RadialManager* > radialManager;

	ManagedReference<CityManager* > cityManager;

	ManagedReference<ResourceManager* > resourceManager;

	ManagedReference<CraftingManager* > craftingManager;

	ManagedReference<LootManager* > lootManager;

	ManagedReference<AuctionManager* > auctionManager;

	ManagedReference<MissionManager* > missionManager;

	ManagedReference<GuildManager* > guildManager;

	Reference<StringIdManager* > stringIdManager;

	Reference<CreatureTemplateManager* > creatureTemplateManager;

	Reference<DnaManager* > dnaManager;

	int totalSentPackets;

	int serverCap;

	int totalResentPackets;

	AtomicInteger currentPlayers;

	AtomicInteger maximumPlayers;

	AtomicInteger totalPlayers;

	AtomicInteger totalDeletedPlayers;

	int serverState;

	String galaxyName;

	String loginMessage;

	int galaxyID;

	Time startTimestamp;

public:
	static const int OFFLINE = 0;

	static const int LOADING = 1;

	static const int ONLINE = 2;

	static const int LOCKED = 3;

	ZoneServerImplementation(ConfigManager* config);

	ZoneServerImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	ZoneClientSession* createConnection(Socket* sock, SocketAddress& addr);

private:
	void loadGalaxyName();

public:
	void initialize();

	void shutdown();

	void startManagers();

	void startZones();

	void stopManagers();

	void start(int p, int mconn = 10);

	void stop();

	void timedShutdown(int minutes);

	void handleMessage(ZoneClientSession* client, Packet* message);

	void processMessage(Message* message);

	bool handleError(ZoneClientSession* client, Exception& e);

	void addTotalSentPacket(int count);

	void addTotalResentPacket(int count);

	void printInfo();

	String getInfo();

	void printEvents();

	SceneObject* getObject(unsigned long long objectID, bool doLock = true);

	SceneObject* createObject(unsigned int templateCRC, const String& dbname, int persistenceLevel = 2);

	SceneObject* createObject(unsigned int templateCRC, int persistenceLevel = 2, unsigned long long objectID = 0);

	SceneObject* createClientObject(unsigned int templateCRC, unsigned long long objectID = 0);

	void updateObjectToDatabase(SceneObject* object);

	void updateObjectToStaticDatabase(SceneObject* object);

	void destroyObjectFromDatabase(unsigned long long objectID);

	void lock(bool doLock = true);

	void unlock(bool doLock = true);

	void fixScheduler();

	void changeUserCap(int amount = 50);

	int getConnectionCount();

	void increaseOnlinePlayers();

	void decreaseOnlinePlayers();

	void increaseTotalDeletedPlayers();

	int getGalaxyID();

	String getGalaxyName();

	void setGalaxyName(const String& name);

	bool isServerLocked();

	bool isServerOnline();

	bool isServerOffline();

	bool isServerLoading();

	int getServerCap();

	int getServerState();

	Zone* getZone(const String& terrainName);

	Zone* getZone(int idx);

	int getZoneCount();

	int getMaxPlayers();

	int getTotalPlayers();

	int getDeletedPlayers();

	ObjectManager* getObjectManager();

	PlayerManager* getPlayerManager();

	ChatManager* getChatManager();

	CityManager* getCityManager();

	ObjectController* getObjectController();

	MissionManager* getMissionManager();

	RadialManager* getRadialManager();

	GuildManager* getGuildManager();

	ResourceManager* getResourceManager();

	CraftingManager* getCraftingManager();

	LootManager* getLootManager();

	AuctionManager* getAuctionManager();

	SkillManager* getSkillManager();

	Time* getStartTimestamp();

	void setGalaxyID(int galaxyid);

	void setServerState(int state);

	void setServerStateLocked();

	void setServerStateOnline();

	void loadLoginMessage();

	void changeLoginMessage(const String& motd);

	String getLoginMessage();

	WeakReference<ZoneServer*> _this;

	operator const ZoneServer*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~ZoneServerImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class ZoneServer;
};

class ZoneServerAdapter : public ManagedServiceAdapter {
public:
	ZoneServerAdapter(ZoneServer* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	void initialize();

	void shutdown();

	void startManagers();

	void startZones();

	void stopManagers();

	void start(int p, int mconn);

	void stop();

	void timedShutdown(int minutes);

	void addTotalSentPacket(int count);

	void addTotalResentPacket(int count);

	void printInfo();

	String getInfo();

	void printEvents();

	SceneObject* getObject(unsigned long long objectID, bool doLock);

	SceneObject* createObject(unsigned int templateCRC, const String& dbname, int persistenceLevel);

	SceneObject* createObject(unsigned int templateCRC, int persistenceLevel, unsigned long long objectID);

	SceneObject* createClientObject(unsigned int templateCRC, unsigned long long objectID);

	void updateObjectToDatabase(SceneObject* object);

	void updateObjectToStaticDatabase(SceneObject* object);

	void destroyObjectFromDatabase(unsigned long long objectID);

	void lock(bool doLock);

	void unlock(bool doLock);

	void fixScheduler();

	void changeUserCap(int amount);

	int getConnectionCount();

	void increaseOnlinePlayers();

	void decreaseOnlinePlayers();

	void increaseTotalDeletedPlayers();

	int getGalaxyID();

	String getGalaxyName();

	void setGalaxyName(const String& name);

	bool isServerLocked();

	bool isServerOnline();

	bool isServerOffline();

	bool isServerLoading();

	int getServerCap();

	int getServerState();

	Zone* getZone(const String& terrainName);

	Zone* getZone(int idx);

	int getZoneCount();

	int getMaxPlayers();

	int getTotalPlayers();

	int getDeletedPlayers();

	PlayerManager* getPlayerManager();

	ChatManager* getChatManager();

	CityManager* getCityManager();

	ObjectController* getObjectController();

	MissionManager* getMissionManager();

	RadialManager* getRadialManager();

	GuildManager* getGuildManager();

	ResourceManager* getResourceManager();

	CraftingManager* getCraftingManager();

	LootManager* getLootManager();

	AuctionManager* getAuctionManager();

	void setGalaxyID(int galaxyid);

	void setServerState(int state);

	void setServerStateLocked();

	void setServerStateOnline();

	void loadLoginMessage();

	void changeLoginMessage(const String& motd);

	String getLoginMessage();

};

class ZoneServerHelper : public DistributedObjectClassHelper, public Singleton<ZoneServerHelper> {
	static ZoneServerHelper* staticInitializer;

public:
	ZoneServerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<ZoneServerHelper>;
};

} // namespace zone
} // namespace server

using namespace server::zone;

#endif /*ZONESERVER_H_*/
