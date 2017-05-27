#ifndef XA_RENDEROBJECT_H
#define XA_RENDEROBJECT_H

#include <vector>

using namespace std;

/**
 * Represents an object that can be displayed on the screen
 */
class RenderObject {
public:
    virtual void bind() = 0;

    virtual void unbind() = 0;
};

#endif // XA_RENDEROBJECT_H