#ifndef XA_SHADERPROGRAM_H
#define XA_SHADERPROGRAM_H

#include <engine/rendering/gl/Shader.h>
#include <engine/rendering/gl/Uniform.h>
#include <memory>

enum class UniformType : unsigned int {
    TransformationMatrix
};

class ShaderProgram {
private:
    int programId;

protected:
    string getResult();
public:
    ShaderProgram();
    void attachShader(Shader shader);
    void deleteShader(Shader shader);
    UniformLocations use();
    void link();
    unsigned int getUniformLocation(UniformType type);
    UniformLocations getUniformLocations();

    static std::shared_ptr<ShaderProgram> getDefault();
};

#endif // XA_SHADERPROGRAM_H