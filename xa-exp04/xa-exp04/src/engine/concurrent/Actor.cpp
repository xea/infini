#include <engine/concurrent/Actor.h>

Actor::Actor() {
    inbox = make_shared<Inbox>([this](Message message) { this->receive(message); });
}

shared_ptr<Inbox> Actor::getInbox() {
    return inbox;
}

ActorContext Actor::context() {
    ActorContext ctx;

    return ctx;
}

void TestActor::receive(Message message) {
    //cout << "Received actor message yay, ctr:" << counter << " " << this_thread::get_id() << endl;
    counter++;
}

Scheduler::Scheduler(list<function<void()>> taskList) {
    
}

void Scheduler::receive(Message message) {
    
}