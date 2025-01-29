#pragma once

#include "TextureComponent.h"
#include "Texture.h"

class GrassTextureComponent : public TextureComponent{
  private:
      Texture texture;
      GLuint textureID[3];
  public:
      void applyTexture() override;
      void sendToShader(const unsigned int& shaderID) override;
      void unbindTexture() override;
      void deleteTexture() override;
};
