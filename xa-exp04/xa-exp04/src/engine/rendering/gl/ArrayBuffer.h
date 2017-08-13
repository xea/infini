#ifndef XA_ARRAYBUFFER_H
#define XA_ARRAYBUFFER_H

#include <GL/glew.h>
#include <memory>
#include <engine/rendering/Mesh.h>

class ArrayBuffer {
private:
    unsigned int bufferId;
public:
    ArrayBuffer();
    void bindMesh(std::shared_ptr<Mesh> mesh);
};

#endif // XA_ARRAYBUFFER_H