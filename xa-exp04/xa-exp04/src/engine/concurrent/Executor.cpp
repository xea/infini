#include <engine/concurrent/Executor.h>

Executor::Executor() {
    auto cpuCount = thread::hardware_concurrency(); 

    // TODO this should be configurable ideally
    for (int i = 0; i < 1; i++) {
        auto w = watchedInboxes;

        auto newThread = thread([w]() {
            while (true) {
                for (auto inbox : *w) {
                    if (inbox->getMessageCount() > 0) {
                        auto nextMessage = inbox->nextMessage();

                        inbox->processMessage(nextMessage);
                    }
                }

                this_thread::sleep_for(1s);
            }
        });

        newThread.detach();
    }
}

void Executor::watch(shared_ptr<Inbox> inbox) {
    watchedInboxes->push_back(inbox);
}

void Executor::mainLoop() {
    
}