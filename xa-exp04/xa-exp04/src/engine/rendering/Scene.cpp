#include <engine/rendering/Scene.h>

DemoScene::DemoScene() {
    auto objects = std::vector<std::shared_ptr<RenderObject>> {};

    auto cube = std::make_shared<Cube>();
    auto triangle = std::make_shared<Triangle>();

    objects.push_back(std::make_shared<GLEWRenderObject>(triangle));
    objects.push_back(std::make_shared<GLEWRenderObject>(cube));

    this->objects = objects;
}

std::vector<std::shared_ptr<RenderObject>> DemoScene::getObjects() {
    return objects;
}

std::shared_ptr<ViewState> DemoScene::getViewState() {
    return std::make_shared<ViewState>();
}

std::shared_ptr<ProjectionState> DemoScene::getProjectionState() {
    return std::make_shared<ProjectionState>(45.0f, 1.6f);
}
