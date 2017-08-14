#ifndef XA_SHADERPROGRAM_H
#define XA_SHADERPROGRAM_H

#include <engine/rendering/gl/Shader.h>
#include <engine/logging/Logger.h>

class ShaderProgram {
private:
    int programId;
protected:
    string getResult();
public:
    ShaderProgram();
    void attachShader(Shader shader);
    void deleteShader(Shader shader);
    void use();
    void link();
    static ShaderProgram getDefault();
};

#endif // XA_SHADERPROGRAM_H