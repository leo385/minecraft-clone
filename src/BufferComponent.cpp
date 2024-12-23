#include "BufferComponent.h"

BufferComponent::BufferComponent(){

    bufferObject.generateBuffers();
}

BufferComponent::~BufferComponent(){

    bufferObject.deleteBuffers();
}


void BufferComponent::bindBuffers(const std::vector<GLfloat>& vertices, const std::vector<GLuint>& indices){

    bufferObject.bindVAO();
    
    bufferObject.bindVBO(vertices.size() * sizeof(float), &vertices[0]);
    bufferObject.bindEBO(indices.size() * sizeof(unsigned int), &indices[0]);

}

void BufferComponent::setAttribPointer(){

    // vertex position
    bufferObject.setVertexAttribPointer(0, 3, 5, 0);
    bufferObject.enableVertexAttribPointer(0);

    // tex uv coords
    bufferObject.setVertexAttribPointer(1, 2, 5, 3);
    bufferObject.enableVertexAttribPointer(1);

}


void BufferComponent::unbindBuffers(){

    bufferObject.unbindVBO();
    bufferObject.unbindVAO();

}

void BufferComponent::bindVAO(){
    bufferObject.bindVAO();
}

void BufferComponent::unbindVAO(){
    bufferObject.unbindVAO();
}
