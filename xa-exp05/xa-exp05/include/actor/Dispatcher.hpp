#ifndef XA_DISPATCHER_H
#define XA_DISPATCHER_H

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

// -------- Test dispatcher

class TestDispatcher : public Dispatcher {
public:
    void dispatch(std::shared_ptr<Dispatch> receiver, std::unique_ptr<Envelope> envelope);
    std::unique_ptr<Envelope> getLastEnvelope();
    
private:
    std::shared_ptr<Dispatch> lastReceiver;
    std::unique_ptr<Envelope> lastEnvelope{ nullptr };
};

void TestDispatcher::dispatch(std::shared_ptr<Dispatch> receiver, std::unique_ptr<Envelope> envelope) {
    lastReceiver = receiver;
    lastEnvelope = std::move(envelope);
}

std::unique_ptr<Envelope> TestDispatcher::getLastEnvelope() {
    return std::move(lastEnvelope);
}




#endif // XA_DISPATCHER_H
