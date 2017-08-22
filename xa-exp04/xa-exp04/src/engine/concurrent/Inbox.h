#ifndef XA_INBOX_H
#define XA_INBOX_H

#include <engine/concurrent/Message.h>
#include <memory>
#include <functional>
#include <deque>
#include <mutex>

using namespace std;

class Inbox {
private:
    function<void(Message)> processor;
    deque<Message> inboundMessages;
    mutex processingMutex;
protected:
    Message nextMessage();
    void processMessage(Message message);
public: 
    Inbox(function<void(Message)> messageProcessor);
    void submit(Message message);
    unsigned int getMessageCount();
    void processNextMessage();

};

#endif // XA_INBOX_H