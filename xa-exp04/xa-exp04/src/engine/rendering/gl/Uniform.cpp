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

void ViewMatrix::rotate(float angle, glm::vec3 direction) {
    state = glm::rotate(state, angle, direction);
}

void ViewMatrix::translate(float distance, float x, float y, float z) {
    state = glm::translate(state, glm::vec3(distance * x, distance * y, distance * z));
}

void ViewMatrix::translate(glm::vec3 translation) {
    state = glm::translate(state, translation);
}

ViewState::ViewState() {
    glm::mat4 view;
    state = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
}

ProjectionState::ProjectionState(float fov, float aspectRatio) {
    state = glm::perspective(glm::radians(fov), aspectRatio, 0.1f, 100.0f);
}