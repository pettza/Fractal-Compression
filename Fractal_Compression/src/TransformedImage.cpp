#include "TransformedImage.h"

unsigned char TransformedImage::operator()(unsigned int x, unsigned int y) const
{
	auto point = transform(x, y);
	auto newX = point.first;
	auto newY = point.second;
	unsigned char pixel = Image::operator()(newX, newY);
	return (3 * pixel) / 4 + b;
}