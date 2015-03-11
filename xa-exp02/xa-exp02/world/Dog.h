#ifndef XA_DOG_H
#define XA_DOG_H

#include <core/Entity.h>
#include <rendering/model/Triangle.h>
#include <rendering/model/Cube.h>

class Dog : public Entity {

private:

	RenderObject *visual;

public:

	Dog();

    ~Dog();

	RenderObject& renderObject();
};

#endif // XA_DOG_H
