#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class MvpComponent {
private:
    glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;

public:
  MvpComponent() : model(glm::mat4(1.0f)), 
                   view(glm::mat4(1.0f)), 
                   projection(glm::mat4(1.0f)) { }
  
  void setMvpMatrix();

  void setViewFromCamera(const glm::vec3& source, const glm::vec3& destination, const glm::vec3& UpDirection);
  void setViewRotate(const float& radians, const glm::vec3& origin);

  void setProjection(float aspectRatio);

  void setModel(const glm::vec3 &_model);
  

  void sendToShader(unsigned int programID, const char* mvpTitle);
  
  glm::mat4 getMvpMatrix() const;
  glm::mat4 getModel() const;

};
