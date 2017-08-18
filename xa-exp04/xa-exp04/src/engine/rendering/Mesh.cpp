#include <engine/rendering/Mesh.h>

Triangle::Triangle() {

}

const float* Triangle::getVertices() {
    return this->vertices;
}

unsigned int Triangle::getVerticesCount() {
    return sizeof(this->vertices) / sizeof(const float);
}

const unsigned int* Triangle::getIndices() {
    return this->indices;
}

unsigned int Triangle::getIndicesCount() {
    return sizeof(this->indices) / sizeof(unsigned int);
}

VertexMode Triangle::getMode() {
    return VertexMode::Triangles;
}

// CUBE 

Cube::Cube() {

}

const float* Cube::getVertices() {
    return this->vertices;
}

unsigned int Cube::getVerticesCount() {
    return sizeof(this->vertices) / sizeof(const float);
}

const unsigned int* Cube::getIndices() {
    return this->indices;
}

unsigned int Cube::getIndicesCount() {
    return sizeof(this->indices) / sizeof(unsigned int);
}

VertexMode Cube::getMode() {
    return VertexMode::Triangles;
}
