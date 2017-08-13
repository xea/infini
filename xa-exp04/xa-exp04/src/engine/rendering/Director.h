#ifndef XA_DIRECTOR_H
#define XA_DIRECTOR_H

#include <engine/rendering/Scene.h>

/**
 * Directors decide what contents of the world get rendered on the current scene. Thus, they provide a link
 * between the displayable scenes and the objects that make up the whole world. 
 */
class Director {
public:
    Scene getScene();
};

#endif // XA_DIRECTOR_H