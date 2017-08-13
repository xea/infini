#include <engine/rendering/Scene.h>

std::vector<std::shared_ptr<RenderObject>> Scene::getObjects() {
    auto objects = std::vector<std::shared_ptr<RenderObject>> {};

    auto triangle = std::make_shared<Triangle>();
    auto obj = std::make_shared<GLEWRenderObject>(triangle);
    objects.push_back(obj);

    return objects;
}