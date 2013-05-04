#ifndef XA_SHADERPROGRAM_H
#define XA_SHADERPROGRAM_H

#include <list>
#include "Shader.h"

using namespace std;

/**
 * Represents one OpenGL Shader program
 */
class ShaderProgram {

private:

	/**
	 * Unique shader program identifier, assigned by OpenGL
	 */
	unsigned int id;

	/**
	 * Container for holding the shaders for this shader program
	 */
	list<Shader *> *shaders;

public:

	/**
	 * Creates a new OpenGL Shader program
	 */
	ShaderProgram();

	/**
	 * Releases the allocated data upon destruction
	 */
	~ShaderProgram();

	/**
	 * Wraps and executes the process of loading a source file containing a shader 
	 * source, reading, compiling and attaching it to this shader program
	 */
	void loadShader(const char *fileName, GLenum shaderType);

	/** 
	 * Attempts to attach the given Shader object to this program
	 */
	void attach(Shader *shader);

	/**
	 * Attemps to detach the given Shader object from this program
	 */
	void detach(Shader *shader);

	/**
	 * Links this Shader program object. If any shaders are attached then
	 * they will be used to create an executable code that runs on the GPU.
	 */
	void link();

	/**
	 * Checks if this Shader program can be executed
	 */
	void validate();

	/**
	 * Binds the shader program to the rendering process
	 */
	void bind();

	/**
	 * Unbinds the shader program from the rendering process
	 */
	void unbind();
};

#endif // XA_SHADERPROGRAM_H