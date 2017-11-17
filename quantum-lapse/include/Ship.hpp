#ifndef __SHIP_H__
#define __SHIP_H__


#include "ShipShader.hpp"
#include "PixelArray.hpp"

/**
 * @class Ship
 * @brief Clase que representa una nave.
 * 
 * Entendemos por nave cualquier objeto presente en el espacio
 */
class Ship{
private:
	PixelArray pixels; /**< @brief Representa el array con todos los pixels. */
	ShipShader shader; /**< @brief Shader asociado a ship. */
	
public:
	/**
	* @brief Constructor por defecto.
	*/
	Ship();
	
	/**
	 * @brief Constructor mediante PixelArray.
	 * 
	 * @param px PixelArray.
	 */
	Ship(const PixelArray& px);
	
	/**
	 * @brief devuelve el array de posiciones de los pixels.
	 * 
	 * @return referencia constante a vertex.
	 */
	const float* getVertex() const;
	
	/**
	 * @brief devuelve el número de pixels.
	 * 
	 * @return enter constante con numero de pixels en array de pixels.
	 */
	const unsigned int& size() const;
	
	
	
	
	void Draw(){
		shader.Draw();
	};
	 
	 
	
	
	
	
	
};





#endif
