/*
 *  Mux.cpp
 *  mt1804
 *
 *  Created by bartle on 4/5/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Multiplexer.h"

Multiplexer::Multiplexer()
{
}

Multiplexer::~Multiplexer()
{
}

int Multiplexer::getNumber()
{
	return r[2]*4+r[1]*2+r[0]*1;
}

void Multiplexer::setBool(int n, bool value)
{
	r[n] = value;
}