/*
 *	server/zone/managers/auction/AuctionsMap.cpp generated by engine3 IDL compiler 0.60
 */

#include "AuctionsMap.h"

#include "server/zone/objects/auction/AuctionItem.h"

/*
 *	AuctionsMapStub
 */

enum {RPC_GETVENDORITEMCOUNT__ = 6,RPC_CONTAINSVENDORITEM__LONG_,RPC_ADDVENDORITEM__LONG_AUCTIONITEM_,RPC_GETPLAYERVENDORITEMCOUNT__LONG_,RPC_DROPVENDORITEM__LONG_,RPC_GETVENDORITEM__LONG_,RPC_GETVENDORITEM__INT_,RPC_INCREASEPLAYERVENDORCOUNT__LONG_,RPC_DECREASEPLAYERVENDORCOUNT__LONG_,RPC_GETPLAYERVENDORCOUNT__LONG_,RPC_GETAUCTIONCOUNT__,RPC_CONTAINSAUCTION__LONG_,RPC_ADDBAZAARITEM__LONG_AUCTIONITEM_,RPC_GETPLAYERAUCTIONCOUNT__LONG_,RPC_DROPBAZAARITEM__LONG_,RPC_GETBAZAARITEM__LONG_,RPC_GETBAZAARITEM__INT_,RPC_CHECKINSTOCKROOM__LONG_,};

AuctionsMap::AuctionsMap() : ManagedObject(DummyConstructorParameter::instance()) {
	AuctionsMapImplementation* _implementation = new AuctionsMapImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

AuctionsMap::AuctionsMap(DummyConstructorParameter* param) : ManagedObject(param) {
}

AuctionsMap::~AuctionsMap() {
}


int AuctionsMap::getVendorItemCount() {
	AuctionsMapImplementation* _implementation = (AuctionsMapImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETVENDORITEMCOUNT__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getVendorItemCount();
}

bool AuctionsMap::containsVendorItem(unsigned long long objectID) {
	AuctionsMapImplementation* _implementation = (AuctionsMapImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CONTAINSVENDORITEM__LONG_);
		method.addUnsignedLongParameter(objectID);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->containsVendorItem(objectID);
}

void AuctionsMap::addVendorItem(unsigned long long objectID, AuctionItem* item) {
	AuctionsMapImplementation* _implementation = (AuctionsMapImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ADDVENDORITEM__LONG_AUCTIONITEM_);
		method.addUnsignedLongParameter(objectID);
		method.addObjectParameter(item);

		method.executeWithVoidReturn();
	} else
		_implementation->addVendorItem(objectID, item);
}

int AuctionsMap::getPlayerVendorItemCount(unsigned long long objectID) {
	AuctionsMapImplementation* _implementation = (AuctionsMapImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETPLAYERVENDORITEMCOUNT__LONG_);
		method.addUnsignedLongParameter(objectID);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getPlayerVendorItemCount(objectID);
}

void AuctionsMap::dropVendorItem(unsigned long long objectID) {
	AuctionsMapImplementation* _implementation = (AuctionsMapImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DROPVENDORITEM__LONG_);
		method.addUnsignedLongParameter(objectID);

		method.executeWithVoidReturn();
	} else
		_implementation->dropVendorItem(objectID);
}

AuctionItem* AuctionsMap::getVendorItem(unsigned long long objectID) {
	AuctionsMapImplementation* _implementation = (AuctionsMapImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETVENDORITEM__LONG_);
		method.addUnsignedLongParameter(objectID);

		return (AuctionItem*) method.executeWithObjectReturn();
	} else
		return _implementation->getVendorItem(objectID);
}

AuctionItem* AuctionsMap::getVendorItem(int index) {
	AuctionsMapImplementation* _implementation = (AuctionsMapImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETVENDORITEM__INT_);
		method.addSignedIntParameter(index);

		return (AuctionItem*) method.executeWithObjectReturn();
	} else
		return _implementation->getVendorItem(index);
}

