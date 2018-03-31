#ifndef XA_UNIFORM_H
#define XA_UNIFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

enum class UniformType : unsigned int {
    ModelMatrix,
    ViewMatrix,
    ProjectionMatrix,
    Resolution,
    FrameCount,
    Time
};

class ViewMatrix {
protected: 
    glm::mat4 state;

public:
    const float* getValuePtr();
    void rotate(float angle, glm::vec3 direction);
    void translate(float x, float y, float z);
    void translate(glm::vec3 translation);
    void scale(float x, float y, float z);
    void scale(glm::vec3 scale);
	void lookAt(glm::vec3 position, glm::vec3 target, glm::vec3 up);
};

class ModelState : public ViewMatrix {
};

class ViewState : public ViewMatrix {
public:
    ViewState();
};

class ProjectionState : public ViewMatrix {
public:
    ProjectionState(float fov, float aspectRatio);
};

class UniformLocations {
public: 
    unsigned int model;
    unsigned int view;
    unsigned int projection;
    unsigned int resolution;
    unsigned int frameCount;
    unsigned int time;
};

class Uniform {
private:
public:
    ModelState model;
    UniformLocations locations;
};


#endif // XA_UNIFORM_H