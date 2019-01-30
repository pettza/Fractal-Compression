#include "TransormedImage.h"

unsigned char & TransormedImage::operator()(unsigned int x, unsigned int y)
{
	auto point = transform(x, y);
	auto newX = point.first;
	auto newY = point.second;
	return (*pixels)[orgX + newX + (orgY + newY) * width];
}

unsigned char TransormedImage::operator()(unsigned int x, unsigned int y) const
{
	return 0;
}
