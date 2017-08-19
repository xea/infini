#ifndef XA_GLEWRENDEROBJECT_H
#define XA_GLEWRENDEROBJECT_H

//#include <engine/rendering/glew/GLEWRenderer.h>
#include <GL/glew.h> // TODO this should be the above GLEWRenderer.h but it's throwing silly errors
#include <engine/rendering/RenderObject.h>
#include <engine/rendering/gl/VertexArray.h>
#include <engine/rendering/gl/ArrayBuffer.h>
#include <engine/rendering/gl/ElementBuffer.h>
#include <engine/rendering/gl/Uniform.h>
#include <memory>

#include <engine/logging/Logger.h>
#include <string>

using namespace std;

class GLEWRenderObject : public RenderObject {
private:
    std::shared_ptr<Mesh> mesh;

    VertexArray vertexArray;
    ArrayBuffer arrayBuffer;
    ElementBuffer elementBuffer;

    GLenum convertVertexMode();
    void setVertexAttributes(VertexMode mode);
public:
    GLEWRenderObject(std::shared_ptr<Mesh> mesh);

    void bind(UniformLocations uniformLocations) override;

    void draw() override;

    void unbind() override;

    std::shared_ptr<Mesh> getMesh() override;

    void translate(float distance, float x, float y, float z) override;
};

#endif // XA_GLEWRENDEROBJECT_H