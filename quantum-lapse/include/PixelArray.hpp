#ifndef __PIXELARRAY_H__
#define __PIXELARRAY_H__

#include "Pixel.hpp"


/**
 * @class PixelArray
 * @brief Clase que representa un array de pixels.
 * 
 * Esta clase es la encargada de tratar todos los pixels en su conjunto,
 * calculando el número de pixels, el peso total, la integridad total...
 */
class PixelArray{
private:
	Pixel* pixels; /**< @brief Representa el array con todos los pixels. */
	unsigned int n; /**< @brief Representa el número de pixels en el array. */
	float* vertex; /**< @brief Representa la posición de los pixels. */
	
	/**
	 * @brief Función de copia por valor a partir de otro PixelArray.
	 * 
	 * @param otro PixelArray a copiar
	 */
	void copy(const PixelArray& otro);
	
	/**
	 * @brief Libera todos los recursos.
	 */
	void clear();
	
	/**
	 * @brief Redimension de los arrays.
	 * 
	 * @param n nuevo tamaño con el que redimensionar.
	 */
	void resize(const unsigned int& n);
	
	
public:
	/**
	 * @brief Constructor por defecto.
	 * 
	 * Establece todos los miembros a su valor por defecto.
	 */
	PixelArray();
	
	/**
	 * @brief Constructor de copia.
	 * 
	 * Inicializa los datos dependientes del array de pixels
	 * 
	 * @param otro PixelArray ha copiar.
	 */
	PixelArray(const PixelArray& otro);
	
	/**
	 * @brief Constructor mediante array con las posiciones.
	 * 
	 * Inicializa todos los pixels con valores por defecto y establece
	 * su posición a la pasada por parámetro.
	 * 
	 * @param vert array de floats con las posiciones.
	 * @param n tamaño del array.
	 */
	PixelArray(const float * vert, unsigned int& n);
	
	/**
	 * @brief Destructor.
	 */
	~PixelArray();
	
	/**
	 * @brief operador de asignación.
	 * 
	 * @param otro PixelArray a copiar.
	 */
	const PixelArray& operator=(const PixelArray& otro);
	
	/**
	 * @brief devuelve el array de posiciones de los pixels.
	 * 
	 * @return referesizecia constante a vertex.
	 */
	const float* getVertex() const;
	
	/**
	 * @brief devuelve el número de pixels.
	 * 
	 * @return enter constante con numero de pixels en array de pixels.
	 */
	const unsigned int& size() const;
	
	
};




#endif
