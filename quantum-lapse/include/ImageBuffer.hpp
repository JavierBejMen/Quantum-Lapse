#ifndef __IMAGEBUFFER_H__
#define __IMAGEBUFFER_H__

#include <cstdint>

/**
 * @class ImageBuffer
 * @brief Wrapper para I/O de imágenes.
 * 
 * Esta clase es la encargada de gestionar todo lo relacionado a la lectura
 * y escritura de imágenes desde el disco.
 */
class ImageBuffer{
private:
	int width; /**< @brief Anchura de la imagen. */
	int height; /**< @brief Altura de la imagen. */
	uint32_t *pixels; /**< @brief Representa el array con todos los pixels. */
	
public:

	/**
	* @brief Constructor por defecto.
	*/
	ImageBuffer();
	
	
	
};



#endif
