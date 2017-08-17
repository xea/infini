#ifndef XA_MESH_H
#define XA_MESH_H

#include <memory>

/**
 * A mesh describes the spatial properties (vertices, indices, etc) of a displayable object
 */
class Mesh {
public:
    virtual const float* getVertices() = 0;
    virtual unsigned int getVerticesCount() = 0;
    virtual const unsigned int* getIndices() = 0;
    virtual unsigned int getIndicesCount() = 0;
};

class Triangle : public Mesh {
private:
    constexpr static float vertices[] = { 
         0.0f,  0.5f, 0.0f, 
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f
    };

    constexpr static unsigned int indices[] = { 0, 1, 2 };

public:
    Triangle();

    const float* getVertices() override;
    unsigned int getVerticesCount() override;
    const unsigned int* getIndices() override;
    unsigned int getIndicesCount() override;

};

#endif // XA_MESH_H