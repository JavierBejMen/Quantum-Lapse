#include "ImageBuffer.hpp"

#include "FileWrapper.hpp"

#include <png.h>
#include <stdexcept>
#include <fstream>


using namespace std;

ImageBuffer::ImageBuffer(){
	this->width = 0;
	this->height = 0;
	this->pixels = nullptr;
}

const utils::FileErrLog& ImageBuffer::ReadPNG(const string& path){
	
	//Check if file is png
	fstream file(path.c_str(), std::fstream::in | std::fstream::binary);
	if(!file){
		errLog.setLog("ReadPNG err: Can't open file", path, false);
		
		return errLog;
	}
	
	png_byte pngsig[PNGSIGSIZE];
	
	file.read((char *)pngsig, PNGSIGSIZE);
	if(!file.good()){
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
	
	
	
	
	
	
	
	
		
	
	
	
	
	
}
