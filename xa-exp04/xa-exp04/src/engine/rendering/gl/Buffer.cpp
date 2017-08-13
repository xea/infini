#include <engine/rendering/gl/Buffer.h>

Buffer::Buffer() {
    unsigned int bufferId;
    glGenBuffers(1, &bufferId);
    this->bufferId = bufferId;
}

void Buffer::bindData(unsigned int bufferId, GLenum target, unsigned int elemCount, void *data) {
    glBindBuffer(target, bufferId);
    glBufferData(target, elemCount, data, GL_STATIC_DRAW);
}