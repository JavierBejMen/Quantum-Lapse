//main prueba

//#include "Pixel.hpp"

#include "FrameTimer.hpp"
#include "Shader.hpp"
#include "PixelShader.hpp"

#include "gl_header.h"
#include <SDL2/SDL.h>

#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

SDL_Window *mainWindow;
SDL_GLContext mainContext;

void InitSDL();
void AdjustViewport(SDL_Window *window);
void Cleanup(SDL_Window *window, SDL_GLContext context);
int DoError(string msg, SDL_Window *window, SDL_GLContext context);
void RunGame();

using namespace std;

int main(int argc, char* argv[]){
	
	
try{
		
		InitSDL();
		
		
		glClearColor(0.f, 0.f, 0.0f, 1.f);
		glEnable(GL_BLEND);
		glDisable(GL_DEPTH_TEST);
		glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
		
		// Make sure the screen size and viewport are set correctly.
		AdjustViewport(mainWindow);
		
		PixelShader::Init();
		
		RunGame();
		
		Cleanup(mainWindow, mainContext);
	}
	catch(const runtime_error &error){
		return DoError(error.what(), mainWindow, mainContext);
	}
	
	return 0;
}

int DoError(string msg, SDL_Window *window, SDL_GLContext context){
	Cleanup(window, context);
	
	// Check if SDL has more details.
	const char *sdlMessage = SDL_GetError();
	if(sdlMessage && sdlMessage[0]){
		msg += " (SDL message: \"";
		msg += sdlMessage;
		msg += "\")";
	}
	
	// Print the error message in the terminal.
	cerr << msg << endl;
	
	return 1;
}




void AdjustViewport(SDL_Window *window){
	// Get the window's size in screen coordinates.
	int width, height;
	SDL_GetWindowSize(window, &width, &height);
	
	// Round the window size up to a multiple of 2, even if this
	// means one pixel of the display will be clipped.
	int roundWidth = (width + 1) & ~1;
	int roundHeight = (height + 1) & ~1;
	
	
	// Find out the drawable dimensions. If this is a high- DPI display, this
	// may be larger than the window.
	int drawWidth, drawHeight;
	SDL_GL_GetDrawableSize(window, &drawWidth, &drawHeight);
		
	
	// Set the viewport to go off the edge of the window, if necessary, to get
	// everything pixel-aligned.
	drawWidth = (drawWidth * roundWidth) / width;
	drawHeight = (drawHeight * roundHeight) / height;
	glViewport(0, 0, drawWidth, drawHeight);
	
}


void Cleanup(SDL_Window *window, SDL_GLContext context)
{
	// Make sure the cursor is visible.
	SDL_ShowCursor(true);
	
	// Clean up in the reverse order that everything is launched.
#ifndef _WIN32
	// Under windows, this cleanup code causes intermittent crashes.
	if(context)
		SDL_GL_DeleteContext(context);
#endif
	if(window)
		SDL_DestroyWindow(window);
	
	SDL_Quit();
}


void InitSDL(){
	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		throw runtime_error("Unable to initialize SDL");
	}
	
	// On Windows, make sure that the sleep timer has at least 1 ms resolution
	// to avoid irregular frame rates.
#ifdef _WIN32
	timeBeginPeriod(1);
#endif
	// Check how big the window can be.
	SDL_DisplayMode mode;
	if(SDL_GetCurrentDisplayMode(0, &mode))
		throw runtime_error("Unable to query monitor resolution!");
		
	// Create the window.
	Uint32 flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN;
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
#ifdef _WIN32
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#endif
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		
	mainWindow = SDL_CreateWindow("Quantum Lapse",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			500, 500, flags);
	if(!mainWindow)
		throw runtime_error("Unable to create window!");
		
	mainContext = SDL_GL_CreateContext(mainWindow);
	if(!mainContext)
		throw runtime_error("Unable to create OpenGL context! Check if your system supports OpenGL 3.0.");
		
	if(SDL_GL_MakeCurrent(mainWindow, mainContext))
		throw runtime_error("Unable to set the current OpenGL context!");
		
	SDL_GL_SetSwapInterval(1);
	
	// Initialize GLEW.
#ifndef __APPLE__
	glewExperimental = GL_TRUE;
	if(glewInit() != GLEW_OK)
		throw runtime_error("Unable to initialize GLEW!");
#endif
		
	// Check that the OpenGL version is high enough.
	const char *glVersion = reinterpret_cast<const char *>(glGetString(GL_VERSION));
	if(!glVersion || !*glVersion)
		throw runtime_error("Unable to query the OpenGL version!");
		
	const char *glslVersion = reinterpret_cast<const char *>(glGetString(GL_SHADING_LANGUAGE_VERSION));
	if(!glslVersion || !*glslVersion){
			ostringstream out;
			out << "Unable to query the GLSL version. OpenGL version is " << glVersion << ".";
			throw runtime_error(out.str());
		}
		
	if(*glVersion < '3'){
		ostringstream out;
		out << "Quantum-Lapse requires OpenGL version 3.0 or higher." << endl;
		out << "Your OpenGL version is " << glVersion << ", GLSL version " << glslVersion << "." << endl;
		out << "Please update your graphics drivers.";
		throw runtime_error(out.str());
	}
	
}

void RunGame(){
	bool loop = true;

	while (loop){
		SDL_Event event;
		while (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT)
				loop = false;

			if (event.type == SDL_KEYDOWN){
				switch (event.key.keysym.sym){
				case SDLK_ESCAPE:
					loop = false;
					break;
				case SDLK_r:
					// Cover with red and update
					glClear(GL_COLOR_BUFFER_BIT);
					PixelShader::Draw();
					break;
				case SDLK_g:
					// Cover with green and update
					glClearColor(0.0, 1.0, 0.0, 1.0);
					glClear(GL_COLOR_BUFFER_BIT);
					break;
				case SDLK_b:
					// Cover with blue and update
					glClearColor(0.0, 0.0, 1.0, 1.0);
					glClear(GL_COLOR_BUFFER_BIT);
					break;
				default:
					break;
				}
				
				SDL_GL_SwapWindow(mainWindow);
			}
		}
	}
}


















