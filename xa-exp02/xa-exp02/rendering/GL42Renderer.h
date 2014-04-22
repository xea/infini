#ifndef XA_GL42RENDERER_H
#define XA_GL42RENDERER_H

#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>  

#include <chrono>
#include <thread>

#include <core/Logger.h>
#include <rendering/Renderer.h>
#include <rendering/Scene.h>
#include <rendering/Shader.h>
#include <rendering/ShaderProgram.h>

/**
 * An OpenGL 4.2 implementation for the Renderer interface
 */
class GL42Renderer : public Renderer {

protected:

	ShaderProgram *shaderProgram;

	glm::mat4 projectionMatrix;
	glm::mat4 viewMatrix;
	
	unsigned int vaoID[1]; // Our Vertex Array Object
	unsigned int vboID[1]; // Our Vertex Buffer Object
	unsigned int vcoID[1]; // Our Vertex Color Buffer Object

	void prepareBuffers();

public:
	/**
	 * OpenGL 4.2 Major version
	 */
	static const int MAJOR_VERSION = 4;

	/**
	 * OpenGL 4.2 Minor version
	 */
	static const int MINOR_VERSION = 2;

	inline const int getMajorVersion() const { return GL42Renderer::MAJOR_VERSION; }

	inline const int getMinorVersion() const { return GL42Renderer::MINOR_VERSION; }

	void prepareScene();

	void prepareFrame();

	void destroyScene();

	void drawScene(Scene& scene);

	void bindObject(RenderObject *object);

	void drawObject(RenderObject *object);
};

#endif // XA_GL42RENDERER_H