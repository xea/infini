//
//  main.cpp
//  xa-exp04
//
//  Created by Sandor Pecsi on 01/04/2018.
//  Copyright © 2018 xea. All rights reserved.
//
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <engine/actor/ActorSystem.h>
#include <engine/actor/Message.h>

class LocalActor : public Actor {
public:
    void receive(shared_ptr<Message> message) override;
    string getDebugName() override;
};

string LocalActor::getDebugName() {
    return "localActor";
}

void LocalActor::receive(shared_ptr<Message> message) {
    switch (message->getMessageType()) {
        case MessageType::Control:
            context()->select("local").send(message);
            break;
        case MessageType::Force:
            break;
    }
}

int main(int argc, const char * argv[]) {
    auto system = make_unique<ActorSystem>();

    auto localRef1 = system->actorOf("local", [](){ return make_shared<LocalActor>(); });
    auto localRef2 = system->actorOf("local", [](){ return make_shared<LocalActor>(); });
    auto localRef3 = system->actorOf("local", [](){ return make_shared<LocalActor>(); });
    auto localRef4 = system->actorOf("local", [](){ return make_shared<LocalActor>(); });
    
    auto msg = make_shared<ControlMessage>(ControlMessageType::Start);
    localRef1.send(msg);
    
    std::this_thread::sleep_for(2s);
    return 0;
}

