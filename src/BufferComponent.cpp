#include "BufferComponent.h"


BufferComponent::~BufferComponent(){

}

void BufferComponent::generateVAO(GLuint& vao)
{
    bufferObject.generateVAO(vao);
}

void BufferComponent::generateVBO(GLuint& vbo)
{
    bufferObject.generateVBO(vbo);
}

void BufferComponent::generateEBO(GLuint& ebo)
{
    bufferObject.generateEBO(ebo);
}

void BufferComponent::deleteVAO(GLuint& vao)
{
    bufferObject.deleteVAO(vao);
}

void BufferComponent::deleteVBO(GLuint& vbo)
{
    bufferObject.deleteVBO(vbo);
}

void BufferComponent::deleteEBO(GLuint& ebo)
{
    bufferObject.deleteEBO(ebo);
}

void BufferComponent::bindEBO(const std::vector<GLuint>& indices, GLuint& ebo)
{
    bufferObject.bindEBO(ebo, indices.size() * sizeof(unsigned int), &indices[0]);
}


void BufferComponent::setAttribPointer(GLuint index, GLint size, GLsizei stride, int steps){

    bufferObject.setVertexAttribPointer(index, size, stride, steps);
    bufferObject.enableVertexAttribPointer(index);

}

void BufferComponent::setAttribDivisor(GLuint index, GLuint divisor)
{
    bufferObject.setVertexAttribDivisor(index, divisor);
}


void BufferComponent::unbindVBO(){

    bufferObject.unbindVBO();

}

void BufferComponent::unbindEBO()
{
    bufferObject.unbindEBO();
}


void BufferComponent::bindVAO(GLuint& vao){
    bufferObject.bindVAO(vao);
}

void BufferComponent::unbindVAO(){
    bufferObject.unbindVAO();
}
