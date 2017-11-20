#ifndef __SPRITESHADER_H__
#define __SPRITESHADER_H__

#include <cstdint>

#include "Sprite.hpp"

/**
 * @class SpriteShader
 * @brief Shader para renderizar los sprites.
 */
class SpriteShader{
public:
	/**
	 * @brief Inicializa el SpriteShader.
	 * 
	 * Crea el programa shader y lo deja listo para usarlo (Unbinded).
	 */
	static void Init();
	
	/**
	 * @brief Dibuja el sprite.
	 */
	 static void Draw(const Sprite& tex);
	 
	 static void Bind();
	 static void Unbind();
	
};








#endif
