#include <engine/rendering/gl/ElementBuffer.h>

ElementBuffer::ElementBuffer() {

}

void ElementBuffer::bindMesh(std::shared_ptr<Mesh> mesh) {
    bindData(this->bufferId, GL_ELEMENT_ARRAY_BUFFER, mesh->getIndicesCount(), (void *) mesh->getIndices());
}
