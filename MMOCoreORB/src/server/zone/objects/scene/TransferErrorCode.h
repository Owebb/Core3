/*
 * TransferErrorCodes.h
 *
 *  Created on: 03/03/2010
 *      Author: victor
 */

#ifndef TRANSFERERRORCODES_H_
#define TRANSFERERRORCODES_H_

class TransferErrorCode {
public:
	const static int SUCCESS = 0;
	const static int SLOTOCCUPIED = 1;
	const static int PLAYERUSEMASKERROR = 2;
	const static int INVALIDTYPE = 3;
	const static int BAITONLY = 4;
	const static int NOTENOUGHENCUMBRANCE = 5;
	const static int CANTNESTOBJECT = 6;
	const static int TOOMANYITEMSINHOUSE = 7;
	const static int CANTADDTOITSELF = 8;
	const static int UNKNOWNCONTAIMENTTYPE = 9;
	const static int CONTAINERFULL = 10;
};


#endif /* TRANSFERERRORCODES_H_ */