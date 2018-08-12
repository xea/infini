#ifndef XA_ACTOR_SELECTION_H
#define XA_ACTOR_SELECTION_H

#include <deque>
#include <string>
#include <iostream>

#include "ActorPath.hpp"

// An actor selection is a logical slice of the actor hierarchy that may refer to a single actor or a group of actors 
// allowing broadcasting messages to multiple actors

class ActorSelection {
public:
    ActorSelection(std::shared_ptr<ActorRef> anchor, std::string path);
    ActorSelection(std::shared_ptr<ActorRef> anchor, std::deque<std::string> path) : anchor(anchor), path(path) {};
    void send(std::unique_ptr<Message> message);
protected:
    std::shared_ptr<ActorRef> anchor;
    std::deque<std::string> path;
    virtual std::shared_ptr<ActorRef> deliverSelection() = 0;
};

ActorSelection::ActorSelection(std::shared_ptr<ActorRef> anchor, std::string path) {
    std::string delimiter = ACTOR_PATH_DELIMITER;
    std::string token;
    size_t pos = 0;
    
    if (path.size() > 0) {
        if (path.find(delimiter) == 0) {
            this->path.push_back(delimiter);
            path.erase(0, delimiter.length());
        }
        
        if (path.size() > 0) {
            while ((pos = path.find(delimiter)) != std::string::npos) {
                token = path.substr(0, pos);
                path.erase(0, pos + delimiter.length());
                
                this->path.push_back(token);
            }
            
            if (path.size() > 0) {
                this->path.push_back(path);
            }
        }
    }
    
    this->anchor = anchor;
}

void ActorSelection::send(std::unique_ptr<Message> message) {
    auto ref = deliverSelection();
    
    if (ref == nullptr) {
        // TODO handle error case
        std::cout << "Message wasn't delivered because recipient didn't exist" << std::endl;
    } else {
        ref->send(std::move(message));
    }
}


#endif // XA_ACTOR_SELECTION_H
