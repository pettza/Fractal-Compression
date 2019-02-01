#include "FractalEncoder.h"
#include "TransformedImage.h"
#include "ImageBuffer.h"
#include <limits>
#include <iostream>

const array<SForm, 8> FractalEncoder::sForms = SForm::GetS_Forms();

FractalCode FractalEncoder::matchDestRef(const Image& destReg, const Image& refIm, const Image& refMeans)
{
	FractalCode code;

	auto destMean = destReg.mean();
	
	unsigned long bestDist = ULONG_MAX;

	for (unsigned int y = 0; y < refMeans.getHeight(); y++) {
		for (unsigned int x = 0; x < refMeans.getWidth(); x++) {
			for (auto i = 0; i < 8; i++) {
				signed char b = destMean - refMeans(x, y);
				unsigned long dist = L2Squared(destReg, TransformedImage(refIm.subImage(x, y, N, N), sForms[i], b));
				if (dist < bestDist)
				{
					code.refX = x;
					code.refY = y;
					code.s = i;
					code.b = b;
				}
			}
		}
	}

	return code;
}

vector<FractalCode> FractalEncoder::Encode(const Image& destIm)
{
	//Result, vector of fractal codes
	vector<FractalCode> codes((destIm.getWidth() / N) * (destIm.getHeight() / N));

	//Reference image is the subsampled destination image
	ImageBuffer refIm(destIm.getWidth() / 2, destIm.getHeight() / 2);
	//Image to store the mean of the reference regions
	ImageBuffer refMeans(refIm.getWidth() - N, refIm.getHeight() - N);

	//Make reference image by averaging and applying gamma transformation
	for (unsigned int y = 0; y < refIm.getHeight(); y++) {
		for (unsigned int x = 0; x < refIm.getWidth(); x++) {
			//casting to long to avoid overflow
			unsigned long x0y0 = destIm(2 * x, 2 * y);
			unsigned long x1y0 = destIm(2 * x + 1, 2 * y);
			unsigned long x0y1 = destIm(2 * x, 2 * y + 1);
			unsigned long x1y1 = destIm(2 * x + 1, 2 * y + 1);
			refIm(x, y) = unsigned char ((x0y0 + x1y0 + x0y1 + x1y1) / 4);
		}
	}

	//Compute means
	for (unsigned int y = 0; y < refMeans.getHeight(); y++) {
		for (unsigned int x = 0; x < refMeans.getWidth(); x++) {
			refMeans(x, y) = refIm.subImage(x, y, N, N).mean();
		}
	}

	//Find best fractal code for each destination region
	auto it = codes.begin();
	for (unsigned int y = 0; y < destIm.getHeight(); y += N) {
		for (unsigned int x = 0; x < destIm.getWidth(); x += N) {
			*it = matchDestRef(destIm.subImage(x, y, N, N), refIm, refMeans);
			it->destX = x;
			it->destY = y;
			it++;
			cout << "x = " << x << ", " << "y = " << y << endl;
		}
	}

	return codes;
}