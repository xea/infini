#include "Dog.h"

Dog::Dog() {
	visual = new Triangle();
}

RenderObject &Dog::renderObject() {
	return *visual;
}