#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec2 TexCoord;

uniform sampler2D texture0;
uniform sampler2D texture1;
uniform sampler2D texture2;

void main() {

    // Front wall
    if(FragPos.z >= 0.5){
        FragColor = texture(texture0, TexCoord);
    }

    // Back wall
    if(FragPos.z <= -0.5){
        FragColor = texture(texture0, TexCoord);
    }
    
    // Left wall
    if(FragPos.x <= -0.5){
        FragColor = texture(texture0, TexCoord);
    }
    
    // Right wall
    if(FragPos.x >= 0.5){
        FragColor = texture(texture0, TexCoord);
    }

    // Bottom wall
    if(FragPos.y <= -0.5){
        FragColor = texture(texture2, TexCoord);
    }

    // Up wall
    if(FragPos.y >= 0.5){
        FragColor = texture(texture1, TexCoord);
    }

};