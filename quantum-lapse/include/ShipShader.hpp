#ifndef __ShipShader_H__
#define __ShipShader_H__

#include "Shader.hpp"

class ShipShader{
public:
	void Init(const GLfloat* px, const unsigned int& size);
	
	void Bind();
	void Draw();
	void Unbind();
	
private:
	Shader shader;
	
	GLuint vao;
	GLuint vbo[2];
	unsigned int size;
};



#endif
