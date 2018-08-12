#ifndef XA_GUARDIAN_H
#define XA_GUARDIAN_H

// A guardian's role is to supervise a whole hierarchy of actors, guaranteeing that their life-cycle events are respected.
class Guardian : public Actor {
private:
public:
    Guardian() : Actor(nullptr) {};
    std::unique_ptr<Receive> createReceive() override;
};

std::unique_ptr<Receive> Guardian::createReceive() {
    return std::make_shared<ReceiveBuilder>()
    ->match(MessageType::POISON_PILL, [](auto msg) { std::cout << "Handled by guardian" << std::endl; })
    ->build();
}



#endif // XA_GUARDIAN_H
