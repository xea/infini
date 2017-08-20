#ifndef XA_INBOX_H
#define XA_INBOX_H

#include <engine/concurrent/Message.h>
#include <vector>

using namespace std;

class Inbox {
private:
    vector<Message> inboundMessages;
public: 
    void submit(Message message);
};

#endif // XA_INBOX_H