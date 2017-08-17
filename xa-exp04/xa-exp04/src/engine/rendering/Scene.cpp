#include <engine/rendering/Scene.h>

DemoScene::DemoScene() {
    auto objects = std::vector<std::shared_ptr<RenderObject>> {};

    auto triangle = std::make_shared<Triangle>();
    auto obj = std::make_shared<GLEWRenderObject>(triangle);
    objects.push_back(obj);

    this->objects = objects;
}

std::vector<std::shared_ptr<RenderObject>> DemoScene::getObjects() {
    return objects;
}