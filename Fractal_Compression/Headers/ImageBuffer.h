#pragma once

#include "Image.h"

/*
Class to hold image data.
In contrast to Image, allows editing
*/
class ImageBuffer : public Image
{
public:
	ImageBuffer(string filename) :Image(filename) {}

	ImageBuffer(unsigned int width = 1, unsigned int height = 1, unsigned char fillColour = 0) : 
		Image(width, height, fillColour) {}
	
	~ImageBuffer() {}

	unsigned char& operator() (unsigned int x, unsigned int y);
};