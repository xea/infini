#ifndef XA_ACTOR_MESSAGE_H
#define XA_ACTOR_MESSAGE_H

#include <glm/glm.hpp>

class Message {

};

class Force : public Message {
public:
    Force(glm::vec3 force);
    glm::vec3 force;
};

#endif // XA_ACTOR_MESSAGE_H