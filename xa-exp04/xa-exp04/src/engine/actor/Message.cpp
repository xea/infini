#include <engine/actor/Message.h>

ControlMessage::ControlMessage(ControlMessageType cmsgtype) {
    this->controlMessageType = cmsgtype;
}

MessageType ControlMessage::getMessageType() {
    return MessageType::Control;
}

ControlMessageType ControlMessage::getControlMessageType() {
    return controlMessageType;
}

/*
MessageType Force::getMessageType() {
    return MessageType::Force;
}

Force::Force(glm::vec3 force) {
    this->force = force;
}

*/