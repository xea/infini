#ifndef XA_DISPATCHER_H
#define XA_DISPATCHER_H


thread_local std::shared_ptr<ActorRef> currentActor;

class Dispatcher {
private:
    std::shared_ptr<Executor> executor;
public:
    Dispatcher() : executor(std::make_shared<NaiveThreadPoolExecutor>()) {};
    virtual void dispatch(std::shared_ptr<Dispatch> receiver, std::unique_ptr<Envelope> envelope);
    std::shared_ptr<Mailbox> createMailbox(std::shared_ptr<MessageHandler> handler);
};

void Dispatcher::dispatch(std::shared_ptr<Dispatch> receiver, std::unique_ptr<Envelope> envelope) {
    auto mailbox = receiver->getMailbox();
    mailbox->enqueue(std::move(envelope));
    
    if (mailbox->getStatus() == STATUS_IDLE) {
        executor->schedule(mailbox);
    }
}

std::shared_ptr<Mailbox> Dispatcher::createMailbox(std::shared_ptr<MessageHandler> handler) {
    return std::make_shared<Mailbox>(handler);
}

#endif // XA_DISPATCHER_H
