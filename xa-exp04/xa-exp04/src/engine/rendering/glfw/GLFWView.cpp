#include <engine/rendering/glfw/GLFWView.h>

GLFWView::GLFWView(tuple<int, int> resolution) {
    if (!glfwInit()) {
        // TODO: error handling
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(get<0>(resolution), get<1>(resolution), "xa experiment 04", NULL, NULL);

    if (window) {
        glfwMakeContextCurrent(window);
    } else {
        // TODO: error handling
    }
}

GLFWView::~GLFWView() {
    glfwTerminate();
}

void GLFWView::swapBuffers() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool GLFWView::closeRequested() {
    bool closeRequested = false;

    if (glfwWindowShouldClose(window)) {
        closeRequested = true;
    }

    return closeRequested;
}