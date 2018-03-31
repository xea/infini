#include <engine/actor/Message.h>

Force::Force(glm::vec3 force) {
    this->force = force;
}

ControlMessage::ControlMessage(ControlMessageType cmsgtype) {
    this->controlMessageType = cmsgtype;
}

MessageType ControlMessage::getMessageType() {
    return MessageType::Control;
}

ControlMessageType ControlMessage::getControlMessageType() {
    return controlMessageType;
}

MessageType Force::getMessageType() {
    return MessageType::Force;
}