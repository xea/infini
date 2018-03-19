#include <engine/rendering/glew/GLEWRenderObject.h>

GLEWRenderObject::GLEWRenderObject(std::shared_ptr<Mesh> mesh) {
    this->mesh = mesh;

    vertexArray.bind();
    arrayBuffer.bindMesh(mesh);
    elementBuffer.bindMesh(mesh);

    setVertexAttributes(mesh->getMode());

    arrayBuffer.unbind();
    vertexArray.unbind();
}

void GLEWRenderObject::bind(UniformLocations uniformLocations) {
    glUniformMatrix4fv(uniformLocations.model, 1, GL_FALSE, uniform.model.getValuePtr());
}

void GLEWRenderObject::unbind() {
}

void GLEWRenderObject::draw() {
    vertexArray.bind();

    // 6 count, 0 indices
    int vtxCount = this->mesh->getVerticesCount();
    int idxCount = this->mesh->getIndicesCount();

    glDrawElements(convertVertexMode(), idxCount, GL_UNSIGNED_INT, 0);
}

GLenum GLEWRenderObject::convertVertexMode() {
    GLenum mode;

    switch (this->mesh->getMode()) {
        case VertexMode::Triangles:
        case VertexMode::TrianglesWithColours:
            mode = GL_TRIANGLES;
            break;
    }

    return mode;
}

std::shared_ptr<Mesh> GLEWRenderObject::getMesh() {
    return this->mesh;
}

void GLEWRenderObject::setVertexAttributes(VertexMode mode) {
    switch (mode) {
        case VertexMode::Triangles:
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
            break;
        case VertexMode::TrianglesWithColours:
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(3* sizeof(float)));
            glEnableVertexAttribArray(1);
            break;
    }
}

void GLEWRenderObject::translate(float distance, float x, float y, float z) {
    uniform.model.translate(distance, x, y, z);
}

void GLEWRenderObject::rotate(float angle, float x, float y, float z) {
	uniform.model.rotate(angle, glm::vec3(x, y, z));
}