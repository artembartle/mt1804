//
//  Tetrad.h
//  mt1804
//
//  Created by bartle on 3/23/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#ifndef TETRAD_H
#define TETRAD_H

class Tetrad
{
	bool t[4];
public:
	Tetrad();
	~Tetrad();
	Tetrad(const Tetrad& tetr);
	void setBool(int n, bool value);
	int getNumber();
};

#endif