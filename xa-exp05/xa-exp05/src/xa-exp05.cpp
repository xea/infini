#include "xa-exp05.h"

#include <cstdlib>

using namespace std;

class Echo : public Actor {
public:
    inline std::unique_ptr<Receive> createReceive() override {
        return make_shared<ReceiveBuilder>()
        ->match(MessageType::TEST_MESSAGE, [this](auto msg){
            //cout << "Received test message" << endl;
            uint64_t sum{0};
            
            for (int i = 0; i < 10000000; i++) {
                sum += rand();
            }
            
            cout << "rand " << this_thread::get_id() << " sum " << sum << endl;
            
            context->sender()->send(move(msg));
        })
        ->build();
    }
};

class Generator : public Actor {
public:
    inline std::unique_ptr<Receive> createReceive() override {
        return make_shared<ReceiveBuilder>()
        ->match(MessageType::TEST_MESSAGE, [this](auto msg) {
            for (int i = 0; i < 1; i++) {
                string name = "/user/echo";
                
                string number = to_string(rand() % 8);
                
                name.append(number);
                
                context->actorSelection(name)->send(make_unique<TestMessage>());
            }
        })
        ->build();
    }
};


int MAIN {
    auto actorSystem = make_shared<ActorSystem>("vertex");
    
    auto echo0 = actorSystem->actorOf([](){ return make_unique<Echo>(); }, "echo0");
    auto echo1 = actorSystem->actorOf([](){ return make_unique<Echo>(); }, "echo1");
    auto echo2 = actorSystem->actorOf([](){ return make_unique<Echo>(); }, "echo2");
    auto echo3 = actorSystem->actorOf([](){ return make_unique<Echo>(); }, "echo3");
    auto echo4 = actorSystem->actorOf([](){ return make_unique<Echo>(); }, "echo4");
    auto echo5 = actorSystem->actorOf([](){ return make_unique<Echo>(); }, "echo5");
    auto echo6 = actorSystem->actorOf([](){ return make_unique<Echo>(); }, "echo6");
    auto echo7 = actorSystem->actorOf([](){ return make_unique<Echo>(); }, "echo7");
    
    auto generator = actorSystem->actorOf([](){ return make_unique<Generator>(); }, "generator");
    
    cout << "Actor system: " << actorSystem->getName() << endl;
    
    generator->send(make_unique<TestMessage>());

    //actorSystem->runSync();
    std::this_thread::sleep_for(60s);
    
    cout << "Exiting" << endl;
	return 0;
}
