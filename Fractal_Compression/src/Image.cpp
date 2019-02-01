#include "Image.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <stdexcept>

using namespace std;

Image::Image(string filename)
{
	int w, h, nChannels;
	
	//load data
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(filename.c_str(), &w, &h, &nChannels, 1);

	//if image loaded correctly
	if (data)
	{
		realWidth = w;
		width = w;
		height = h;

		//copy data
		pixels = shared_ptr<vector<unsigned char>>(new vector<unsigned char>(data, data + width*height));

		//free data
		stbi_image_free(data);
	}
	else throw runtime_error("Image constructor: Failed to load image");
}

Image Image::subImage(unsigned int orgX, unsigned int orgY, unsigned int width, unsigned int height) const
{
	return Image(orgX, orgY, width, height, *this);
}

unsigned char Image::operator()(unsigned int x, unsigned int y) const
{
	return (*pixels)[orgX + x + (orgY + y) * realWidth];
}

unsigned char Image::mean() const
{
	unsigned long mean = 0;
	for (unsigned int y = 0; y < height; y++) {
		for (unsigned int x = 0; x < width; x++) {
			mean += (*this)(x, y);
		}
	}

	return unsigned char(mean / (width*height));
}

unsigned long L2Squared(const Image & im1, const Image & im2)
{
	if (im1.getHeight() != im2.getHeight() || im1.getWidth() != im2.getWidth())
	{
		throw logic_error("L2Squared: Images don't have same dimensions");
	}
	else
	{
		unsigned int height = im1.getHeight();
		unsigned int width = im1.getWidth();
		unsigned long L2 = 0;
		for (unsigned int y = 0; y < height; y++) {
			for (unsigned int x = 0; x < width; x++) {
				unsigned long px1 = im1(x, y);
				unsigned long px2 = im2(x, y);

				L2 += (px1 - px2) * (px1 - px2);
			}
		}

		return L2;
	}
}