#pragma once

class TextureComponent {
public:
  virtual ~TextureComponent() = default;
  virtual void applyTexture() = 0;
  virtual void sendToShader(const unsigned int &shaderID) = 0;
};
