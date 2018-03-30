#include <engine/rendering/Director.h>

Director::Director(std::unique_ptr<World> world) {
    scene = std::make_shared<DemoScene>();
    this->world = std::move(world);
    this->world->start();

    
/*
    auto object = std::make_shared<Object>(std::make_shared<GLEWRenderObject>(std::make_shared<Cube>()), 1.0);
    auto ground = std::make_shared<Object>(std::make_shared<GLEWRenderObject>(std::make_shared<Cube>()), 999999999999999.0);

    ground->getRenderObject()->scale(1.0, 1.0, 1.0)->translate(1.0, -1.0, 0.0);

    this->world->addObject(ground);
    scene->addObject(ground->getRenderObject());

    this->world->addObject(object);
    scene->addObject(object->getRenderObject());
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
