/*
 *  MicrocommandsMemory.h
 *  mt1804
 *
 *  Created by bartle on 4/5/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef MICROCOMMANDSMEMORY_H
#define MICROCOMMANDSMEMORY_H

#include "Register.h"

class CommandAnalizer;

class MicrocommandsMemory
{
	friend class CommandAnalizer;
	Register* microCommands;
public:
	MicrocommandsMemory();
	~MicrocommandsMemory();
	void loadMicroCommandToAddress(const Register& microCmd, int address);
	int getDataFromTetradAtRegister(int numRegister, int numTetrad);
};

extern MicrocommandsMemory pmk;

#endif