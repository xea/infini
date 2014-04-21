#include "Shader.h"

Shader::Shader(const char *shaderCode, GLenum shaderType) {
	this->shaderType = shaderType;

	id = glCreateShader(shaderType);

	glShaderSource(id, 1, &shaderCode, 0);
}

Shader::~Shader() {
	glDeleteShader(id);
}

/**
 * Implementation is temporarily borrowed from swiftless.com
 */
string Shader::getFileContents(const char *fileName) {
	string fileString = string(); 
	string line = string(); 

	ifstream file(fileName); 

	if (file.is_open()) { 
		while (!file.eof()) { 
			getline(file, line); 
		  	fileString.append(line); 
			fileString.append("\n"); 
		}
		file.close(); 
	}

    return fileString; 
}

Shader *Shader::loadFromFile(const char *fileName, GLenum shaderType) {
	string shaderCode = Shader::getFileContents(fileName);

	Shader *shader = new Shader(shaderCode.c_str(), shaderType);

	return shader;
}

void Shader::compile() {
	glCompileShader(id);
}

void Shader::validate() {
	const unsigned int BUFFER_SIZE = 512;
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    GLsizei length = 0;

    // Ask OpenGL to give us the log associated with the shader
    glGetShaderInfoLog(id, BUFFER_SIZE, &length, buffer); 
    
	if (length > 0) {
        cout << "Shader " << id << " compile error: " << buffer << endl;
	}
}

GLuint Shader::getId() {
	return id;
}