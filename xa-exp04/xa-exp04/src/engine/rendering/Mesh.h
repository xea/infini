#ifndef XA_MESH_H
#define XA_MESH_H

#include <memory>

enum class VertexMode : unsigned int {
    Triangles
};

/**
 * A mesh describes the spatial properties (vertices, indices, etc) of a displayable object
 */
class Mesh {
public:
    virtual const float* getVertices() = 0;
    virtual unsigned int getVerticesCount() = 0;
    virtual const unsigned int* getIndices() = 0;
    virtual unsigned int getIndicesCount() = 0;
    virtual VertexMode getMode() = 0;
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
    VertexMode getMode() override;
};

class Cube : public Mesh {
private:
    constexpr static float vertices[] = {
        -0.5f,  0.5f, -0.5f, // back side top left      0
        -0.5f, -0.5f, -0.5f, // back side bottom left   1
         0.5f,  0.5f, -0.5f, // back side top right     2
         0.5f, -0.5f, -0.5f, // back side bottom right  3
        -0.5f,  0.5f,  0.5f, // front side top left     4
        -0.5f, -0.5f,  0.5f, // front side bottom left  5
         0.5f,  0.5f,  0.5f, // front side top right    6
         0.5f, -0.5f,  0.5f  // front side bottom right 7
    };

    constexpr static unsigned int indices[] = {
        0, 1, 2,
        1, 2, 3,
    };
public:
    Cube();

    const float* getVertices() override;
    unsigned int getVerticesCount() override;
    const unsigned int* getIndices() override;
    unsigned int getIndicesCount() override;
    VertexMode getMode() override;
};

#endif // XA_MESH_H