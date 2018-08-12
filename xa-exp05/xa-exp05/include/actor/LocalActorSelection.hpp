#ifndef XA_LOCAL_ACTOR_SELECTION_H
#define XA_LOCAL_ACTOR_SELECTION_H

class LocalActorSelection : public ActorSelection {
protected:
    std::shared_ptr<ActorRef> deliverSelection() override;
public:
    LocalActorSelection(std::shared_ptr<ActorRef> anchor, std::string path) : ActorSelection(anchor, path) {};
};

std::shared_ptr<ActorRef> LocalActorSelection::deliverSelection() {
    auto currentRef = anchor;
    
    while (path.size() > 0) {
        auto currentPath = path.front();
        path.pop_front();
        
        auto refWithCell = std::dynamic_pointer_cast<ActorRefWithCell>(currentRef);
        
        if (refWithCell == nullptr) {
            // TODO uh oh
            break;
        } else {
            if (currentPath == "/") {
                currentRef = std::static_pointer_cast<ActorContext>(refWithCell->getActorCell())->root();
            } else if (currentPath == "..") {
                currentRef = std::static_pointer_cast<ActorContext>(refWithCell->getActorCell())->parent();
            } else {
                currentRef = std::static_pointer_cast<ActorContext>(refWithCell->getActorCell())->child(currentPath);
            }
        }
        
    }
    
    return currentRef;
}

#endif // XA_LOCAL_ACTOR_SELECTION_H
