#include <engine/rendering/gl/ElementBuffer.h>

ElementBuffer::ElementBuffer() {
    glGenBuffers(1, &this->bufferId);
}

void ElementBuffer::bindMesh(std::shared_ptr<Mesh> mesh) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->bufferId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->getIndicesCount(), mesh->getIndices(), GL_STATIC_DRAW);
    //bindData(this->bufferId, GL_ELEMENT_ARRAY_BUFFER, mesh->getIndicesCount(), (void *) mesh->getIndices());
}
