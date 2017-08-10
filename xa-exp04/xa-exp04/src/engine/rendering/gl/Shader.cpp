#include <engine/rendering/gl/Shader.h>

Shader Shader::loadShader(std::string filename, ShaderType shaderType) {
    const char *shaderSource;

    // TODO implement actual shader loading
    
    switch (shaderType) {
        case ShaderType::VertexShader:
            shaderSource = 
                "#version 330 core\n"
                "layout (location = 0) in vec3 aPos;\n"
                "void main()\n"
                "{\n"
                "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                "}\0";
                break;
        case ShaderType::FragmentShader:
            shaderSource = 
                "#version 330 core\n"
                "out vec4 FragColor;\n"
                "void main()\n"
                "{\n"
                "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                "}\n\0";
                break;
    }

    VertexShader vertexShader;
    vertexShader.setSource(&shaderSource);
    vertexShader.compile();
    return vertexShader;
}

void Shader::setSource(const char **shaderSource) {
    glShaderSource(shaderId, 1, shaderSource, NULL);
}

void Shader::compile() {
    glCompileShader(shaderId);
}

int Shader::getShaderId() {
    return this->shaderId;
}

VertexShader::VertexShader() {
    shaderId = glCreateShader(GL_VERTEX_SHADER);
}

FragmentShader::FragmentShader() {
    shaderId = glCreateShader(GL_FRAGMENT_SHADER);
}