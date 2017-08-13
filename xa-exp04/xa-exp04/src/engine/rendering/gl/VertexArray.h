#ifndef XA_VERTEXARRAY_H
#define XA_VERTEXARRAY_H

#include <GL/glew.h>

class VertexArray {
private:
    unsigned int arrayId;
public:
    VertexArray();

    void bind();
    void unbind();
};

#endif // XA_VERTEXARRAY_H