#ifndef XA_DIRECTOR_H
#define XA_DIRECTOR_H

#include <engine/rendering/Scene.h>
#include <world/World.h>
#include <memory>
#include <cmath>

/**
 * Directors decide what contents of the world get rendered on the current scene. Thus, they provide a link
 * between the displayable scenes and the objects that make up the whole world. 
 */
class Director {
private:
    // CAMERA comes here
    std::shared_ptr<Scene> scene;
    std::unique_ptr<World> world;
public:
    Director(std::unique_ptr<World> world);
    std::shared_ptr<Scene> getScene();
    void update();
};

#endif // XA_DIRECTOR_H