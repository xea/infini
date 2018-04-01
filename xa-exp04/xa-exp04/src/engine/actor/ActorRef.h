#ifndef XA_ACTOR_ACTOR_REF_H
#define XA_ACTOR_ACTOR_REF_H

#include <memory>
#include <engine/actor/Message.h>

using namespace std;

class ActorRef {
protected:
    
public:
    void send(shared_ptr<Message> message);
    void forward();
};

#endif // XA_ACTOR_ACTOR_REF_H