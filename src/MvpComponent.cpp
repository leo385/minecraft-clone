#include "MvpComponent.h"

#include <GL/glew.h>

void MvpComponent::setMvpMatrix(){
  
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, -3.0f));
    view = glm::rotate(model, glm::radians(-55.0f), glm::vec3(0.0f, 0.0f, 0.0f));
    projection = glm::perspective(glm::radians(60.0f), 800.0f / 600.f, 0.1f, 100.0f);
}

void MvpComponent::setViewFromCamera(const glm::vec3 &source, const glm::vec3 &destination, const glm::vec3 &UpDirection){

    view = glm::lookAt(source, destination, UpDirection);
}

void MvpComponent::setViewRotate(const float& radians, const glm::vec3& origin)
{
    view = glm::rotate(model, glm::radians(radians), origin);
}

void MvpComponent::setProjection(float aspectRatio)
{
    projection = glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 100.0f);
}

void MvpComponent::setModel(const glm::vec3& _model)
{
    model = glm::translate(model, _model);
}

void MvpComponent::sendToShader(unsigned int programID, const char* mvpTitle)
{
	unsigned int mvpLocationID = glGetUniformLocation(programID, mvpTitle);
	glUniformMatrix4fv(mvpLocationID, 1, GL_FALSE, glm::value_ptr(getMvpMatrix()));
}

glm::mat4 MvpComponent::getMvpMatrix() const{
    return projection * view * model;
}

glm::mat4 MvpComponent::getModel() const
{
    return model;
}
