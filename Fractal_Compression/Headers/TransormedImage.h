#pragma once
#include "Image.h"
#include "S_Form.h"

class TransormedImage : public Image
{
private:
	S_Form transform;
public:
	TransormedImage(Image& im, const S_Form& s) :
		Image(im), transform(s) {}

	~TransormedImage() {}

	virtual unsigned char& operator() (unsigned int x, unsigned int y) override;
	virtual unsigned char operator() (unsigned int x, unsigned int y) const override;
};

