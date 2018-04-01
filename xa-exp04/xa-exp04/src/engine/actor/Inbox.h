#ifndef XA_INBOX_H
#define XA_INBOX_H

#include <engine/actor/Message.h>
#include <memory>
#include <functional>
#include <deque>
#include <mutex>
#include <vector>

using namespace std;

class Inbox {
private:
    function<void(shared_ptr<Message>)> processor;
    deque<shared_ptr<Message>> inboundMessages;
    vector<shared_ptr<Message>> preQueue;
    mutex processingMutex;
    mutex batchMutex;
protected:
    shared_ptr<Message> nextMessage();
    void processMessage(shared_ptr<Message> message);
public: 
    Inbox(function<void(shared_ptr<Message>)> messageProcessor);
    void submit(shared_ptr<Message> message);
    unsigned long getMessageCount();
    void processNextMessage();

};

#endif // XA_INBOX_H
