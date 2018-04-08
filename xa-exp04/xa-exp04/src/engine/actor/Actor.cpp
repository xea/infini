#include <engine/actor/Actor.h>

Actor::Actor() {
    children = make_shared<list<shared_ptr<ActorRef>>>();
    // the default actor implementation's inbox will simply call receive() for each submitted message
    /*
    actorInbox = make_shared<Inbox>([this](std::shared_ptr<Message> message) { 
        auto logger = Logger::getInstance("Actor inbox");
        std::stringstream ss;

        ss << "Received message " << (unsigned short) message->getMessageType() << " to " << this->getDebugName();

        this->receive(message); 
        logger->info(ss.str());
    });
    */
}

std::shared_ptr<ActorContext> Actor::context() {
    return this->actorContext;
}

std::shared_ptr<Inbox> Actor::inbox() {
    return this->actorInbox;
}

shared_ptr<list<shared_ptr<ActorRef>>> Actor::getChildren() {
    return this->children;
}

RenderActor::RenderActor(std::shared_ptr<Object> object) {
    this->object = object;
}

void RenderActor::receive(std::shared_ptr<Message> message) {
    auto logger = Logger::getInstance("RenderActor");

    logger->info("Received message");
}

std::string RenderActor::getDebugName() {
    return "renderactor";
}
