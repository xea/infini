#include <engine/rendering/gl/ArrayBuffer.h>

ArrayBuffer::ArrayBuffer() {
    glGenBuffers(1, &this->bufferId);
}

void ArrayBuffer::bindMesh(std::shared_ptr<Mesh> mesh) {
    glBindBuffer(GL_ARRAY_BUFFER, this->bufferId);
    glBufferData(GL_ARRAY_BUFFER, mesh->getVerticesCount() * sizeof(float), mesh->getVertices(), GL_STATIC_DRAW);
}

void ArrayBuffer::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}