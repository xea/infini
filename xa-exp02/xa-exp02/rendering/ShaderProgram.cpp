#include "ShaderProgram.h"

ShaderProgram::ShaderProgram() {
	id = glCreateProgram();
	shaders = new list<Shader *>();
}

ShaderProgram::~ShaderProgram() {
	for (list<Shader *>::iterator it = shaders->begin(); it != shaders->end();) {
		Shader * const currentShader = *it;

		// UGLY HACK: because i wasn't able to find a way to remove the current 
		// shader by value from detach() i'm doing it here.
		detach(currentShader);
		shaders->erase(it++);
		delete currentShader;
	}

	delete shaders;

	glDeleteProgram(id);
}

void ShaderProgram::loadShader(const char *fileName, GLenum shaderType) {
	Shader *shader = Shader::loadFromFile(fileName, shaderType);
	shader->compile();
	shader->validate();
	attach(shader);
}

void ShaderProgram::attach(Shader *shader) {
	glAttachShader(id, shader->getId());

	shaders->push_back(shader);
}

void ShaderProgram::detach(Shader *shader) {
	glDetachShader(id, shader->getId());

	// TODO the removal from shaders list should come here but i was unable to
	// find a way to do that up to this point, so i remove it in the desturctor
}

void ShaderProgram::link() {
	glLinkProgram(id);
}

void ShaderProgram::validate() {
	const unsigned int BUFFER_SIZE = 512;
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    GLsizei length = 0;
    
	// Ask OpenGL to give us the log associated with the program
    glGetProgramInfoLog(id, BUFFER_SIZE, &length, buffer); 

    if (length > 0) {
        cout << "Program " << id<< " link error: " << buffer << endl; 
	}
    
	// Get OpenGL to try validating the program
    glValidateProgram(id); 
    GLint status;
    
	// Find out if the shader program validated correctly
	glGetProgramiv(id, GL_VALIDATE_STATUS, &status); 

    if (status == GL_FALSE)  {
    glGetProgramInfoLog(id, BUFFER_SIZE, &length, buffer); 

    if (length > 0) {
        cout << "Program " << id<< " link error: " << buffer << endl; 
	}
		cout << "Error validating shader " << id << endl;
	}
}

void ShaderProgram::bind() {
	glUseProgram(id);
}

void ShaderProgram::unbind() {
	glUseProgram(0);
}

GLuint ShaderProgram::getId() {
	return id;
}