void AuctionsMap::increasePlayerVendorCount(unsigned long long playerID) {
	AuctionsMapImplementation* _implementation = (AuctionsMapImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INCREASEPLAYERVENDORCOUNT__LONG_);
		method.addUnsignedLongParameter(playerID);

		method.executeWithVoidReturn();
	} else
		_implementation->increasePlayerVendorCount(playerID);
}

void AuctionsMap::decreasePlayerVendorCount(unsigned long long playerID) {
	AuctionsMapImplementation* _implementation = (AuctionsMapImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DECREASEPLAYERVENDORCOUNT__LONG_);
		method.addUnsignedLongParameter(playerID);

		method.executeWithVoidReturn();
	} else
		_implementation->decreasePlayerVendorCount(playerID);
}

int AuctionsMap::getPlayerVendorCount(unsigned long long playerID) {
	AuctionsMapImplementation* _implementation = (AuctionsMapImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETPLAYERVENDORCOUNT__LONG_);
		method.addUnsignedLongParameter(playerID);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getPlayerVendorCount(playerID);
}

int AuctionsMap::getAuctionCount() {
	AuctionsMapImplementation* _implementation = (AuctionsMapImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETAUCTIONCOUNT__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getAuctionCount();
}

bool AuctionsMap::containsAuction(unsigned long long objectID) {
	AuctionsMapImplementation* _implementation = (AuctionsMapImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CONTAINSAUCTION__LONG_);
		method.addUnsignedLongParameter(objectID);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->containsAuction(objectID);
}

void AuctionsMap::addBazaarItem(unsigned long long objectID, AuctionItem* item) {
	AuctionsMapImplementation* _implementation = (AuctionsMapImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ADDBAZAARITEM__LONG_AUCTIONITEM_);
		method.addUnsignedLongParameter(objectID);
		method.addObjectParameter(item);

		method.executeWithVoidReturn();
	} else
		_implementation->addBazaarItem(objectID, item);
}

int AuctionsMap::getPlayerAuctionCount(unsigned long long objectID) {
	AuctionsMapImplementation* _implementation = (AuctionsMapImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETPLAYERAUCTIONCOUNT__LONG_);
		method.addUnsignedLongParameter(objectID);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getPlayerAuctionCount(objectID);
}

void AuctionsMap::dropBazaarItem(unsigned long long objectID) {
	AuctionsMapImplementation* _implementation = (AuctionsMapImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DROPBAZAARITEM__LONG_);
		method.addUnsignedLongParameter(objectID);

		method.executeWithVoidReturn();
	} else
		_implementation->dropBazaarItem(objectID);
}

AuctionItem* AuctionsMap::getBazaarItem(unsigned long long objectID) {
	AuctionsMapImplementation* _implementation = (AuctionsMapImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETBAZAARITEM__LONG_);
		method.addUnsignedLongParameter(objectID);

		return (AuctionItem*) method.executeWithObjectReturn();
	} else
		return _implementation->getBazaarItem(objectID);
}

AuctionItem* AuctionsMap::getBazaarItem(int index) {
	AuctionsMapImplementation* _implementation = (AuctionsMapImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETBAZAARITEM__INT_);
		method.addSignedIntParameter(index);

		return (AuctionItem*) method.executeWithObjectReturn();
	} else
		return _implementation->getBazaarItem(index);
}

bool AuctionsMap::checkInStockroom(unsigned long long objectID) {
	AuctionsMapImplementation* _implementation = (AuctionsMapImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CHECKINSTOCKROOM__LONG_);
		method.addUnsignedLongParameter(objectID);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->checkInStockroom(objectID);
}

