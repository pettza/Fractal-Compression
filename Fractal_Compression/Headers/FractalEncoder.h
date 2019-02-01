#pragma once

#include "constants.h"
#include "FractalCode.h"
#include "SForm.h"
#include "Image.h"
#include <vector>
#include <array>

using namespace std;

class FractalEncoder
{
private:
	static const array<SForm, 8> sForms;

	//Finds best fractal code for a destination region
	static FractalCode matchDestRef(const Image& destReg, const Image& refIm, const Image& refMeans);
public:
	FractalEncoder() = delete;

	//Encodes the image as a Partitioned Iterated Function System
	static vector<FractalCode> Encode(const Image& destIm);
	
	~FractalEncoder() {};
};