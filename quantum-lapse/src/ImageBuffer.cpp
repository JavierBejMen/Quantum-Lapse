#include "ImageBuffer.hpp"

#include <png.h>

using namespace std;

ImageBuffer::ImageBuffer(){
	this->width = 0;
	this->height = 0;
	this->pixels = nullptr;
}
