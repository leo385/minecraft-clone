#pragma once

#include <GL/glew.h>
#include <vector>

class RenderComponent{
public:
    virtual void render(const std::vector<GLuint>& indices) = 0;
};
