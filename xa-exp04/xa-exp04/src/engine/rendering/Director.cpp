#include <engine/rendering/Director.h>

std::shared_ptr<Scene> Director::getScene() {
    return std::make_shared<DemoScene>();
}