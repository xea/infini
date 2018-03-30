#include <engine/concurrent/Actor.h>

Actor::Actor(shared_ptr<ActorContext> localContext) {
    this->localContext = std::move(localContext);
    inbox = make_shared<Inbox>([this](Message message) { this->receive(message); });
}

shared_ptr<Inbox> Actor::getInbox() {
    return inbox;
}

shared_ptr<ActorContext> Actor::context() {
    return localContext;
}

/*
void TestActor::receive(Message message) {
    //cout << "Received actor message yay, ctr:" << counter << " " << this_thread::get_id() << endl;
    counter++;
}

Scheduler::Scheduler(list<function<void()>> taskList) {
    Actor();
}

void Scheduler::receive(Message message) {
    
}
*/