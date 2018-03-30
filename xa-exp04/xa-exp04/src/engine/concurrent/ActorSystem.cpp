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

ActorRef ActorSystem::create(string actorId, function<unique_ptr<Actor>()> propsFunc) {
    auto context = ActorContext(this);

    auto actor = propsFunc();
    auto actorInbox = actor->getInbox();

    ActorRef newRef(actorInbox);

    actors[actorId] = std::move(actor);

    executor->watch(actorInbox);

    return newRef;
}
