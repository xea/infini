#ifndef XA_DISPATCH_H
#define XA_DISPATCH_H

class Mailbox;

class Dispatch {
public:
    virtual std::shared_ptr<Mailbox> getMailbox() = 0;
};

#endif // XA_DISPATCH_H
