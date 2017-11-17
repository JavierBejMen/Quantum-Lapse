#include "PixelArray.hpp"

#include <cstring>
#include <stdexcept>
#include <iostream>

using namespace std;


void PixelArray::clear(){
	if(this->pixels != nullptr && this->vertex != nullptr){
		delete[] this->pixels;
		delete[] this->vertex;
	}
	this->n = 0;
}

void PixelArray::resize(const unsigned int& n){
		this->n = n;
		this->pixels = new Pixel[this->n];
		this->vertex = new float[this->n*2];
}

void PixelArray::copy(const PixelArray& otro){		
	resize(otro.n);

	memcpy(this->pixels, otro.pixels, this->n * sizeof(Pixel));
	memcpy(this->vertex, otro.vertex, this->n * 2 * sizeof(float));
}

PixelArray::PixelArray(){
	this->pixels = nullptr;
	this->vertex = nullptr;
	this->n = 0;
}

PixelArray::PixelArray(const PixelArray& otro){
	copy(otro);
}

PixelArray::PixelArray(const float* vert, unsigned int& n){
	if(n%2 != 0 || vert == nullptr){
		throw runtime_error("Error en constructor mediante array,"
							" o bien n no es múltiplo de 2, o el array es nulo");
	}
	
	resize(n/2);
	
	memcpy(this->vertex, vert, n * sizeof(float));
	
	
	for(unsigned int i = 0; i < this->n; ++i){
		this->pixels[i] = Pixel(0, 0, 0, 0, 0, false, this->vertex[i+(i)], this->vertex[i+1+(i)]);
	}
}

PixelArray::~PixelArray(){
	clear();
}

const PixelArray& PixelArray::operator =(const PixelArray& otro){
	if(this!=&otro){
		clear();
		copy(otro);
	}
	return *this;
}

const float* PixelArray::getVertex() const{
	return this->vertex;
}

const unsigned int& PixelArray::size() const{
	return this->n;
}












	
