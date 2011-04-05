/*
 *  Mux.h
 *  mt1804
 *
 *  Created by bartle on 4/5/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef MULTIPLEXER_H
#define MULTIPLEXER_H

class Multiplexer 
{
	bool r[3];
public:
	Multiplexer();
	~Multiplexer();
	int getNumber();
	void setBool(int n, bool value);
};

#endif