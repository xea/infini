#ifndef XA_VIEW_H
#define XA_VIEW_H

/**
 * View implementations represent surfaces that renderers can draw onto. In most cases these will be windows or
 * canvas surfaces.
 */
class View {
public:

    /**
     * Swap frame buffers, displaying the frame being drawn to.
     */
    virtual void swapBuffers() = 0;
};

#endif // XA_VIEW_H