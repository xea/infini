#include <engine/rendering/glew/GLEWRenderObject.h>

GLEWRenderObject::GLEWRenderObject(std::shared_ptr<Mesh> mesh) {
    this->mesh = mesh;
}

void GLEWRenderObject::bind() {
}

void GLEWRenderObject::unbind() {
    
}

void GLEWRenderObject::draw() {
    // 6 count, 0 indices
    int vtxCount = this->mesh->getVerticesCount();
    int idxCount = this->mesh->getIndicesCount();

    glDrawElements(GL_TRIANGLES, vtxCount, GL_UNSIGNED_INT, 0);
}

std::shared_ptr<Mesh> GLEWRenderObject::getMesh() {
    return this->mesh;
}