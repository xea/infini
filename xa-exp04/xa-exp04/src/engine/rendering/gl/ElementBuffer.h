#ifndef XA_ELEMENTBUFFER_H
#define XA_ELEMENTBUFFER_H

#include <GL/glew.h>
#include <engine/rendering/Mesh.h>
#include <memory>

class ElementBuffer {
private:
    unsigned int bufferId;
public:
    ElementBuffer();
    void bindMesh(std::shared_ptr<Mesh> mesh);
};

#endif // XA_ELEMENTBUFFER_H
