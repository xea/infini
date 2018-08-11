#include "xa-exp05.h"

using namespace std;

int MAIN {
    auto rootPath = make_unique<RootActorPath>();
    auto mailbox = make_unique<Mailbox>(nullptr);
    cout << "Root path: " << rootPath->getFullName() << endl;
    cout << "Mailbox status: " << mailbox->getStatus() << endl;
    
	return 0;
}

