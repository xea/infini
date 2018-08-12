#include "xa-exp05.h"

using namespace std;

int MAIN {
    auto actorSystem = make_unique<ActorSystem>("vertex");
    
    cout << "Actor system: " << actorSystem->getName() << endl;

	return 0;
}
