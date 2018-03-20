#include <engine/rendering/Director.h>

Director::Director(std::unique_ptr<World> world) {
    scene = std::make_shared<DemoScene>();
    this->world = std::move(world);
    this->world->start();

    auto cube = std::make_shared<Cube>();
    auto triangle = std::make_shared<Triangle>();

    scene->addObject(cube);
/*
    objects.push_back(std::make_shared<GLEWRenderObject>(triangle));
    objects.push_back(std::make_shared<GLEWRenderObject>(cube));
    */
}

std::shared_ptr<Scene> Director::getScene() {
    return scene;
}

void Director::update() {
    int i = 0;

    for (auto& object : scene->getObjects()) {

/*
        if (i++ % 2 == 0) {
		    //object->rotate(0.01f, 1.0f, 0.5f, 0);
            //object->translate(0.01f, 1.0f, 0, 0);
        } else {
            //object->translate(-0.01f, 1.0f, 0, 0);
		    //object->rotate(-0.01f, 1.0f, 0.5f, 0);
        }
    */
    }
}
