#pragma once

#include "interfaces/IReadableJson.h"
#include "types/gl_types.h"

#include <vector>

namespace {

constexpr int maxPoints = 4;
constexpr size_t maxVertices = 5;

struct Wall {
  float pointArray[maxPoints][maxVertices];
};

}

class CubeMeshJsonParser final : public IReadableJson {
public:
  CubeMeshJsonParser() = default;
  virtual ~CubeMeshJsonParser() = default;

  std::vector<gl::GLfloat> getVerticesFromVectorOfWalls() const;

private:
  json getDataFromJsonFile(const std::string &filename) const override;

  std::vector<Wall> parseJsonToVectorOfWalls() const;
};
