#ifndef XA_DIRECTOR_H
#define XA_DIRECTOR_H

#include <rendering/Scene.h>

class Director {

public:

	virtual Scene& currentScene() = 0;

	virtual void update() = 0;
};

#endif // XA_DIRECTOR