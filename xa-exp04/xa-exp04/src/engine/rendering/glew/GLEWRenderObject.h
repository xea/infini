#ifndef XA_GLEWRENDEROBJECT_H
#define XA_GLEWRENDEROBJECT_H

#include <engine/rendering/RenderObject.h>

class GLEWRenderObject : public RenderObject {
public:
    void bind() override;

    void unbind() override;

};

#endif // XA_GLEWRENDEROBJECT_H