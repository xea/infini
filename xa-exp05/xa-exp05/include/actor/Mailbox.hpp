#ifndef XA_MAILBOX_H
#define XA_MAILBOX_H

#include <thread>

constexpr uint8_t STATUS_IDLE = 0;
constexpr uint8_t STATUS_SCHEDULED = 1;

class Mailbox {
public:
    Mailbox(std::shared_ptr<MessageHandler> actor) : actor(actor) {};
    void enqueue(std::unique_ptr<Envelope> envelope);
    void dequeue();
    void setAsScheduled();
    void setAsIdle();
    uint8_t getStatus();
private:
    std::deque<std::unique_ptr<Envelope>> messageQueue;
    std::shared_ptr<MessageHandler> actor;
    std::recursive_mutex mailbox_mutex;
    std::atomic_uint status{ STATUS_IDLE };
};

void Mailbox::enqueue(std::unique_ptr<Envelope> envelope) {
    //std::cout << "Locking " << std::this_thread::get_id() << std::endl;
    std::lock_guard<std::recursive_mutex> queue_guard(mailbox_mutex);
    messageQueue.push_back(std::move(envelope));
}

void Mailbox::dequeue() {
    std::lock_guard<std::recursive_mutex> queue_guard(mailbox_mutex);
    
    while (messageQueue.size() > 0) {
        std::unique_ptr<Envelope> envelope = std::move(messageQueue.front());
        messageQueue.pop_front();
        
        if (envelope != nullptr) {
            actor->invoke(std::move(envelope));
        }
    }
    
    setAsIdle();
    
    /*
     std::packaged_task<void()> task([this, e = std::move(envelope)](){
     actor->invoke(e);
     std::cout << "Invoked yiss" << std::endl;
     });
     
     return task.get_future();
     */
}

uint8_t Mailbox::getStatus() {
    return status;
}

void Mailbox::setAsScheduled() {
    status = STATUS_SCHEDULED;
}

void Mailbox::setAsIdle() {
    status = STATUS_IDLE;
}

#endif
