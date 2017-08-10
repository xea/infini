#ifndef XA_SHADER_H
#define XA_SHADER_H

#include <string>
#include <GL/glew.h>

enum class ShaderType : unsigned int {
    VertexShader,
    FragmentShader
};

class Shader {
protected:
    int shaderId;

public:
    void compile();
    void setSource(const char **shaderSource);
    int getShaderId();
    static Shader loadShader(std::string filename, ShaderType shaderType);
};

class VertexShader : public Shader {
public:
    VertexShader();

};

class FragmentShader : public Shader {
public:
    FragmentShader();
};

#endif // XA_SHADER_H
