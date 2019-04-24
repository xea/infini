#include <engine/concurrent/ActorSystem.h>

ActorSystem::ActorSystem() {
    executor = make_unique<Executor>();
}

ActorRef ActorSystem::actorOf(string actorId) {
    for (auto& actor : actors) {
        auto currentId = get<0>(actor);

        if (currentId == actorId) {
            ActorRef newRef(get<1>(actor)->getInbox());

            return newRef;
        }
    }

    // TODO this is going to cause problems. find a better way.
    return ActorRef(make_shared<Inbox>([](Message message) {  }));
}

ActorRef ActorSystem::create(string parentActor, string actorId, function<unique_ptr<Actor>()> propsFunc) {
    auto actor = propsFunc();
    auto actorInbox = actor->getInbox();

    auto context = ActorContext(this, actor->children);

    ActorRef newRef(actorInbox);

    actors[actorId] = std::move(actor);

    executor->watch(actorInbox);

    return newRef;
}

ActorSelection ActorSystem::select(string selector) {
    list<ActorRef> localActors; 

    if (selector.length() == 0) {
        // empty selector, no results
        return ActorSelection(localActors);
    } else if (selector[0] == '/') {
        // first character is a slash, extract id and recurse if needed
        auto nextSlashPos = selector.find_first_of('/', 1);

        if (nextSlashPos > 0) {
            
        } else {
            
        }
        
        return ActorSelection(localActors);
    }

    ActorSelection newselection(localActors);

    return newselection;
    /*

    for (auto& actor : actors) {
        auto currentId = get<0>(actor);

        ActorRef newRef(get<1>(actor)->getInbox());

        localActors.push_back(newRef);
    }

    */
}