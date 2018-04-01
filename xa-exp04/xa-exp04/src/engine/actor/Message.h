#ifndef XA_ACTOR_MESSAGE_H
#define XA_ACTOR_MESSAGE_H

#include <glm/glm.hpp>

enum class MessageType : unsigned short {
    Control,
    Force
};

class Message {
public:
    virtual MessageType getMessageType() = 0;
};

enum class ControlMessageType : unsigned short {
    Start,
    Stop
};

class ControlMessage : public Message {
    ControlMessageType controlMessageType;
public:

    ControlMessage(ControlMessageType cmsgtype);
    MessageType getMessageType() override;
    ControlMessageType getControlMessageType();
};

class Force : public Message {
public:
    MessageType getMessageType() override;
    Force(glm::vec3 force);
    glm::vec3 force;
};

#endif // XA_ACTOR_MESSAGE_H