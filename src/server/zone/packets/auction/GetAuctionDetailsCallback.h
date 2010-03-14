/*
 * GetAuctionDetailsCallback.h
 *
 *  Created on: 13/03/2010
 *      Author: victor
 */

#ifndef GETAUCTIONDETAILSCALLBACK
#define GETAUCTIONDETAILSCALLBACK

#include "../MessageCallback.h"
#include "server/zone/managers/bazaar/BazaarManager.h"


class GetAuctionDetailsCallback : public MessageCallback {
	uint64 objectid;

public:
	GetAuctionDetailsCallback(ZoneClientSession* client, ZoneProcessServerImplementation* server) :
			MessageCallback(client, server) {

	}

	void parse(Message* message) {
		objectid = message->parseLong();
	}

	void run() {
		PlayerCreature* player = (PlayerCreature*) client->getPlayer();

		if (player == NULL)
			return;

		BazaarManager* bazaarManager = server->getZoneServer()->getBazaarManager();
		bazaarManager->getItemAttributes(player, objectid);
	}

};

#endif

