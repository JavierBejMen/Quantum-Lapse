#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "ImageBuffer.hpp"
#include <string>



/**
 * @class Sprite
 * @brief Clase que representa un objeto Sprite.
 * 
 * Esta clase es la encargada de gestionar todo lo relacionado con la
 * inicialización de las texturas, y establecimiento de los parámetros de
 * OpenGL para usar las texturas(Sprites).
 */
class Sprite{
private:
	unsigned int ID; /**< @brief Identificador del Sprite. */
	unsigned int width; /**< @brief Anchura del Sprite. */
	unsigned int height; /**< @brief Altura del Sprite. */
	std::string name; /**< @brief Nombre del Sprite. */
	
	
public:
	
	Sprite() = delete;
	
	/**
	* @brief Constructor a partir de una imagen cargada en memoria.
	*/
	Sprite(const std::string& name);
	
	/**
	* @brief Genera y carga la textura en OpenGL.
	* 
	* @param img Imagen cargada en memoria.
	*/
	void Generate(const ImageBuffer& img);
	
	/**
	* @brief Consultar ID.
	* 
	* @return Devuelve el ID.
	*/
	const unsigned int& getID() const;
	
};





#endif
