#include <engine/rendering/gl/Uniform.h>

const float* TransformationState::getValuePtr() {
    return glm::value_ptr(state);
}

void TransformationState::rotateX(float xrot) {
    state = glm::rotate(state, xrot, glm::vec3(1.0f, 0.0f, 0.0f));
}

void TransformationState::rotateY(float yrot) {
    state = glm::rotate(state, yrot, glm::vec3(0.0f, 1.0f, 0.0f));
}

void TransformationState::rotateZ(float zrot) {
    state = glm::rotate(state, zrot, glm::vec3(0.0f, 0.0f, 1.0f));
}
