#include <engine/rendering/glew/GLEWRenderObject.h>

GLEWRenderObject::GLEWRenderObject(std::shared_ptr<Mesh> mesh) {
    this->mesh = mesh;

    vertexArray.bind();
    arrayBuffer.bindMesh(mesh);
    elementBuffer.bindMesh(mesh);

    // TODO tidy up this shit

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    arrayBuffer.unbind();
    vertexArray.unbind();
}

void GLEWRenderObject::bind(UniformLocations uniformLocations) {
    glUniformMatrix4fv(uniformLocations.transformation, 1, GL_FALSE, uniform.transformation.getValuePtr());
//    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transformation_matrix));
}

void GLEWRenderObject::unbind() {
}

void GLEWRenderObject::draw() {
    vertexArray.bind();

    // 6 count, 0 indices
    int vtxCount = this->mesh->getVerticesCount();
    int idxCount = this->mesh->getIndicesCount();

    glDrawElements(convertVertexMode(), vtxCount, GL_UNSIGNED_INT, 0);
}

GLenum GLEWRenderObject::convertVertexMode() {
    GLenum mode;

    switch (this->mesh->getMode()) {
        case VertexMode::Triangles:
            mode = GL_TRIANGLES;
            break;
    }

    return mode;
}

std::shared_ptr<Mesh> GLEWRenderObject::getMesh() {
    return this->mesh;
}