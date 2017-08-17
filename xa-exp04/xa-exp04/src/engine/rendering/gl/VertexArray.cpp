#include <engine/rendering/gl/VertexArray.h>

VertexArray::VertexArray() {
    glGenVertexArrays(1, &this->arrayId);
}

void VertexArray::bind() {
    glBindVertexArray(this->arrayId);
}

void VertexArray::unbind() {
    glBindVertexArray(0);
}
