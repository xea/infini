#include <engine/rendering/gl/Uniform.h>

const float* ViewMatrix::getValuePtr() {
    return glm::value_ptr(state);
}

void ViewMatrix::rotate(float angle, glm::vec3 direction) {
    state = glm::rotate(state, angle, direction);
}

void ViewMatrix::translate(float x, float y, float z) {
    state = glm::translate(state, glm::vec3(x, y, z));
}

void ViewMatrix::translate(glm::vec3 translation) {
    state = glm::translate(state, translation);
}

void ViewMatrix::scale(float x, float y, float z) {
    state = glm::scale(state, glm::vec3(x, y, z));
}

void ViewMatrix::scale(glm::vec3 scale) {
    state = glm::scale(state, scale);
}

void ViewMatrix::lookAt(glm::vec3 position, glm::vec3 target, glm::vec3 up) {
	state = glm::lookAt(position, target, up);
}

ViewState::ViewState() {
    glm::mat4 view;
    state = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
}

ProjectionState::ProjectionState(float fov, float aspectRatio) {
    state = glm::perspective(glm::radians(fov), aspectRatio, 0.1f, 100.0f);
}