#include <engine/concurrent/Inbox.h>

Inbox::Inbox(function<void(Message)> messageProcessor)  {
    processor = messageProcessor;
}

void Inbox::submit(Message message) {
    processingMutex.lock();
    inboundMessages.push_back(message);
    processingMutex.unlock();
    /*
    batchMutex.lock();
    preQueue.push_back(message);
    batchMutex.unlock();
    */
}

Message Inbox::nextMessage() {
    auto message = inboundMessages.front();
    inboundMessages.pop_front();

    return message;
}

unsigned long Inbox::getMessageCount() {
    return inboundMessages.size();
}

void Inbox::processMessage(Message message) {
    processor(message);
}

void Inbox::processNextMessage() { 
    //lock_guard<mutex> proclock(processingMutex);

    if (processingMutex.try_lock() && getMessageCount() > 0) {
        Message nextMessage = this->nextMessage();
    
        processMessage(nextMessage);

        processingMutex.unlock();
    }
}
