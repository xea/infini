#include <world/Physics.h>

void Physics::receive(Message message) {
    // this call never returns
    for (auto& actor : context()->select("").all()) {
        
    }
}
