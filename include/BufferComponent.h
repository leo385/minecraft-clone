#pragma once

#include "BuffersObjectController.h"

#include <vector>

class BufferComponent{
  private:
    BuffersObjectController bufferObject;
  
  public:
   BufferComponent();
   ~BufferComponent();
  
   void bindBuffers(const std::vector<GLfloat>& vertices, const std::vector<GLuint>& indices);
   void setAttribPointer();
   void unbindBuffers();

   void bindVAO();
   void unbindVAO();
};
