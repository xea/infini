#ifndef XA_SHADER_H
#define XA_SHADER_H

#include <string>
#include <GL/glew.h>
#include <engine/logging/Logger.h>

enum class ShaderType : unsigned int {
    VertexShader,
    FragmentShader
};

class Shader {
protected:
    int shaderId;

    string getResult();

public:
    Shader(ShaderType shaderType);
    void compile();
    void setSource(const char **shaderSource);
    int getShaderId();
    static Shader loadShader(std::string filename, ShaderType shaderType);
};

#endif // XA_SHADER_H
