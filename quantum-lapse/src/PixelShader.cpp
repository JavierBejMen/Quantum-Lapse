
#include "PixelShader.hpp"
#include "Shader.hpp"

#include <stdexcept>

using namespace std;

namespace{
	Shader shader;
	
	GLuint vao;
	GLuint vbo[2];
}

void PixelShader::Init(){
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
	
	
	shader = Shader(vertexCode, fragmentCode);
	
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	glGenBuffers(2, vbo);
	
	GLfloat vertexData[] = {
		0.5, 0.5,
		0.5, -0.5,
		-0.5,  0.5,
		-0.5,  -0.5
	};
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(shader.Attrib("in_Position"));
	glVertexAttribPointer(shader.Attrib("in_Position"), 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	
	GLfloat colorData[] = {
		0.5, 0., 0., 1.0f,
		0., 0.5, 0.0, 1.0f,
		0., 0., 0.5, 1.0f,
		0.5, 0.5, 0.5, 1.0f
	};
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colorData), colorData, GL_STATIC_DRAW);
	
	
	glEnableVertexAttribArray(shader.Attrib("in_Color"));
	glVertexAttribPointer(shader.Attrib("in_Color"), 4, GL_FLOAT, GL_FALSE, 0, nullptr);
	
	// unbind the VBO and VAO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void PixelShader::Draw(){
	if(!shader.Object())
		throw runtime_error("LineShader: Draw() called before Init().");
	
	glUseProgram(shader.Object());
	glBindVertexArray(vao);
	
	glPointSize(10);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
	glBindVertexArray(0);
	glUseProgram(0);
}
	
	











