#include "Dog.h"

Dog::Dog() {
	//visual = new Triangle();
	visual = new Cube();
}

Dog::~Dog() {
    delete visual;
}

RenderObject &Dog::renderObject() {
	return *visual;
}
