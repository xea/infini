#include <engine/concurrent/Executor.h>

Executor::Executor() {
    auto cpuCount = thread::hardware_concurrency(); 

    // TODO this should be configurable ideally
    for (int i = 0; i < cpuCount - 1; i++) {
        auto w = watchedInboxes;

        auto newThread = thread([w]() {
            bool didProcess = false;

            while (true) {
                didProcess = false;

                for (auto inbox : *w) {
                    if (inbox->getMessageCount() > 0) {
                        inbox->processNextMessage();
                        didProcess = true;
                    }
                }

                // In case we have nothing to do, let's throttle things back a bit
                if (!didProcess) {
                    this_thread::sleep_for(10ms);
                }
            }
        });

        newThread.detach();
        serviceThreads.push_back(move(newThread));
    }
}

void Executor::watch(shared_ptr<Inbox> inbox) {
    watchedInboxes->push_back(inbox);
}

void Executor::mainLoop() {
    
}