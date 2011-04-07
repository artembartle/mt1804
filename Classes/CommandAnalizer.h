/*
 *  CommandAnalizer.h
 *  mt1804
 *
 *  Created by bartle on 4/7/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef COMMANDANALIZER_H
#define COMMANDANALIZER_H

#include "Register.h"
#include <queue>

using namespace std;

class CommandAnalizer
{
	int d;
	int b;
	int a;
	int funcALU;
	int source;
	int reciever;
	int nextAddr;
	int jmpAddr;
	
	std::queue<Register*>* commands;
public:
	CommandAnalizer();
	~CommandAnalizer();
	void loadMicroCommand(Register* microCommand);
	void run();
	void fillIn(Register* command);
};

extern CommandAnalizer* analizer;

#endif
