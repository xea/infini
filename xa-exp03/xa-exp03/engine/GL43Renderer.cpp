#include "GL43Renderer.h"

void GL43Renderer::clearScreen() {
	glClearColor(0.1f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
