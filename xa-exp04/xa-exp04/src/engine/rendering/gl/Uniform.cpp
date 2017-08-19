#include <engine/rendering/gl/Uniform.h>

const float* ViewMatrix::getValuePtr() {
    return glm::value_ptr(state);
}

void ViewMatrix::rotateX(float xrot) {
    state = glm::rotate(state, xrot, glm::vec3(1.0f, 0.0f, 0.0f));
}

void ViewMatrix::rotateY(float yrot) {
    state = glm::rotate(state, yrot, glm::vec3(0.0f, 1.0f, 0.0f));
}

void ViewMatrix::rotateZ(float zrot) {
    state = glm::rotate(state, zrot, glm::vec3(0.0f, 0.0f, 1.0f));
}

ViewState::ViewState() {
    glm::mat4 view;
    state = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
}

ProjectionState::ProjectionState(float fov, float aspectRatio) {
    state = glm::perspective(fov, aspectRatio, 0.1f, 100.0f);
}