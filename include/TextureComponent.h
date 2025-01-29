#pragma once

class TextureComponent{
  public:
      virtual void applyTexture() = 0;
      virtual void sendToShader(const unsigned int& shaderID) = 0;
      virtual void unbindTexture() = 0;
      virtual void deleteTexture() = 0;
};
