#ifndef XA_SCENE_H
#define XA_SCENE_H

#include <list>
#include <core/Entity.h>
#include <rendering/RenderObject.h>

using namespace std;

/**
 * Manages the objects that appear on the screen
 */
class Scene {

private:

	
public:

	/**
	 * Holds references to objects that are to be rendered on-screen
	 */
	list<RenderObject *> objects;

	list<Entity *> entities;

	Scene();
};

#endif // XA_SCENE_H