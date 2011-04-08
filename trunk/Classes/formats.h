/*
 *  formats.h
 *  mt1804
 *
 *  Created by bartle on 4/8/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef FORMATS_H
#define FORMATS_H

typedef enum operation 
{
	RplusS,
	SminusR,
	RminusS,
	RunionS,
	RintersectS,
	notRintersectS,
	Rmod2S,
	notRmod2S
};

typedef enum operandsSource
{
	AQ,
	AB,
	_0Q,
	_0B,
	_0A,
	DA,
	DQ,
	D0
};


typedef enum operandsReciever
{
	FtoQ,
	FtoF,
	FtoBA,	// F -> B, A -> Y
	FtoBF,	// F -> B, F -> Y;
	FQd2toBQ, //F / 2 -> B, Q / 2 -> Q
	Fd2toB,
	FQmul2toBQ, // F*2 -> B, Q*2 -> Q
	Fmul2toB
};

typedef enum nextAddress
{
	JmpZ0,
	Jmp,
	Next,
	ToAddress,
	CallZ0,
	Call,
	Ret,
	ToAddrInStack,
	PopZ1,
	Push,
	Pop,
	PopC41,
	JmpZ1,
	JmpF31,
	JmpOVR,
	JmpC41
};

#endif