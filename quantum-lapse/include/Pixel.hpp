
#ifndef __PIXEL_H__
#define __PIXEL_H__

#include <iostream>

using namespace std;


/**
 * @class Pixel
 * @brief Clase que representa un pixel.
 */
class Pixel{
private:
	int weight; /**< @brief Representa el peso del pixel. */
	int structural; /**< @brief Representa la fuerza estructural del pixel. */  
	double health; /**< @brief Representa la salud del pixel. */  
	double complexity; /**< @brief Representa la complejidad del pixel. */  
	double resistance; /**< @brief Representa la resistencia del pixel. */  
	bool occupied; /**< @brief Representa si esta ocupado el pixel. */
	
public:
	
	/**
	 * @brief Constructor por defecto.
	 * 
	 * Establece todos los miembros a su valor por defecto.
	 */
	Pixel();
	
	/**
	 * @brief Constructor con parámetros.
	 * 
	 * Establece todos los miembros a los valores pasados por parámetro al constructor.
	 * @param w Weigth.
	 * @param s Structural.
	 * @param h Health.
	 * @param c Complexity.
	 * @param o Occupied.
	 */
	 Pixel(const int w, const int s, const double h, 
			const double c, const double r, const bool o);
			
	
	
	
	
	
	
	
	
};

#endif
