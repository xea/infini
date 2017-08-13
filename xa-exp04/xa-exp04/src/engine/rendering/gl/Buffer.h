#ifndef XA_BUFFER_H
#define XA_BUFFER_H

#include <GL/glew.h>

class Buffer {
protected:
    unsigned long bufferId;
    
    void bindData(unsigned int bufferId, GLenum target, unsigned int elemCount, void *data);
public:
    Buffer();
    void bind();
    void unbind();
};

#endif // XA_BUFFER_H