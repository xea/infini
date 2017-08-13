#include <engine/rendering/gl/ArrayBuffer.h>

ArrayBuffer::ArrayBuffer() {
    glGenBuffers(1, &this->bufferId);
}

void ArrayBuffer::bindMesh(std::shared_ptr<Mesh> mesh) {
    glBindBuffer(GL_ARRAY_BUFFER, this->bufferId);
    glBufferData(GL_ARRAY_BUFFER, mesh->getVerticesCount(), mesh->getVertices(), GL_STATIC_DRAW);

    //bindData(this->bufferId, GL_ARRAY_BUFFER, mesh->getVerticesCount(), (void *) mesh->getVertices());
}
