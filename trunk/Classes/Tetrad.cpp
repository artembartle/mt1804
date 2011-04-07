//
//  Tetrad.mm
//  mt1804
//
//  Created by bartle on 3/23/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Tetrad.h"

Tetrad::Tetrad()
{
}

Tetrad::~Tetrad()
{
}

Tetrad& Tetrad::operator=(const Tetrad& other)
{
	for (int i = 0; i < 4; i++)
		(*this).setBool(i, other.t[i]);
	return *this;
}

void Tetrad::setBool(int n, bool value)
{
	t[n] = value;
}

int Tetrad::getNumber()
{
	return t[3]*8+t[2]*4+t[1]*2+t[0]*1;
}