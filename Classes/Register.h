//
//  Register.h
//  mt1804
//
//  Created by bartle on 3/23/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#include "Tetrad.h"
#ifndef REGISTER_H
#define REGISTER_H

class Register
{
	Tetrad content[8];
	Tetrad currentTetrad;
public:
	Register();
	~Register();
	Register(const Register& reg);
	void loadToRegister(int tetradNum, int number);
	int getFromTetrad(int tetradNum);
};

#endif