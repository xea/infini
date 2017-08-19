#ifndef XA_VIEW_H
#define XA_VIEW_H

#include <tuple>

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

    /**
     * Indicates whether the user requested the window to close eg. by clicking on the window's close button.
     */
    virtual bool closeRequested() = 0;

    virtual std::tuple<int, int> getCurrentResolution() = 0;
};

#endif // XA_VIEW_H