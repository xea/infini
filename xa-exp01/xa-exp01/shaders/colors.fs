#version 420 core
out vec3 color;

in vec3 fragmentColor;

void main(){
    
    color = fragmentColor; //vec3(1.0,1.0,1.0);
}