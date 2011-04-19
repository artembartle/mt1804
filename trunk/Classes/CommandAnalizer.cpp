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
#include <stdio.h>
#include <stdlib.h>

CommandAnalizer* analizer;

CommandAnalizer::CommandAnalizer()
{
	RON = (int*)calloc(8, sizeof(int));
}

CommandAnalizer::~CommandAnalizer()
{
	
}

void CommandAnalizer::performMicroCommand(Register* microCommand)
{
	if (commandIndex < 16) 
	{
		fillIn(microCommand);
		getOperandsSource();
		F = performOperation();
		getResultReciever();
		getNextAddress();
	}
}

void CommandAnalizer::run()
{
	commandIndex = 0;
	printRON();
	performMicroCommand(&pmk.microCommands[0]);
}

void CommandAnalizer::nextCommand()
{
	printRON();
	commandIndex++;
	performMicroCommand(&pmk.microCommands[commandIndex]);
}

void CommandAnalizer::jumpToCommand(int commandNum)
{
	printRON();
	performMicroCommand(&pmk.microCommands[commandNum]);
}

void CommandAnalizer::fillIn(Register* command)
{
	D = command->getFromTetrad(0);
	B = command->getFromTetrad(1);
	A = command->getFromTetrad(2);
	funcALU = command->getFromTetrad(3);
	source = command->getFromTetrad(4);
	reciever = command->getFromTetrad(5);
	nextAddr = command->getFromTetrad(6);
	jmpAddr = command->getFromTetrad(7);
	printf("Microcommand#%d: %d %d %d %d %d %d %d %d\n", commandIndex, D,B,A,funcALU, source, reciever, nextAddr, jmpAddr);
}

int CommandAnalizer::performOperation()
{
	C0 = funcALU / 8;
	
	switch (funcALU % 8) 
	{
		case RplusS:
			return R+S+C0;
		case SminusR:
			return S-R+C0; 
		case RminusS:
			return R-S+C0;
		case RunionS:
			return R|S;
		case RintersectS:
			return R&S;
		case notRintersectS:
			return (not R)&S;
		case Rmod2S:
			return R xor S;
		case notRmod2S:
			return not(R xor S);
		default:
			break;
	}
	
	return -1;
}

void CommandAnalizer::getOperandsSource()
{
	S0 = source / 8;
	
	switch (source % 8) 
	{
		case AQ:
		{ R = RON[A]; S = Q; }
			break;
		case AB:
		{ R = RON[A]; S = RON[B]; }
			break;
		case _0Q:
		{ R = 0; S = Q; }
			break;
		case _0B:
		{ R = 0; S = RON[B]; }
			break;
		case _0A:
		{ R = 0; S = RON[A]; }
			break;
		case DA:
		{ R = D; S = RON[A]; }
			break;
		case DQ:
		{ R = D; S = Q; }
			break;
		case D0:
		{ R = D; S = 0; }
			break;

		default:
			break;
	}
}

void CommandAnalizer::getResultReciever()
{
	S1 = reciever / 8;
	
	switch (reciever % 8) 
	{
		case FtoQ:
		{ Q = F; Y = F; }
			break;
		case FtoF:
		{ Y = F; }
			break;
		case FtoBA:
		{ RON[B] = F; Y = A; }
			break;
		case FtoBF:
		{ RON[B] = F; Y = F; }
			break;
		case FQd2toBQ:
		{ RON[B] = F / 2; Q = Q / 2; Y = F; }
			break;
		case Fd2toB:
		{ RON[B] = F / 2; Y = F; }
			break;
		case FQmul2toBQ:
		{ RON[B] = F * 2; Q = Q * 2; Y = F; }
			break;
		case Fmul2toB:
		{ RON[B] = F * 2; Y = F; }
			break;
		default:
			break;
	}
}

#pragma mark TODO: Call subprogramm & Ret

void CommandAnalizer::getNextAddress()
{
	switch (nextAddr) 
	{
		case JmpZ0:
			if (!Z)
				jumpToCommand(jmpAddr);
			break;
			
		case Jmp:
			jumpToCommand(jmpAddr);
			break;
			
		case Next:
			nextCommand();
			break;
			
		case ToAddress:
			jumpToCommand(SA11_SA8);
			break;
			
		case CallZ0:
			break;
		case Call:
			break;
		case Ret:
			break;
		case ToAddrInStack:
			break;
		case PopZ1:
			break;
		case Push:
			break;
		case Pop:
			break;
		case PopC41:
			break;
			
		case JmpZ1:
			if (Z)
				jumpToCommand(jmpAddr);
			break;
			
		case JmpF31:
			if (F3)
				jumpToCommand(jmpAddr);
			break;

		case JmpOVR:
			if (OVR)
				jumpToCommand(jmpAddr);
			break;
			
		case JmpC41:
			if (C4)
				jumpToCommand(jmpAddr);
			break;
			
		default:
			break;
	}
}

void CommandAnalizer::printRON()
{
	printf("%d) ", commandIndex);
	for (int i = 0; i < 8; i++)
		printf("%d ", RON[i]);
	printf("\n");
}
