//
//  Register.h
//  mt1804
//
//  Created by bartle on 3/23/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#include "Tetrad.h"

//class Tetrad;

class Register
{
	Tetrad content[8];
	Tetrad currentTetrad;
public:
	Register();
	~Register();
}