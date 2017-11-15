
#ifndef __PIXEL_H__
#define __PIXEL_H__

#include <iostream>

using namespace std;


/**
 * @class Pixel
 * @brief Clase que representa un pixel
 * Representa la unidad minima del universo, el pixel
 */
class Pixel{
private:
	int weight; /**< representa el peso del pixel. */  
	int structural; /**< representa la fuerza estructural del pixel. */  
	double health; /**< representa la salud del pixel. */  
	double complexity; /**< representa la complejidad del pixel. */  
	double resistance; /**< representa la resistencia del pixel. */  
	bool occupied; /**< representa si esta ocupado el pixel. */
	
public:
	
	/**
	 * @brief Constructor por defecto
	 * Establece todos los parámetros a su valor por defecto
	 */
	Pixel();
	
	
	
	
	
	
};

#endif
