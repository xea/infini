#version 330 core

in vec3 fragmentColor;
out vec4 FragColor;
uniform vec2 resolution;

void main() {
    vec2 uv = vec2(gl_FragCoord.x / resolution.x, gl_FragCoord.y / resolution.y);

    // FragColor = vec4(floor(fragmentColor.x * 10), floor(fragmentColor.y * 10), floor(fragmentColor.z * 10), 1.0f);
    //FragColor = vec4(fragmentColor, 1.0f);
    FragColor = vec4(uv.x, uv.y, 0, 1.0f);
}

