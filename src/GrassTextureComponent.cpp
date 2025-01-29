#include "GrassTextureComponent.h"


void GrassTextureComponent::applyTexture(){
  
    // init front texture
    texture.init(&textureID[0], GL_TEXTURE0);
    texture.setTextureParameter(GL_CLAMP_TO_BORDER, GL_NEAREST, GL_LINEAR_MIPMAP_LINEAR);
    texture.loadTextureIntoGL(ASSETS_PATH "/cube/grass/cube_grass_normal.png");

    // init top texture
    texture.init(&textureID[1], GL_TEXTURE1);
    texture.setTextureParameter(GL_CLAMP_TO_BORDER, GL_NEAREST, GL_LINEAR_MIPMAP_LINEAR);
    texture.loadTextureIntoGL(ASSETS_PATH "/cube/grass/cube_grass_top.png");

    // init bottom texture
    texture.init(&textureID[2], GL_TEXTURE2);
    texture.setTextureParameter(GL_CLAMP_TO_BORDER, GL_NEAREST, GL_LINEAR_MIPMAP_LINEAR);
    texture.loadTextureIntoGL(ASSETS_PATH "/cube/grass/cube_grass_bottom.png");
   
}

void GrassTextureComponent::sendToShader(const unsigned int& shaderID){

    texture.sendTextureToShader(shaderID, "texture0", 0);
    texture.sendTextureToShader(shaderID, "texture1", 1);
    texture.sendTextureToShader(shaderID, "texture2", 2);

}

void GrassTextureComponent::unbindTexture()
{
    texture.unbindTexture();
}

void GrassTextureComponent::deleteTexture()
{
    texture.deleteTexture(textureID[0]);
    texture.deleteTexture(textureID[1]);
    texture.deleteTexture(textureID[2]);
}
