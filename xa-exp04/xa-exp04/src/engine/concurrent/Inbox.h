#ifndef XA_INBOX_H
#define XA_INBOX_H

#include <engine/concurrent/Message.h>
#include <memory>
#include <functional>
#include <deque>

using namespace std;

class Inbox {
private:
    function<void(Message)> processor;
    deque<Message> inboundMessages;
public: 
    Inbox(function<void(Message)> messageProcessor);
    void submit(Message message);
    unsigned int getMessageCount();
    Message nextMessage();
    void processMessage(Message message);
};

#endif // XA_INBOX_H