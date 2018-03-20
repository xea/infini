#ifndef XA_SCENE_H
#define XA_SCENE_H

#include <memory>
#include <vector>

#include <engine/rendering/RenderObject.h>
#include <engine/rendering/glew/GLEWRenderObject.h>
#include <engine/rendering/gl/Uniform.h>
#include <engine/rendering/Mesh.h>

using namespace std;

/**
 * A scene is essentially a collection of render objects that will be rendered on the 
 * current frame.
 */
class Scene {
protected:
    

public:
    virtual std::vector<std::shared_ptr<RenderObject>> getObjects() = 0;
    virtual std::shared_ptr<ViewState> getViewState() = 0;
    virtual std::shared_ptr<ProjectionState> getProjectionState() = 0;
    virtual void addObject(std::shared_ptr<RenderObject> object) = 0;
};

/**
 * A simplistic Scene implementation that's purpose is to test basic functionalities
 */
class DemoScene : public Scene {
private:
    std::vector<std::shared_ptr<RenderObject>> objects;
public:
    DemoScene();

    std::vector<std::shared_ptr<RenderObject>> getObjects() override;

    std::shared_ptr<ViewState> getViewState() override;
    std::shared_ptr<ProjectionState> getProjectionState() override;

    void addObject(std::shared_ptr<RenderObject> object) override;
    
};

#endif // XA_SCENE_H