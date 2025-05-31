#pragma once

#include "Texture.h"
#include "TextureComponent.h"

class GrassTextureComponent : public TextureComponent {
public:
  ~GrassTextureComponent() = default;

private:
  Texture texture;

public:
  void applyTexture() override;
  void sendToShader(const unsigned int &shaderID) override;
};
