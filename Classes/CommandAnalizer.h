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
#include "formats.h"
#include <objc/objc.h>

class CommandAnalizer
{
	int F,Y;
	int Q;
	int R,S,C0;
	int S0,S1;
	bool Z, F3, OVR, C4;
	
	int* RON;
	
	int D;
	int B;
	int A;
	int funcALU;
	int source;
	int reciever;
	int nextAddr;
	int jmpAddr;
	int SA11_SA8;
	int commandIndex;
	
	int commandsCount;
	
	Register* currCommand;
	id viewController;
	
	bool step;
	
	void fillIn(Register* command);
	void getOperandsSource();
	void getResultReciever();
	void getNextAddress();
	int performOperation();
	void performMicroCommand(Register* microCommand);
	void nextCommand();
	void jumpToCommand(int commandNum);
	void printRON();
public:
	CommandAnalizer();
	~CommandAnalizer();
	void run();
	void setVC(id VC);
	void increaseCommandsCount(int n);
	int getCommandsCount();
	void setCommandsCount(int n);
};

extern CommandAnalizer* analizer;

#endif
