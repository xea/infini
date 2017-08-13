#ifndef XA_ARRAYBUFFER_H
#define XA_ARRAYBUFFER_H

#include <memory>
#include <engine/rendering/gl/Buffer.h>
#include <engine/rendering/Mesh.h>

class ArrayBuffer : public Buffer {
public:
    ArrayBuffer();
    void bindMesh(std::shared_ptr<Mesh> mesh);
};

#endif // XA_ARRAYBUFFER_H