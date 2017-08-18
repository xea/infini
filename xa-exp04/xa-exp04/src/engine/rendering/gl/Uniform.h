#ifndef XA_UNIFORM_H
#define XA_UNIFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class TransformationState {
private:
    glm::mat4 state;

public:
    const float* getValuePtr();
    void rotateX(float xrot);
    void rotateY(float yrot);
    void rotateZ(float zrot);
};

class UniformLocations {
public: 
    unsigned int transformation;
};

class Uniform {
private:
public:
    TransformationState transformation;
    UniformLocations locations;
};


#endif // XA_UNIFORM_H