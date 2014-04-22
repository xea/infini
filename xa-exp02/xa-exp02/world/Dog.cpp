#include "Dog.h"

Dog::Dog() {
	//visual = new Triangle();
	visual = new Cube();
}

RenderObject &Dog::renderObject() {
	return *visual;
}