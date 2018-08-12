#ifndef XA_ACTOR_CELL_H
#define XA_ACTOR_CELL_H

class ActorSystem;

// Actor cells are where concrete actor instances are confined. Each actor cell attempts to conceal it's actor and
// provision it with a context through which the actor can communicate with other actors (or the system itself).
//
// Actor cells, when created are empty (ie. they point to a null actor) and must be assigned an actor in order to
// make it useful.
// Actor cells are where concrete actor instances are confined. Each actor cell attempts to conceal it's actor and
// provision it with a context through which the actor can communicate with other actors (or the system itself).
//
// Actor cells, when created are empty (ie. they point to a null actor) and must be assigned an actor in order to
// make it useful.
class ActorCell : public ActorContext, public MessageHandler, public Dispatch, public std::enable_shared_from_this<ActorCell> {
public:
    ActorCell(std::shared_ptr<ActorSystem> system, std::shared_ptr<Dispatcher> dispatcher) : actor(nullptr), dispatcher(dispatcher), system(system) {};
    void assignActor(std::function<std::unique_ptr<Actor>()> propsFunc);
    void updateRefs(std::shared_ptr<ActorRef> self, std::shared_ptr<ActorRef> parent);
    void updateRefs(std::shared_ptr<ActorRef> self, std::shared_ptr<ActorRef> parent, std::shared_ptr<ActorSystem> system);
    void attachChild(std::shared_ptr<ActorRef> child);
    std::shared_ptr<Mailbox> getMailbox() override;
    // actor references
    std::shared_ptr<ActorRef> self() override;
    std::shared_ptr<ActorRef> parent() override;
    std::shared_ptr<ActorRef> sender() override;
    std::shared_ptr<ActorRef> root() override;
    // actor creation
    std::shared_ptr<ActorRef> actorOf(PropsFunc propsFunc, std::string name) override;
    std::shared_ptr<ActorSelection> actorSelection(std::string selector) override;
    // message handling
    void sendMessage(std::unique_ptr<Envelope> message) override;
    void invoke(std::unique_ptr<Envelope> envelope) override;
protected:
    std::shared_ptr<ActorRef> child(std::string name) override;
    std::vector<std::shared_ptr<ActorRef>> children() override;
private:
    std::unique_ptr<Actor> actor;
    std::shared_ptr<Dispatcher> dispatcher;
    std::shared_ptr<ActorSystem> system;
    std::unique_ptr<Envelope> currentMessage{ nullptr };
    std::shared_ptr<ActorRef> _self;
    std::shared_ptr<ActorRef> _parent;
    std::shared_ptr<Mailbox> _mailbox;
    std::stack<std::unique_ptr<Receive>> behaviourStack;
    std::vector<std::shared_ptr<ActorRef>> _children;
};

void ActorCell::assignActor(std::function<std::unique_ptr<Actor>()> propsFunc) {
    contextStack.push(shared_from_this());
    actor = propsFunc();
    behaviourStack.push(actor->createReceive());
    _mailbox = dispatcher->createMailbox(shared_from_this());
}

void ActorCell::updateRefs(std::shared_ptr<ActorRef> self, std::shared_ptr<ActorRef> parent) {
    updateRefs(self, parent, system);
}

void ActorCell::updateRefs(std::shared_ptr<ActorRef> self, std::shared_ptr<ActorRef> parent, std::shared_ptr<ActorSystem> system) {
    _self = self;
    if (system != nullptr) {
        this->system = system;
    }
}

void ActorCell::attachChild(std::shared_ptr<ActorRef> child) {
    _children.push_back(child);
}

std::shared_ptr<ActorRef> ActorCell::sender() {
    if (currentMessage == nullptr) {
        // TODO
        return nullptr;
    }
    else {
        return currentMessage->sender;
    }
}

std::shared_ptr<ActorRef> ActorCell::parent() {
    return _parent;
}

std::shared_ptr<ActorRef> ActorCell::self() {
    return _self;
}

std::shared_ptr<ActorRef> ActorCell::root() {
    return std::static_pointer_cast<ActorRefFactory>(system)->root();
}

std::shared_ptr<Mailbox> ActorCell::getMailbox() {
    return _mailbox;
}

std::shared_ptr<ActorRef> ActorCell::child(std::string name) {
    for (auto& child : _children) {
        if (child->getPath()->getName() == name) {
            return child;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<ActorRef>> ActorCell::children() {
    return _children;
}

std::shared_ptr<ActorRef> ActorCell::actorOf(PropsFunc propsFunc, std::string name) {
    std::shared_ptr<ActorCell> newCell = std::make_shared<ActorCell>(system, dispatcher);
    newCell->assignActor(propsFunc);
    
    auto localRef = std::make_shared<LocalActorRef>(std::make_shared<ChildActorPath>(self()->getPath(), name), newCell);
    //auto localRef = std::make_shared<LocalActorRef>(self()->getPath(), newCell);
    newCell->updateRefs(localRef, self());
    
    _children.push_back(localRef);
    
    return localRef;
}

std::shared_ptr<ActorSelection> ActorCell::actorSelection(std::string selector) {
    return std::make_shared<LocalActorSelection>(self(), selector);
}

void ActorCell::sendMessage(std::unique_ptr<Envelope> message) {
    dispatcher->dispatch(shared_from_this(), std::move(message));
}

void ActorCell::invoke(std::unique_ptr<Envelope> envelope) {
    currentMessage = std::move(envelope);
    currentActor = self();
    
    behaviourStack.top()->onMessage(std::move(currentMessage->message));
}

#endif // XA_ACTOR_CELL_H
