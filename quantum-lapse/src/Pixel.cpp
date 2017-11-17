#include "Pixel.hpp"

#include <stdexcept>

using namespace std;

Pixel::Pixel(){
	this->weight = 0;
	this->structural = 0;
	this->health = 0;
	this->complexity = 0;
	this->resistance = 0;
	this->occupied = false;
	this->posX = 0;
	this->posY = 0;
}

Pixel::Pixel(const int& w, const int& s, const double& h, const double& c, 
		const double& r, const bool& o, const float& x, const float& y)
{
	if(!checkParam(w, s, h, c, r, o, x, y))
		throw runtime_error("Error, bad params on Pixel constructor");
	
	this->weight = w;
	this->structural = s;
	this->health = h;
	this->complexity = c;
	this->resistance = r;
	this->occupied = o;
	this->posX = x;
	this->posY = y;
	
}

bool Pixel::checkParam(const int& w, const int& s, const double& h, const double& c, 
		const double& r, const bool& o, const float& x, const float& y) const
{
	if(w < 0 || s < 0 || h < 0 || c < 0 || r < 0 || 
		(o != true && o != false)) return false;
		
	return true;
}

float Pixel::X() const{
	return this->posX;
}

float Pixel::Y() const{
	return this->posY;
}
		
		
		
