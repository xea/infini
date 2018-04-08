#ifndef XA_INBOX_H
#define XA_INBOX_H

#include <engine/actor/Message.h>
#include <engine/logging/Logger.h>
#include <memory>
#include <functional>
#include <deque>
#include <mutex>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class MessageProcessor {
public:
    virtual void receive(shared_ptr<Message> message) = 0;
    virtual string getDebugName() = 0;
};

class Inbox {
private:
    shared_ptr<MessageProcessor> processor;
    deque<shared_ptr<Message>> inboundMessages;
    vector<shared_ptr<Message>> preQueue;
    mutex processingMutex;
    mutex batchMutex;
protected:
    shared_ptr<Message> nextMessage();
    void processMessage(shared_ptr<Message> message);
public: 
    Inbox(shared_ptr<MessageProcessor> messageProcessor);
    void submit(shared_ptr<Message> message);
    unsigned long getMessageCount();
    void processNextMessage();

};

#endif // XA_INBOX_H