VectorMap<unsigned long long, ManagedReference<AuctionItem* > >* AuctionsMap::getBazaarItems() {
	AuctionsMapImplementation* _implementation = (AuctionsMapImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getBazaarItems();
}

VectorMap<unsigned long long, ManagedReference<AuctionItem* > >* AuctionsMap::getVendorItems() {
	AuctionsMapImplementation* _implementation = (AuctionsMapImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getVendorItems();
}

DistributedObjectServant* AuctionsMap::_getImplementation() {

	_updated = true;
	return _impl;
}

void AuctionsMap::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	AuctionsMapImplementation
 */

AuctionsMapImplementation::AuctionsMapImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


AuctionsMapImplementation::~AuctionsMapImplementation() {
}


void AuctionsMapImplementation::finalize() {
}

void AuctionsMapImplementation::_initializeImplementation() {
	_setClassHelper(AuctionsMapHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void AuctionsMapImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (AuctionsMap*) stub;
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* AuctionsMapImplementation::_getStub() {
	return _this;
}

AuctionsMapImplementation::operator const AuctionsMap*() {
	return _this;
}

void AuctionsMapImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void AuctionsMapImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void AuctionsMapImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void AuctionsMapImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void AuctionsMapImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void AuctionsMapImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void AuctionsMapImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void AuctionsMapImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("AuctionsMap");

}

void AuctionsMapImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(AuctionsMapImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool AuctionsMapImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ManagedObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "auctions") {
		TypeInfo<VectorMap<unsigned long long, ManagedReference<AuctionItem* > > >::parseFromBinaryStream(&auctions, stream);
		return true;
	}

	if (_name == "vendorItems") {
		TypeInfo<VectorMap<unsigned long long, ManagedReference<AuctionItem* > > >::parseFromBinaryStream(&vendorItems, stream);
		return true;
	}

	if (_name == "playerAuctionCount") {
		TypeInfo<VectorMap<unsigned long long, int> >::parseFromBinaryStream(&playerAuctionCount, stream);
		return true;
	}

	if (_name == "playerVendorItemCount") {
		TypeInfo<VectorMap<unsigned long long, int> >::parseFromBinaryStream(&playerVendorItemCount, stream);
		return true;
	}

	if (_name == "playerVendorCount") {
		TypeInfo<VectorMap<unsigned long long, int> >::parseFromBinaryStream(&playerVendorCount, stream);
		return true;
	}


	return false;
}

void AuctionsMapImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = AuctionsMapImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int AuctionsMapImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "auctions";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<VectorMap<unsigned long long, ManagedReference<AuctionItem* > > >::toBinaryStream(&auctions, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "vendorItems";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<VectorMap<unsigned long long, ManagedReference<AuctionItem* > > >::toBinaryStream(&vendorItems, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "playerAuctionCount";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<VectorMap<unsigned long long, int> >::toBinaryStream(&playerAuctionCount, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "playerVendorItemCount";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<VectorMap<unsigned long long, int> >::toBinaryStream(&playerVendorItemCount, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "playerVendorCount";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<VectorMap<unsigned long long, int> >::toBinaryStream(&playerVendorCount, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 5 + ManagedObjectImplementation::writeObjectMembers(stream);
}

AuctionsMapImplementation::AuctionsMapImplementation() {
	_initializeImplementation();
	// server/zone/managers/auction/AuctionsMap.idl():  		auctions.setNullValue(null);
	(&auctions)->setNullValue(NULL);
	// server/zone/managers/auction/AuctionsMap.idl():  		auctions.setNoDuplicateInsertPlan();
	(&auctions)->setNoDuplicateInsertPlan();
	// server/zone/managers/auction/AuctionsMap.idl():  		vendorItems.setNullValue(null);
	(&vendorItems)->setNullValue(NULL);
	// server/zone/managers/auction/AuctionsMap.idl():  		vendorItems.setNoDuplicateInsertPlan();
	(&vendorItems)->setNoDuplicateInsertPlan();
	// server/zone/managers/auction/AuctionsMap.idl():  		playerAuctionCount.setNullValue(0);
	(&playerAuctionCount)->setNullValue(0);
	// server/zone/managers/auction/AuctionsMap.idl():  		playerAuctionCount.setAllowOverwriteInsertPlan();
	(&playerAuctionCount)->setAllowOverwriteInsertPlan();
	// server/zone/managers/auction/AuctionsMap.idl():  		playerVendorItemCount.setNullValue(0);
	(&playerVendorItemCount)->setNullValue(0);
	// server/zone/managers/auction/AuctionsMap.idl():  		playerVendorItemCount.setAllowOverwriteInsertPlan();
	(&playerVendorItemCount)->setAllowOverwriteInsertPlan();
	// server/zone/managers/auction/AuctionsMap.idl():  		playerVendorCount.setNullValue(0);
	(&playerVendorCount)->setNullValue(0);
	// server/zone/managers/auction/AuctionsMap.idl():  		playerVendorCount.setAllowOverwriteInsertPlan();
	(&playerVendorCount)->setAllowOverwriteInsertPlan();
}

int AuctionsMapImplementation::getVendorItemCount() {
	// server/zone/managers/auction/AuctionsMap.idl():  		return vendorItems.size();
	return (&vendorItems)->size();
}

bool AuctionsMapImplementation::containsVendorItem(unsigned long long objectID) {
	// server/zone/managers/auction/AuctionsMap.idl():  		return vendorItems.contains(objectID);
	return (&vendorItems)->contains(objectID);
}

void AuctionsMapImplementation::addVendorItem(unsigned long long objectID, AuctionItem* item) {
	// server/zone/managers/auction/AuctionsMap.idl():  		vendorItems.put(objectID, item);
	(&vendorItems)->put(objectID, item);
	// server/zone/managers/auction/AuctionsMap.idl():  		playerVendorItemCount.put(item.getOwnerID(), playerVendorItemCount.get(item.getOwnerID()) + 1);
	(&playerVendorItemCount)->put(item->getOwnerID(), (&playerVendorItemCount)->get(item->getOwnerID()) + 1);
}

int AuctionsMapImplementation::getPlayerVendorItemCount(unsigned long long objectID) {
	// server/zone/managers/auction/AuctionsMap.idl():  		return playerVendorItemCount.get(objectID);
	return (&playerVendorItemCount)->get(objectID);
}

void AuctionsMapImplementation::dropVendorItem(unsigned long long objectID) {
	// server/zone/managers/auction/AuctionsMap.idl():  		AuctionItem item = vendorItems.get(objectID);
	AuctionItem* item = (&vendorItems)->get(objectID);
	// server/zone/managers/auction/AuctionsMap.idl():  		int 
	if (item == NULL)	// server/zone/managers/auction/AuctionsMap.idl():  			return;
	return;
	// server/zone/managers/auction/AuctionsMap.idl():  		int count = playerVendorItemCount.get(item.getOwnerID());
	int count = (&playerVendorItemCount)->get(item->getOwnerID());
	// server/zone/managers/auction/AuctionsMap.idl():  		count = count - 1;
	count = count - 1;
	// server/zone/managers/auction/AuctionsMap.idl():  			playerVendorItemCount.put(item.getOwnerID(), count);
	if (count < 1)	// server/zone/managers/auction/AuctionsMap.idl():  			playerVendorItemCount.drop(item.getOwnerID());
	(&playerVendorItemCount)->drop(item->getOwnerID());

	else 	// server/zone/managers/auction/AuctionsMap.idl():  			playerVendorItemCount.put(item.getOwnerID(), count);
	(&playerVendorItemCount)->put(item->getOwnerID(), count);
	// server/zone/managers/auction/AuctionsMap.idl():  		vendorItems.drop(objectID);
	(&vendorItems)->drop(objectID);
}

AuctionItem* AuctionsMapImplementation::getVendorItem(unsigned long long objectID) {
	// server/zone/managers/auction/AuctionsMap.idl():  		return vendorItems.get(objectID);
	return (&vendorItems)->get(objectID);
}

AuctionItem* AuctionsMapImplementation::getVendorItem(int index) {
	// server/zone/managers/auction/AuctionsMap.idl():  		return vendorItems.get(index);
	return (&vendorItems)->get(index);
}

void AuctionsMapImplementation::increasePlayerVendorCount(unsigned long long playerID) {
	// server/zone/managers/auction/AuctionsMap.idl():  		playerVendorCount.put(playerID, playerVendorCount.get(playerID) + 1);
	(&playerVendorCount)->put(playerID, (&playerVendorCount)->get(playerID) + 1);
}

void AuctionsMapImplementation::decreasePlayerVendorCount(unsigned long long playerID) {
	// server/zone/managers/auction/AuctionsMap.idl():  		int count = playerVendorCount.get(playerID) - 1;
	int count = (&playerVendorCount)->get(playerID) - 1;
	// server/zone/managers/auction/AuctionsMap.idl():  		playerVendorCount.
	if (count <= 0)	// server/zone/managers/auction/AuctionsMap.idl():  			playerVendorCount.drop(playerID);
	(&playerVendorCount)->drop(playerID);
	// server/zone/managers/auction/AuctionsMap.idl():  		playerVendorCount.put(playerID, count);
	(&playerVendorCount)->put(playerID, count);
}

int AuctionsMapImplementation::getPlayerVendorCount(unsigned long long playerID) {
	// server/zone/managers/auction/AuctionsMap.idl():  		return playerVendorCount.get(playerID);
	return (&playerVendorCount)->get(playerID);
}

int AuctionsMapImplementation::getAuctionCount() {
	// server/zone/managers/auction/AuctionsMap.idl():  		return auctions.size();
	return (&auctions)->size();
}

bool AuctionsMapImplementation::containsAuction(unsigned long long objectID) {
	// server/zone/managers/auction/AuctionsMap.idl():  		return auctions.contains(objectID);
	return (&auctions)->contains(objectID);
}

void AuctionsMapImplementation::addBazaarItem(unsigned long long objectID, AuctionItem* item) {
	// server/zone/managers/auction/AuctionsMap.idl():  		auctions.put(objectID, item);
	(&auctions)->put(objectID, item);
	// server/zone/managers/auction/AuctionsMap.idl():  		playerAuctionCount.put(item.getOwnerID(), playerAuctionCount.get(item.getOwnerID()) + 1);
	(&playerAuctionCount)->put(item->getOwnerID(), (&playerAuctionCount)->get(item->getOwnerID()) + 1);
}

int AuctionsMapImplementation::getPlayerAuctionCount(unsigned long long objectID) {
	// server/zone/managers/auction/AuctionsMap.idl():  		return playerAuctionCount.get(objectID);
	return (&playerAuctionCount)->get(objectID);
}

void AuctionsMapImplementation::dropBazaarItem(unsigned long long objectID) {
	// server/zone/managers/auction/AuctionsMap.idl():  		AuctionItem item = auctions.get(objectID);
	AuctionItem* item = (&auctions)->get(objectID);
	// server/zone/managers/auction/AuctionsMap.idl():  		int 
	if (item == NULL)	// server/zone/managers/auction/AuctionsMap.idl():  			return;
	return;
	// server/zone/managers/auction/AuctionsMap.idl():  		int count = playerAuctionCount.get(item.getOwnerID());
	int count = (&playerAuctionCount)->get(item->getOwnerID());
	// server/zone/managers/auction/AuctionsMap.idl():  		count = count - 1;
	count = count - 1;
	// server/zone/managers/auction/AuctionsMap.idl():  			playerAuctionCount.put(item.getOwnerID(), count);
	if (count < 1)	// server/zone/managers/auction/AuctionsMap.idl():  			playerAuctionCount.drop(item.getOwnerID());
	(&playerAuctionCount)->drop(item->getOwnerID());

	else 	// server/zone/managers/auction/AuctionsMap.idl():  			playerAuctionCount.put(item.getOwnerID(), count);
	(&playerAuctionCount)->put(item->getOwnerID(), count);
	// server/zone/managers/auction/AuctionsMap.idl():  		auctions.drop(objectID);
	(&auctions)->drop(objectID);
}

AuctionItem* AuctionsMapImplementation::getBazaarItem(unsigned long long objectID) {
	// server/zone/managers/auction/AuctionsMap.idl():  		return auctions.get(objectID);
	return (&auctions)->get(objectID);
}

AuctionItem* AuctionsMapImplementation::getBazaarItem(int index) {
	// server/zone/managers/auction/AuctionsMap.idl():  		return auctions.get(index);
	return (&auctions)->get(index);
}

bool AuctionsMapImplementation::checkInStockroom(unsigned long long objectID) {
	// server/zone/managers/auction/AuctionsMap.idl():  		AuctionItem item = vendorItems.get(objectID);
	AuctionItem* item = (&vendorItems)->get(objectID);
	// server/zone/managers/auction/AuctionsMap.idl():  		return item.isInStockroom();
	return item->isInStockroom();
}

VectorMap<unsigned long long, ManagedReference<AuctionItem* > >* AuctionsMapImplementation::getBazaarItems() {
	// server/zone/managers/auction/AuctionsMap.idl():  		return auctions;
	return (&auctions);
}

VectorMap<unsigned long long, ManagedReference<AuctionItem* > >* AuctionsMapImplementation::getVendorItems() {
	// server/zone/managers/auction/AuctionsMap.idl():  		return vendorItems;
	return (&vendorItems);
}

/*
 *	AuctionsMapAdapter
 */

AuctionsMapAdapter::AuctionsMapAdapter(AuctionsMapImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* AuctionsMapAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_GETVENDORITEMCOUNT__:
		resp->insertSignedInt(getVendorItemCount());
		break;
	case RPC_CONTAINSVENDORITEM__LONG_:
		resp->insertBoolean(containsVendorItem(inv->getUnsignedLongParameter()));
		break;
	case RPC_ADDVENDORITEM__LONG_AUCTIONITEM_:
		addVendorItem(inv->getUnsignedLongParameter(), (AuctionItem*) inv->getObjectParameter());
		break;
	case RPC_GETPLAYERVENDORITEMCOUNT__LONG_:
		resp->insertSignedInt(getPlayerVendorItemCount(inv->getUnsignedLongParameter()));
		break;
	case RPC_DROPVENDORITEM__LONG_:
		dropVendorItem(inv->getUnsignedLongParameter());
		break;
	case RPC_GETVENDORITEM__LONG_:
		resp->insertLong(getVendorItem(inv->getUnsignedLongParameter())->_getObjectID());
		break;
	case RPC_GETVENDORITEM__INT_:
		resp->insertLong(getVendorItem(inv->getSignedIntParameter())->_getObjectID());
		break;
	case RPC_INCREASEPLAYERVENDORCOUNT__LONG_:
		increasePlayerVendorCount(inv->getUnsignedLongParameter());
		break;
	case RPC_DECREASEPLAYERVENDORCOUNT__LONG_:
		decreasePlayerVendorCount(inv->getUnsignedLongParameter());
		break;
	case RPC_GETPLAYERVENDORCOUNT__LONG_:
		resp->insertSignedInt(getPlayerVendorCount(inv->getUnsignedLongParameter()));
		break;
	case RPC_GETAUCTIONCOUNT__:
		resp->insertSignedInt(getAuctionCount());
		break;
	case RPC_CONTAINSAUCTION__LONG_:
		resp->insertBoolean(containsAuction(inv->getUnsignedLongParameter()));
		break;
	case RPC_ADDBAZAARITEM__LONG_AUCTIONITEM_:
		addBazaarItem(inv->getUnsignedLongParameter(), (AuctionItem*) inv->getObjectParameter());
		break;
	case RPC_GETPLAYERAUCTIONCOUNT__LONG_:
		resp->insertSignedInt(getPlayerAuctionCount(inv->getUnsignedLongParameter()));
		break;
	case RPC_DROPBAZAARITEM__LONG_:
		dropBazaarItem(inv->getUnsignedLongParameter());
		break;
	case RPC_GETBAZAARITEM__LONG_:
		resp->insertLong(getBazaarItem(inv->getUnsignedLongParameter())->_getObjectID());
		break;
	case RPC_GETBAZAARITEM__INT_:
		resp->insertLong(getBazaarItem(inv->getSignedIntParameter())->_getObjectID());
		break;
	case RPC_CHECKINSTOCKROOM__LONG_:
		resp->insertBoolean(checkInStockroom(inv->getUnsignedLongParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

int AuctionsMapAdapter::getVendorItemCount() {
	return ((AuctionsMapImplementation*) impl)->getVendorItemCount();
}

bool AuctionsMapAdapter::containsVendorItem(unsigned long long objectID) {
	return ((AuctionsMapImplementation*) impl)->containsVendorItem(objectID);
}

void AuctionsMapAdapter::addVendorItem(unsigned long long objectID, AuctionItem* item) {
	((AuctionsMapImplementation*) impl)->addVendorItem(objectID, item);
}

int AuctionsMapAdapter::getPlayerVendorItemCount(unsigned long long objectID) {
	return ((AuctionsMapImplementation*) impl)->getPlayerVendorItemCount(objectID);
}

void AuctionsMapAdapter::dropVendorItem(unsigned long long objectID) {
	((AuctionsMapImplementation*) impl)->dropVendorItem(objectID);
}

AuctionItem* AuctionsMapAdapter::getVendorItem(unsigned long long objectID) {
	return ((AuctionsMapImplementation*) impl)->getVendorItem(objectID);
}

AuctionItem* AuctionsMapAdapter::getVendorItem(int index) {
	return ((AuctionsMapImplementation*) impl)->getVendorItem(index);
}

void AuctionsMapAdapter::increasePlayerVendorCount(unsigned long long playerID) {
	((AuctionsMapImplementation*) impl)->increasePlayerVendorCount(playerID);
}

void AuctionsMapAdapter::decreasePlayerVendorCount(unsigned long long playerID) {
	((AuctionsMapImplementation*) impl)->decreasePlayerVendorCount(playerID);
}

int AuctionsMapAdapter::getPlayerVendorCount(unsigned long long playerID) {
	return ((AuctionsMapImplementation*) impl)->getPlayerVendorCount(playerID);
}

int AuctionsMapAdapter::getAuctionCount() {
	return ((AuctionsMapImplementation*) impl)->getAuctionCount();
}

bool AuctionsMapAdapter::containsAuction(unsigned long long objectID) {
	return ((AuctionsMapImplementation*) impl)->containsAuction(objectID);
}

void AuctionsMapAdapter::addBazaarItem(unsigned long long objectID, AuctionItem* item) {
	((AuctionsMapImplementation*) impl)->addBazaarItem(objectID, item);
}

int AuctionsMapAdapter::getPlayerAuctionCount(unsigned long long objectID) {
	return ((AuctionsMapImplementation*) impl)->getPlayerAuctionCount(objectID);
}

void AuctionsMapAdapter::dropBazaarItem(unsigned long long objectID) {
	((AuctionsMapImplementation*) impl)->dropBazaarItem(objectID);
}

AuctionItem* AuctionsMapAdapter::getBazaarItem(unsigned long long objectID) {
	return ((AuctionsMapImplementation*) impl)->getBazaarItem(objectID);
}

AuctionItem* AuctionsMapAdapter::getBazaarItem(int index) {
	return ((AuctionsMapImplementation*) impl)->getBazaarItem(index);
}

bool AuctionsMapAdapter::checkInStockroom(unsigned long long objectID) {
	return ((AuctionsMapImplementation*) impl)->checkInStockroom(objectID);
}

/*
 *	AuctionsMapHelper
 */

AuctionsMapHelper* AuctionsMapHelper::staticInitializer = AuctionsMapHelper::instance();

AuctionsMapHelper::AuctionsMapHelper() {
	className = "AuctionsMap";

	Core::getObjectBroker()->registerClass(className, this);
}

void AuctionsMapHelper::finalizeHelper() {
	AuctionsMapHelper::finalize();
}

DistributedObject* AuctionsMapHelper::instantiateObject() {
	return new AuctionsMap(DummyConstructorParameter::instance());
}

DistributedObjectServant* AuctionsMapHelper::instantiateServant() {
	return new AuctionsMapImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* AuctionsMapHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new AuctionsMapAdapter((AuctionsMapImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}
