/*
 *  MicrocommandsMemory.cpp
 *  mt1804
 *
 *  Created by bartle on 4/5/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "MicrocommandsMemory.h"

MicrocommandsMemory pmk;

MicrocommandsMemory::MicrocommandsMemory()
{
	
}

MicrocommandsMemory::~MicrocommandsMemory()
{
	
}

void MicrocommandsMemory::loadMicroCommandToAddress(const Register& microCmd, int address)
{
	microCommands[address] = microCmd;
}

int MicrocommandsMemory::getDataFromTetradAtRegister(int numRegister, int numTetrad)
{
	return microCommands[numRegister].getFromTetrad(numTetrad);
}