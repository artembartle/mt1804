/*
 *  CommandAnalizer.cpp
 *  mt1804
 *
 *  Created by bartle on 4/7/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "CommandAnalizer.h"
#include "MicrocommandsMemory.h"

CommandAnalizer* analizer;

CommandAnalizer::CommandAnalizer()
{
	commands = new std::queue<Register*>();
}

CommandAnalizer::~CommandAnalizer()
{
	delete commands;
}

void CommandAnalizer::loadMicroCommand(Register* microCommand)
{
	commands->push(microCommand);
}

void CommandAnalizer::run()
{
	
}

void CommandAnalizer::fillIn(Register* command)
{
	d = command->getFromTetrad(0);
	b = command->getFromTetrad(1);
	a = command->getFromTetrad(2);
	funcALU = command->getFromTetrad(3);
	source = command->getFromTetrad(4);
	reciever = command->getFromTetrad(5);
	nextAddr = command->getFromTetrad(6);
	jmpAddr = command->getFromTetrad(7);
}