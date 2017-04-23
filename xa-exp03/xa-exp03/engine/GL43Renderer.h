#ifndef XA_GL43RENDERER_H
#define XA_GL43RENDERER_H

#include <GL/glew.h>

#include "Renderer.h"

#ifdef _MSC_VER

#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glfw3.lib")

#endif // _MSC_VER

class GL43Renderer : public Renderer {
public:
	void clearScreen();
};

#endif // XA_GL43RENDERER_H