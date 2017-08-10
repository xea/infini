#ifndef XA_SCENE_H
#define XA_SCENE_H

#include <memory>
#include <vector>

#include <engine/rendering/RenderObject.h>
#include <engine/rendering/Primitives.h>

using namespace std;

/**
 * A scene is essentially a collection of render objects that will be rendered on the 
 * current frame.
 */
class Scene {
protected:
    

public:
    std::vector<std::shared_ptr<RenderObject>> getObjects();
};

/**
 * A simplistic Scene implementation that's purpose is to test basic functionalities
 */
class DemoScene : public Scene {

};

#endif // XA_SCENE_H