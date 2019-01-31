#pragma once

struct FractalCode
{
public:
	unsigned int destX; //Destinarion region x component
	unsigned int destY; //Destinarion region y component
	unsigned int refX; //Reference region x component
	unsigned int refY; //Reference region y component
	signed char b; //Intensity beta-value
	unsigned char s; //SForm index

public:
	FractalCode(unsigned int destX = 0, unsigned int destY = 0,
		unsigned int refX = 0, unsigned int refY = 0,
		unsigned char b = 0, unsigned char s = 0) :
		destX(destX), destY(destY), refX(refX), refY(refY), b(b), s(s) {}

	~FractalCode() {}
};

