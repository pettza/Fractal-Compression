#pragma once

#include <memory>
#include <vector>
#include <string>

using namespace std;

/*
Class to hold image data, doesn't allow editing
For the time being only grayscale images are supported
*/
class Image
{
//Member variables
protected:
	//If an image is part of another, than this is its origin relative to the other
	unsigned int orgX;
	unsigned int orgY;
	//and the other's width
	unsigned int realWidth;

	//Image dimensions
	unsigned int width;
	unsigned int height;
	
	//The image is stored by rows
	shared_ptr<vector<unsigned char>> pixels;

//Member functions
private:
	//Returns a part of the image
	Image(unsigned int orgX, unsigned int orgY, unsigned int width, unsigned int height, const Image& otherImage) :
		orgX(orgX), orgY(orgY), realWidth(otherImage.realWidth),
		width(width), height(height), pixels(otherImage.pixels) {}

protected:
	//For use by derived classes
	Image(unsigned int width = 1, unsigned int height = 1, unsigned char fillColour = 0) :
		orgX(0), orgY(0), realWidth(width), width(width), height(height),
		pixels(new vector<unsigned char>(width*height, fillColour)) {}

public:
	//Image from file
	Image(string filename);

	virtual ~Image() {}

	//Returns a part of the image
	Image subImage(unsigned int orgX, unsigned int orgY, unsigned int width, unsigned int height) const;

	//Getters
	unsigned int getWidth() const { return width; }
	unsigned int getHeight() const { return height; }

	//Retrieves pixel value
	virtual unsigned char operator() (unsigned int x, unsigned int y) const;

	//Computes mean
	unsigned char mean() const;
};

unsigned long L2Squared(const Image& im1, const Image& im2);