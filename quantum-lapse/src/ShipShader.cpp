
#include "ShipShader.hpp"


#include <stdexcept>
#include <iostream>
#include <cstring>

using namespace std;


void ShipShader::Init(const float* px, const unsigned int& size){
	
	static const char *vertexCode = 
		"in vec4 in_Color;\n"
		"in vec2 in_Position;\n"
			
		"out vec4 color;\n"
			
		"void main(void){\n"
			"gl_Position = vec4(in_Position, 0, 1);\n"
			"color = in_Color;\n"
		"}\n";
			
	
	static const char *fragmentCode =
		"in vec4 color;\n"
		"out vec4 fragColor;\n"
		
		"void main(void){\n"
			"fragColor = color;\n"
		"}\n";
	
	
	this->shader = Shader(vertexCode, fragmentCode);
	
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	glGenBuffers(2, vbo);
	
	GLfloat vert[size*2];
	memcpy(vert, px, size * 2 * sizeof(float));
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, size * 2 * sizeof(GLfloat), vert, GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(shader.Attrib("in_Position"));
	glVertexAttribPointer(shader.Attrib("in_Position"), 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	
	
	GLfloat co[] = {
		0.5, 0., 0., 1.0f,
		0., 0.5, 0., 1.0f,
		0., 0., 0.5, 1.0f,
		0., 0.5, 0.5, 1.0f,
	};
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(co), co, GL_STATIC_DRAW);
	
	
	glEnableVertexAttribArray(shader.Attrib("in_Color"));
	glVertexAttribPointer(shader.Attrib("in_Color"), 4, GL_FLOAT, GL_FALSE, 0, nullptr);
	
	this->size = size;
	cout<<"size in shader: "<<size * 2 * sizeof(GLfloat)<<endl;
	// unbind the VBO and VAO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void ShipShader::Bind(){
	glUseProgram(shader.Object());
	glBindVertexArray(vao);
}

void ShipShader::Unbind(){
	glBindVertexArray(0);
	glUseProgram(0);
}

void ShipShader::Draw(){
	if(!shader.Object())
		throw runtime_error("LineShader: Draw() called before Init().");
	
	Bind();
	
	glDrawArrays(GL_TRIANGLE_STRIP, 0, this->size);
	
	Unbind();
}
	
	











