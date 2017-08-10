#include <engine/rendering/Scene.h>

std::vector<std::shared_ptr<RenderObject>> Scene::getObjects() {
    auto objects = std::vector<std::shared_ptr<RenderObject>> {};

    objects.push_back(std::make_shared<Triangle>());

    return objects;
}