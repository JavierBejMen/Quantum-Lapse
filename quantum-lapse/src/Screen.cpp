
#include "Screen.hpp"

using namespace std;

namespace{
	unsigned int RAW_WIDTH = 0;
	unsigned int RAW_HEIGHT = 0;
	
	
}

void Screen::SetRaw(const unsigned int& width, const unsigned int& height){
	RAW_WIDTH = width;
	RAW_HEIGHT = height;
}

const unsigned int& Screen::RawWidth(){
	return RAW_WIDTH;
}

const unsigned int& Screen::RawHeight(){
	return RAW_HEIGHT;
}
