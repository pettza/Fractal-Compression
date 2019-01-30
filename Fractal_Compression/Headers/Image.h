#pragma once

#include <memory>
#include <vector>
#include <string>

using namespace std;

/*
Class to hold image data
For the time being only grayscale images are supported
*/
class Image
{
//Member variables
protected:
	//If an image is part of another, than this is its origin relative to the other
	unsigned int orgX;
	unsigned int orgY;
	
	//Image dimensions
	unsigned int width;
	unsigned int height;
	
	//The image is stored by rows
	shared_ptr<vector<unsigned char>> pixels;

//Member functions
public:
	//Image from file
	Image(string filename);

	Image(unsigned int width, unsigned int height, unsigned char fillColour = 0) : 
		orgX(0), orgY(0), width(width), height(height), 
		pixels(new vector<unsigned char>(width*height, fillColour)){}

	//Returns a part of the image
	Image(unsigned int orgX, unsigned int orgY, unsigned int width, unsigned int height, Image& otherImage) :
		orgX(orgX), orgY(orgY), width(width), height(height), pixels(otherImage.pixels) {}

	~Image() {}

	//Getters
	unsigned int GetWidth() const { return width; }
	unsigned int GetHeight() const { return height; }

	virtual unsigned char& operator() (unsigned int x, unsigned int y);
	virtual unsigned char operator() (unsigned int x, unsigned int y) const;

	unsigned char Mean() const;
};

unsigned long L2Squared(const Image& im1, const Image& im2);