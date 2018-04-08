#include <world/Physics.h>


void Physics::receive(std::shared_ptr<Message> message) {
    auto logger = Logger::getInstance("Physics");
    logger->info("Received message");

    switch (message->getMessageType()) {
        case MessageType::Control:
            context()->select("physics");
            break;
    }
}

std::string Physics::getDebugName() {
    return "physics";
}