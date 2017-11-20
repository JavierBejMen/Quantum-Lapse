#include "SpriteShader.hpp"

#include "Shader.hpp"
#include <iostream>
using namespace std;

namespace{
	Shader shader;
	GLuint vao;
	GLuint vbo;
}

void SpriteShader::Init()
{
	static const char *vertexCode =
		
		"in vec2 vert;\n"
		"out vec2 fragTexCoord;\n"
		
		"void main() {\n"
		"  gl_Position = vec4(vert, 0, 1);\n"
		"  fragTexCoord = vert + vec2(.5, .5);\n"
		"}\n";

	static const char *fragmentCode =
		"uniform sampler2D tex0;\n"
		
		"in vec2 fragTexCoord;\n"
		"out vec4 finalColor;\n"
		
		"void main() {\n"
		 
		"  finalColor = texture(tex0, fragTexCoord);\n"
		"}\n";
	
	shader = Shader(vertexCode, fragmentCode);
	
	glUseProgram(shader.Object());
	glUniform1i(shader.Uniform("tex0"), 0);

	glUseProgram(0);
	
	// Generate the vertex data for drawing sprites.
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	
	GLfloat vertexData[] = {
		-.5f, -.5f,
		-.5f,  .5f,
		 .5f, -.5f,
		 .5f,  .5f
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(shader.Attrib("vert"));
	glVertexAttribPointer(shader.Attrib("vert"), 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
	
	// unbind the VBO and VAO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void SpriteShader::Draw(const Sprite& tex0)
{	
	Bind();
	glBindTexture(GL_TEXTURE_2D, tex0.getID());
	cout<<"val:"<<tex0.getID()<<endl;	
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	Unbind();
}


void SpriteShader::Bind()
{
	glUseProgram(shader.Object());
	glBindVertexArray(vao);
	glActiveTexture(GL_TEXTURE0);
}


void SpriteShader::Unbind()
{
	glBindVertexArray(0);
	glUseProgram(0);
}
