#pragma once

#include "BuffersObjectController.h"

#include <vector>

class BufferComponent{
  private:
    BuffersObjectController bufferObject;
  
  public:
    BufferComponent() = default;
   ~BufferComponent();
  
   void generateVAO(GLuint& vao);
   void generateVBO(GLuint& vbo);
   void generateEBO(GLuint& ebo);

   void deleteVAO(GLuint& vao);
   void deleteVBO(GLuint& vbo);
   void deleteEBO(GLuint& ebo);

   template<typename T>
   void bindVBO(const std::vector<T>& vertices, GLuint& vbo)
   {
       bufferObject.bindVBO(vbo, vertices.size() * sizeof(float), &vertices[0]);
   }

   void bindEBO(const std::vector<GLuint>& indices, GLuint& ebo);
 
   void setAttribPointer(GLuint index, GLint size, GLsizei stride, int steps);
   void setAttribDivisor(GLuint index, GLuint divisor);

   void unbindVBO();
   void unbindEBO();

   void bindVAO(GLuint& vao);
   void unbindVAO();
};
