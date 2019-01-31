#pragma once

#include "Image.h"
#include "SForm.h"

class TransformedImage : public Image
{
private:
	//Tranformations of coordinates
	SForm transform;

	//Additive constant
	signed char b;
public:
	TransformedImage(const Image& im, const SForm& s, signed char b) :
		Image(im), transform(s), b(b) {}

	~TransformedImage() {}

	virtual unsigned char operator() (unsigned int x, unsigned int y) const override;
};