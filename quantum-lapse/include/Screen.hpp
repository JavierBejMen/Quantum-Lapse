#ifndef __SCREEN_H__
#define __SCREEN_H__


/**
 * @class Screen
 * @brief Clase que contiene las propiedades de la pantalla.
 */
class Screen{
public:

	/**
	* @brief Establece el tamaño de la ventana en pixels.
	*/
	static void SetRaw(const unsigned int& width, const unsigned int& height);
	
	/**
	* @brief Consultar el Ancho de la ventana en pixels.
	* @return RAW_WIDTH.
	*/
	static const unsigned int& RawWidth();
	
	/**
	* @brief Consultar el Alto de la ventana en pixels.
	* @return RAW_HEIGHT.
	*/
	static const unsigned int& RawHeight();
	
	
};





#endif
