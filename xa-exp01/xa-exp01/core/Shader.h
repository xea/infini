#ifndef XA_SHADER_H
#define XA_SHADER_H

#include <GL/glew.h>

#include <iostream>
#include <fstream>
#include <string>

#include "Logger.h"

using namespace std;

/**
 * Represents an OpenGL shader object
 */
class Shader {

private:

	/**
	 * Indicates the type of this shader
	 */
	GLenum shaderType;

	/**
	 * The ID of this shader object
	 */
	GLuint id;

protected:

	static string getFileContents(const char *fileName);

public:

	/**
	 * Initializes an empty shader
	 */
	Shader(const char *shaderCode, GLenum shaderType);

	/**
	 * Handles the destruction of this shader
	 */
	~Shader();

	/**
	 * Reads the contents of a file containing a shader source code
	 */
	static Shader* loadFromFile(const char *fileName, GLenum type);

	/**
	 * Compiles the loaded shader source code.
	 */
	void compile();

	/**
	 * Checks if there were any errors during compiling this shader
	 */
	void validate();

	/**
	 * Returns with the type of this shader which is usually one of the following three values:
	 * GL_VERTEX_SHADER
	 * GL_FRAGMENT_SHADER
	 * GL_GEOMETRY_SHADER
	 */
	GLenum getType();

	/**
	 * Returns the ID of this shader object
	 */
	GLuint getId();
};

#endif // XA_SHADER_H