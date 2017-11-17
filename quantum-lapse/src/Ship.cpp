#include "Ship.hpp"

Ship::Ship(){
}

Ship::Ship(const PixelArray& px){
	this->pixels = px;
	this->shader.Init(this->pixels.getVertex(), this->pixels.size());
	
}

const float* Ship::getVertex() const{
	return this->pixels.getVertex();
}

const unsigned int& Ship::size() const{
	return this->pixels.size();
}
