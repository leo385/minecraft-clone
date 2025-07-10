#pragma once

#include "interfaces/IReadableJson.h"

#include <vector>

constexpr int maxPoints = 4;
constexpr size_t maxVertices = 5;

struct Wall {
  float pointArray[maxPoints][maxVertices];
};

class CubeMeshJsonParser final : public IReadableJson {
private:
  std::vector<Wall> walls;

public:
  CubeMeshJsonParser();
  virtual ~CubeMeshJsonParser() = default;

private:
  void parseJsonToVector();

  json getDataFromJsonFile(const std::string &filename) const override;
  std::vector<Wall> deriveWalls() const;
};
