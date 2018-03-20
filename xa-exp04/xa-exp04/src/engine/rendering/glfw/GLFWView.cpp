#include <engine/rendering/glfw/GLFWView.h>

GLFWView::GLFWView(tuple<int, int> resolution, bool shouldMaximise) {
    if (!glfwInit()) {
        // TODO: error handling
    }

    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // Windowed full screen
    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
	
	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    //void mouse_callback(GLFWwindow* window, double xpos, double ypos);
    //glfwSetCursorPosCallback(window, mouse_callback);  

    const char *windowTitle = "xa experiment 04";

    if (shouldMaximise) {
        window = glfwCreateWindow(mode->width, mode->height, windowTitle, primaryMonitor, NULL);
    } else {
        window = glfwCreateWindow(get<0>(resolution), get<1>(resolution), windowTitle, NULL, NULL);
    }

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

std::tuple<int, int> GLFWView::getCurrentResolution() {
    int xsize, ysize;

    glfwGetWindowSize(window, &xsize, &ysize);

    return { xsize, ysize };
}

std::tuple<int, int> GLFWView::getCursorPosition() {
    double xpos, ypos;

    glfwGetCursorPos(window, &xpos, &ypos);

    return { xpos, ypos };
}
