#ifndef XA_SCENE_H
#define XA_SCENE_H

#include <list>
#include <memory>

#include <engine/rendering/RenderObject.h>

class Scene {
private:
	std::list<std::shared_ptr<RenderObject>> objects;
public:
	void add(std::unique_ptr<RenderObject> object);
	std::list<std::shared_ptr<RenderObject>> getObjects();
};

#endif // XA_SCENE_H