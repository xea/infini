#include <engine/rendering/glew/GLEWRenderObject.h>

GLEWRenderObject::GLEWRenderObject(std::shared_ptr<Mesh> mesh) {
    this->mesh = mesh;

    vertexArray.bind();
    arrayBuffer.bindMesh(mesh);
    elementBuffer.bindMesh(mesh);

    // TODO tidy up this shit

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void GLEWRenderObject::bind() {
}

void GLEWRenderObject::unbind() {
}

void GLEWRenderObject::draw() {
    vertexArray.bind();

    // 6 count, 0 indices
    int vtxCount = this->mesh->getVerticesCount();
    int idxCount = this->mesh->getIndicesCount();

    glDrawElements(GL_TRIANGLES, vtxCount, GL_UNSIGNED_INT, 0);
}

std::shared_ptr<Mesh> GLEWRenderObject::getMesh() {
    return this->mesh;
}