#include <engine/rendering/Mesh.h>

Triangle::Triangle() {

}

const float* Triangle::getVertices() {
    return this->vertices;
}

unsigned int Triangle::getVerticesCount() {
    return sizeof(this->vertices);
}

const unsigned int* Triangle::getIndices() {
    return this->indices;
}

unsigned int Triangle::getIndicesCount() {
    return sizeof(this->indices);
}