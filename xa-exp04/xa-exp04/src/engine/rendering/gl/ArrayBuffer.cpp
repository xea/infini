#include <engine/rendering/gl/ArrayBuffer.h>

ArrayBuffer::ArrayBuffer() {
    
}

void ArrayBuffer::bindMesh(std::shared_ptr<Mesh> mesh) {
    bindData(this->bufferId, GL_ARRAY_BUFFER, mesh->getVerticesCount(), (void *) mesh->getVertices());
}
