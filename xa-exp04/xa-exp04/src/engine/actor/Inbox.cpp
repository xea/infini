#include <engine/actor/Inbox.h>

Inbox::Inbox(shared_ptr<MessageProcessor> messageProcessor)  {
    processor = messageProcessor;
}

void Inbox::submit(shared_ptr<Message> message) {
    processingMutex.lock();
    inboundMessages.push_back(message);
    processingMutex.unlock();
    /*
    batchMutex.lock();
    preQueue.push_back(message);
    batchMutex.unlock();
    */
}

shared_ptr<Message> Inbox::nextMessage() {
    auto message = inboundMessages.front();
    inboundMessages.pop_front();

    return message;
}

unsigned long Inbox::getMessageCount() {
    return inboundMessages.size();
}

void Inbox::processMessage(shared_ptr<Message> message) {
    stringstream logmsg;

    logmsg << "Processing message " << (unsigned short) message->getMessageType() << " to " << processor->getDebugName();
    
    Logger::getInstance("Inbox")->info(logmsg.str());
    processor->receive(message);
}

void Inbox::processNextMessage() { 
    //lock_guard<mutex> proclock(processingMutex);

    if (processingMutex.try_lock() && getMessageCount() > 0) {
        shared_ptr<Message> nextMessage = this->nextMessage();
    
        processMessage(nextMessage);

        processingMutex.unlock();
    }
}
