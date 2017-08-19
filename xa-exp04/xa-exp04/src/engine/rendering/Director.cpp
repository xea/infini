#include <engine/rendering/Director.h>

Director::Director() {
    
}

std::shared_ptr<Scene> Director::getScene() {
    return std::make_shared<DemoScene>();
}