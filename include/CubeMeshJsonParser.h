#pragma once

#include "interfaces/IReadableJson.h"
#include "types/gl_types.h"

#include <vector>

namespace {

constexpr int maxPoints = 4;
constexpr size_t maxVertices = 5;
constexpr size_t maxIndices = 6;

struct Wall {
  float pointArray[maxPoints][maxVertices];
  unsigned int indexArray[maxIndices];
};

}

class CubeMeshJsonParser final : public IReadableJson {
private:
    std::vector<Wall> vecWalls;

public:
  CubeMeshJsonParser();
  virtual ~CubeMeshJsonParser() = default;

  std::vector<gl::GLfloat> getVerticesFromVectorOfWalls() const;
  std::vector<gl::GLuint> getIndicesFromVectorOfWalls() const;

private:
  json getDataFromJsonFile(const std::string &filename) const override;

  std::vector<Wall> parseJsonToVectorOfWalls() const;
};
