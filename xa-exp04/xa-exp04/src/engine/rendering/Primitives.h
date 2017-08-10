#ifndef XA_PRIMITIVES_H
#define XA_PRIMITIVES_H

#include <engine/rendering/RenderObject.h>

class Triangle : public RenderObject {
public:
    void bind();

    void unbind();
};

#endif // XA_PRIMITIVES_H