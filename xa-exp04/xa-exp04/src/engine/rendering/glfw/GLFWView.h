#ifndef XA_GLFWVIEW_H
#define XA_GLFWVIEW_H

#include <tuple>

#include <GLFW/glfw3.h>

#include <engine/rendering/View.h>

using namespace std;

class GLFWView : public View {
private:
    GLFWwindow *window;    
public:
    GLFWView(tuple<int, int> resolution);
    ~GLFWView();

    void swapBuffers() override;

    bool closeRequested() override;

    std::tuple<int, int> getCurrentResolution() override;
};

#endif // XA_GLFWVIEW_H