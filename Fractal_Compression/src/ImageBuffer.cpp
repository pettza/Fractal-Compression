#include "ImageBuffer.h"

unsigned char & ImageBuffer::operator()(unsigned int x, unsigned int y)
{
	return (*pixels)[orgX + x + (orgY + y) * width];
}