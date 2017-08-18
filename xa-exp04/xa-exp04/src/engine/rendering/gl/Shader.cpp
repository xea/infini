#include <engine/rendering/gl/Shader.h>

Shader Shader::loadShader(std::string filename, ShaderType shaderType) {
    string fileContent = FileSource::getFileContents(filename);

    const char *shaderSource = fileContent.data();

    Shader shader(shaderType);
    shader.setSource(&shaderSource);
    shader.compile();

    return shader;
}

void Shader::setSource(const char **shaderSource) {
    glShaderSource(shaderId, 1, shaderSource, NULL);
}

void Shader::compile() {
    glCompileShader(shaderId);
}

string Shader::getResult() {
    string result;

    int success;
    char infoLog[512];
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
        result.append("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
        result.append(infoLog);
    }

    return result;
}

int Shader::getShaderId() {
    return this->shaderId;
}

unsigned int Shader::getShaderLocation(string varName) {
    return glGetUniformLocation(shaderId, varName.c_str());
}

Shader::Shader(ShaderType shaderType) {

    switch (shaderType) {
        case ShaderType::VertexShader:
            shaderId = glCreateShader(GL_VERTEX_SHADER);
            break;
        case ShaderType::FragmentShader:
            shaderId = glCreateShader(GL_FRAGMENT_SHADER);
            break;

    }
}
