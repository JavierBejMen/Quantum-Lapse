#include "ImageBuffer.hpp"

#include "FileWrapper.hpp"
#include "utils.hpp"

#include <png.h>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <iostream>


using namespace std;

void ImageBuffer::clear(){
	delete[] this->pixels;
}

void ImageBuffer::resize(const unsigned int& width, const unsigned int& height){
	if(this->pixels != nullptr)
		this->clear();
		
	this->width = width;
	this->height = height;
	
	this->pixels = new uint32_t[width * height];
}

ImageBuffer::~ImageBuffer(){
	if(this->pixels != nullptr)
		this->clear();
}


ImageBuffer::ImageBuffer(){
	this->width = 0;
	this->height = 0;
	this->pixels = nullptr;
}



const utils::FileErrLog& ImageBuffer::ReadPNG(const string& path){
	
	//Check if file is png
	utils::File file(path.c_str(), "rb");
	if(!file){
		errLog.setLog("ReadPNG err: Can't open file", path, false);
		
		return errLog;
	}
	
	png_byte pngsig[PNGSIGSIZE];
	
	fread((char *)pngsig, 1, PNGSIGSIZE, file);
	if(!file){
		errLog.setLog("ReadPNG err: Can't read signature file",path,false);
		
		return errLog;
	}
	
	if(png_sig_cmp(pngsig, 0, PNGSIGSIZE) != 0){
		errLog.setLog("ReadPNG err: Bad signature file",path,false);
		
		return errLog;
	}
	
	//Setup libpng
	png_struct *png = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
	if(!png){
		errLog.setLog("ReadPNG err: Couldn't create png_struct", path, false);
		
		return errLog;
	}
	
	png_info *info = png_create_info_struct(png);
	if(!info){
		errLog.setLog("ReadPNG err: Couldn't create png_info", path, false);
		png_destroy_read_struct(&png, nullptr, nullptr);
		
		return errLog;
	}
	
	if(setjmp(png_jmpbuf(png))){
		errLog.setLog("ReadPNG err: Error during init_io (setjmp call)", path, false);
		png_destroy_read_struct(&png, &info, nullptr);
		
		return errLog;
	}
	
	png_init_io(png, file);
	png_set_sig_bytes(png, PNGSIGSIZE);
	
	png_read_info(png, info);
	
	int width = png_get_image_width(png, info);
	int height = png_get_image_height(png, info);
	
	cout<<"width:"<<width<<endl;
	cout<<"height:"<<height<<endl;
	
	if(!width || !height){
		errLog.setLog("ReadPNG err: Error getting width or height", path, false);
		png_destroy_read_struct(&png, &info, nullptr);
		
		return errLog;
	}
	
	int colorType = png_get_color_type(png, info);
	int bitDepth = png_get_bit_depth(png, info);
	
	png_set_strip_16(png);
	png_set_packing(png);
	if(colorType == PNG_COLOR_TYPE_PALETTE)
		png_set_palette_to_rgb(png);
	if(colorType == PNG_COLOR_TYPE_GRAY && bitDepth < 8)
		png_set_expand_gray_1_2_4_to_8(png);
	if(colorType == PNG_COLOR_TYPE_GRAY || colorType == PNG_COLOR_TYPE_GRAY_ALPHA)
		png_set_gray_to_rgb(png);
	if(colorType & PNG_COLOR_MASK_COLOR)
		png_set_bgr(png);
	png_read_update_info(png, info);
	
	this->resize(width, height);
	vector<png_byte *> rows(height, nullptr);
	for(int i = 0; i < height; ++i){
		rows[i] = reinterpret_cast<png_byte *>(this->pixels + i * width);
	}
	
	png_read_image(png, &rows.front());
	
	// Clean up. The file will be closed automatically.
	png_destroy_read_struct(&png, &info, nullptr);
	
	errLog.setLog("",path,true);
	return errLog;
}

const uint32_t * ImageBuffer::getRaw() const{
	return this->pixels;
}

const unsigned int& ImageBuffer::getWidth() const{
	return this->width;
}

const unsigned int& ImageBuffer::getHeight() const{
	return this->height;
}
