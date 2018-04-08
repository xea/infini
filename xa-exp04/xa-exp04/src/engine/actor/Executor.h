#ifndef XA_EXECUTOR_H
#define XA_EXECUTOR_H

#include <engine/actor/Inbox.h>
#include <engine/logging/Logger.h>
#include <memory>
#include <thread>
#include <vector>

// temp includes
#include <iostream>

using namespace std;

class Executor {
private:
    vector<thread> serviceThreads;
    shared_ptr<vector<shared_ptr<Inbox>>> watchedInboxes{ make_shared<vector<shared_ptr<Inbox>>>() };
    shared_ptr<Logger> logger;

protected:
    void mainLoop();

public:
    Executor();

    void watch(shared_ptr<Inbox> inbox);
};

#endif // XA_EXECUTOR_H