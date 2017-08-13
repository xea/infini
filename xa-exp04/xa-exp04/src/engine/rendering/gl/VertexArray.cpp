#include <engine/rendering/gl/VertexArray.h>

VertexArray::VertexArray() {
    unsigned int arrayId;
    glGenVertexArrays(1, &arrayId);

    this->arrayId = arrayId;
}

void VertexArray::bind() {
    glBindVertexArray(this->arrayId);
}

void VertexArray::unbind() {
    glBindVertexArray(0);
}
