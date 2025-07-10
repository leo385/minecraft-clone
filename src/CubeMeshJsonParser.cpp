#include "CubeMeshJsonParser.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

#include "patterns/cube/inc/cube_data_pattern.h"

void setWallArrayValue(Wall &wall, int idPoint, int idVertex, float value);

CubeMeshJsonParser::CubeMeshJsonParser() { parseJsonToVector(); }

void CubeMeshJsonParser::parseJsonToVector() {
  const auto data = getDataFromJsonFile(ASSETS_PATH "/cube/json/mesh.json");
  const auto meshVertices = data["Mesh"]["vertices"];

  Wall frontWall, backWall, leftWall, rightWall, bottomWall, topWall;

  for (const auto &wallName : patterns::cube::wallOrderPattern) {

    auto itWall = meshVertices.find(wallName);
    if (itWall == meshVertices.end())
      continue;

    const auto &wallData = itWall.value();

    // std::cout << wallName << ": " << "\n";

    int idPoint = 0;

    for (const auto &pointName : patterns::cube::pointOrderPattern) {
      auto itPoint = wallData.find(pointName);
      if (itPoint == wallData.end())
        continue;

      const auto &pointData = itPoint.value();

      // std::cout << pointName << ": ";

      int idVertex = 0;

      for (const auto &coordKey : patterns::cube::vertexOrderPattern) {
        auto itCoord = pointData.find(coordKey);
        if (itCoord != pointData.end()) {
          if (std::string_view(wallName) == "front-wall") {
            setWallArrayValue(frontWall, idPoint, idVertex,
                              itCoord.value().get<float>());
            idVertex++;
          }
          if (std::string_view(wallName) == "back-wall") {
            setWallArrayValue(backWall, idPoint, idVertex,
                              itCoord.value().get<float>());
            idVertex++;
          }
          if (std::string_view(wallName) == "left-wall") {
            setWallArrayValue(leftWall, idPoint, idVertex,
                              itCoord.value().get<float>());
            idVertex++;
          }
          if (std::string_view(wallName) == "right-wall") {
            setWallArrayValue(rightWall, idPoint, idVertex,
                              itCoord.value().get<float>());
            idVertex++;
          }
          if (std::string_view(wallName) == "bottom-wall") {
            setWallArrayValue(bottomWall, idPoint, idVertex,
                              itCoord.value().get<float>());
            idVertex++;
          }
          if (std::string_view(wallName) == "top-wall") {
            setWallArrayValue(topWall, idPoint, idVertex,
                              itCoord.value().get<float>());
            idVertex++;
          }
        }
      }
      idPoint++;
    }
  }

  walls.push_back(frontWall);
  walls.push_back(backWall);
  walls.push_back(leftWall);
  walls.push_back(rightWall);
  walls.push_back(bottomWall);
}

void setWallArrayValue(Wall &wall, int idPoint, int idVertex, float value) {
  wall.pointArray[idPoint][idVertex] = value;
}

json CubeMeshJsonParser::getDataFromJsonFile(
    const std::string &filename) const {
  std::ifstream file{filename};
  if (!file.is_open()) {
    std::cerr << "Not found JSON file: " << filename << "\n";
    return EXIT_FAILURE;
  }

  json data;
  file >> data;
  return data;
}

std::vector<Wall> CubeMeshJsonParser::deriveWalls() const { return walls; }
