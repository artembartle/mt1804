//
//  Register.m
//  mt1804
//
//  Created by bartle on 3/23/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Register.h"

Register::Register() 
{
	
}

Register::~Register()
{
}


Register& Register::operator=(const Register& reg)
{
	for (int i = 0; i < 8; i++)
		(*this).content[i] = reg.content[i];
	
	(*this).currentTetrad = reg.currentTetrad;
	return *this;
}

void Register::loadToRegister(int tetradNum, int number)
{
	int currValue = number;
	for(int i = 0; i < 4; i++)
	{
		currentTetrad.setBool(i, currValue % 2);
		currValue /= 2;
	}
	content[tetradNum] = currentTetrad;
}

int Register::getFromTetrad(int tetradNum)
{
	return content[tetradNum].getNumber();
}

void Register::cleanRegister()
{
	for (int i = 0; i < 8; i++)
		loadToRegister(i, 0);
	
}