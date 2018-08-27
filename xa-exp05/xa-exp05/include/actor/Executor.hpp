#ifndef XA_EXECUTOR_H
#define XA_EXECUTOR_H

#include <thread>

using namespace std::chrono_literals;

class Executor {
public:
    virtual void schedule(std::shared_ptr<Mailbox> mailboxEvent) = 0;
};

// -----------
class LocklessThreadPoolExecutor : public Executor {
public:
    LocklessThreadPoolExecutor();
    void schedule(std::shared_ptr<Mailbox> mailboxEvent) override;
};

LocklessThreadPoolExecutor::LocklessThreadPoolExecutor() {
    auto cpuCount = std::thread::hardware_concurrency();
    
    for (uint8_t i = 0; i < cpuCount; i++) {
        auto newThread = std::thread([this]() {
        });
    }
}

void LocklessThreadPoolExecutor::schedule(std::shared_ptr<Mailbox> mailboxEvent) {
    
}

// -----------
class NaiveThreadPoolExecutor : public Executor {
public:
    NaiveThreadPoolExecutor();
    void schedule(std::shared_ptr<Mailbox> mailboxEvent) override;
private:
    std::vector<std::thread> serviceThreads;
    std::deque<std::shared_ptr<Mailbox>> workQueue;
    std::recursive_mutex workQueueMutex;
};

NaiveThreadPoolExecutor::NaiveThreadPoolExecutor() {
    auto cpuCount = std::thread::hardware_concurrency();
    
    for (uint8_t i = 0; i < cpuCount; i++) {
        auto newThread = std::thread([this]() {
            // TODO support shutdown
            while (true) {
                if (workQueue.size() > 0) {
                    std::lock_guard<std::recursive_mutex> process_lock(workQueueMutex);
                    
                    if (workQueue.size() > 0) {
                        auto mailbox = workQueue.front();
                        workQueue.pop_front();
                        
                        // process actor mailbox
                        mailbox->dequeue();
                    }
                }
                else {
                    std::this_thread::sleep_for(10ms);
                }
            }
            
        });
        
        newThread.detach();
        
        serviceThreads.push_back(std::move(newThread));
    }
}

void NaiveThreadPoolExecutor::schedule(std::shared_ptr<Mailbox> mailboxEvent) {
    // if already scheduled then do nothing
    // otherwise add task to work queue
    std::lock_guard<std::recursive_mutex> lock(workQueueMutex);
    mailboxEvent->setAsScheduled();
    workQueue.push_back(mailboxEvent);
}

#endif // XA_EXECUTOR_H
