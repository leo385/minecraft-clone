#pragma once

#include "TextureComponent.h"
#include "Texture.h"

class GrassTextureComponent : public TextureComponent{
  private:
      Texture texture;
  public:
      void applyTexture() override;
      void sendToShader(const unsigned int& shaderID) override;
};
