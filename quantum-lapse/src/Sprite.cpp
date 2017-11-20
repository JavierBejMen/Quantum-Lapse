#include "Sprite.hpp"

#include "gl_header.h"

using namespace std;

Sprite::Sprite(const string& name){
	this->name = name;
}

void Sprite::Generate(const ImageBuffer& img){
	this->width = img.getWidth();
	this->height = img.getHeight();
	
	
	glGenTextures(1, &this->ID);
	
	glBindTexture(GL_TEXTURE_2D, this->ID);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, img.getWidth(), img.getHeight(), 0,
		GL_BGRA, GL_UNSIGNED_BYTE, img.getRaw());
		
	glBindTexture(GL_TEXTURE_2D, 0);
}

const unsigned int& Sprite::getID() const{
	return this->ID;
}
