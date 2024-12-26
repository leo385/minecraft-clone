#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 3) in vec3 instancePosition;

uniform mat4 mvp;

out vec3 FragPos;
out vec2 TexCoord;

void main() {

    vec3 worldPosition = aPos + instancePosition;
    gl_Position = mvp * vec4(worldPosition, 1.0);
    
    FragPos = aPos;
    TexCoord = aTexCoord;

};