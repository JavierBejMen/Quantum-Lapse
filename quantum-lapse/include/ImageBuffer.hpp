#ifndef __IMAGEBUFFER_H__
#define __IMAGEBUFFER_H__

#include "utils.hpp"

#include <cstdint>
#include <string>


#define PNGSIGSIZE 8

/**
 * @class ImageBuffer
 * @brief Wrapper para I/O de imágenes.
 * 
 * Esta clase es la encargada de gestionar todo lo relacionado a la lectura
 * y escritura de imágenes desde el disco.
 */
class ImageBuffer{	
public:
	/**
	* @brief Constructor por defecto.
	*/
	ImageBuffer();
	
	/**
	* @brief Destructor
	*/
	~ImageBuffer();
	
	
	/**
	* @brief Carga el archivo PNG.
	* 
	* @param path contiene la dirección del archivo.
	*/
	const utils::FileErrLog& ReadPNG(const std::string& path);
	
private:
	unsigned int width; /**< @brief Anchura de la imagen. */
	unsigned int height; /**< @brief Altura de la imagen. */
	uint32_t *pixels; /**< @brief Representa el array con todos los pixels. */
	utils::FileErrLog errLog; /**< @brief Representa el log en las operaciones I/O. */
	
	/**
	* @brief Reserva el buffer.
	* 
	* @param width ancho de la imagen.
	* @param height alto de la imagen.
	*/
	void resize(const unsigned int& width, const unsigned int& height);
	
	/**
	* @brief Libera el heap
	*/
	void clear();
	
};



#endif
