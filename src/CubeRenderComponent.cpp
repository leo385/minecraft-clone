#include "CubeRenderComponent.h"

void CubeRenderComponent::render(const std::vector<GLuint>& indices){
    
    glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
}

