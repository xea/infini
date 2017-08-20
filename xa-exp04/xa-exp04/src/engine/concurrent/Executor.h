#ifndef XA_EXECUTOR_H
#define XA_EXECUTOR_H

#include <thread>
#include <vector>

using namespace std;



class Executor {
private:
    vector<thread> availableThreads;
    vector<thread> serviceThreads;

protected:
    void mainLoop();

public:
    

};

#endif // XA_EXECUTOR_H