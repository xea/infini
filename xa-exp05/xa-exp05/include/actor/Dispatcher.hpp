#ifndef XA_DISPATCHER_H
#define XA_DISPATCHER_H

#include <atomic>

thread_local std::shared_ptr<ActorRef> currentActor;

class Dispatcher {
public:
    Dispatcher() noexcept : executor(std::make_shared<NaiveThreadPoolExecutor>()) {};
    virtual void dispatch(std::shared_ptr<Dispatch> receiver, std::unique_ptr<Envelope> envelope);
    std::shared_ptr<Mailbox> createMailbox(std::shared_ptr<MessageHandler> handler);
private:
    std::shared_ptr<Executor> executor;
    std::atomic_uint64_t msgCount{0};
};

void Dispatcher::dispatch(std::shared_ptr<Dispatch> receiver, std::unique_ptr<Envelope> envelope) {
    auto mailbox = receiver->getMailbox();
    mailbox->enqueue(std::move(envelope));
    
    msgCount++;
    
    if (mailbox->getStatus() == STATUS_IDLE) {
        executor->schedule(mailbox);
    }
}

std::shared_ptr<Mailbox> Dispatcher::createMailbox(std::shared_ptr<MessageHandler> handler) {
    return std::make_shared<Mailbox>(handler);
}

#endif // XA_DISPATCHER_H
