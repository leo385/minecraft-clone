#include "CubeMeshJsonParser.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

#include "patterns/cube/inc/cube_data_pattern.h"

namespace {

void setWallArrayValue(Wall &wall, int idPoint, int idVertex, float value) {
    wall.pointArray[idPoint][idVertex] = value;
}

void setWallArrayValue(const char* wallName, std::string wallNameToCompare, Wall& wall, const std::vector<int>& indices){
    if(std::string_view(wallName) == wallNameToCompare.c_str()){
        for(int it = 0; it < maxIndices; ++it){
                wall.indexArray[it] = indices.at(it);
        }
    }
}

}

CubeMeshJsonParser::CubeMeshJsonParser(){
    vecWalls = parseJsonToVectorOfWalls();
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

std::vector<Wall> CubeMeshJsonParser::parseJsonToVectorOfWalls() const {
    const auto data = getDataFromJsonFile(ASSETS_PATH "/cube/json/mesh.json");
    const auto meshVertices = data["Mesh"]["vertices"];
    const auto meshIndices = data["Mesh"]["indices"];

    std::vector<Wall> walls;
    Wall frontWall, backWall, leftWall, rightWall, bottomWall, topWall;

    for (const auto &wallName : patterns::cube::wallOrderPattern) {

        auto itWall = meshVertices.find(wallName);
        if (itWall == meshVertices.end())
            continue;

        const auto &wallData = itWall.value();

        int idPoint = 0;

        for (const auto &pointName : patterns::cube::pointOrderPattern) {
            auto itPoint = wallData.find(pointName);
            if (itPoint == wallData.end())
                continue;

            const auto &pointData = itPoint.value();

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

        // Fetch out indices from json file and save to raw array.
        itWall = meshIndices.find(wallName);
        auto indices = itWall->get<std::vector<int>>();

        setWallArrayValue(wallName, "front-wall", frontWall, indices);
        setWallArrayValue(wallName, "back-wall", backWall, indices);
        setWallArrayValue(wallName, "left-wall", leftWall, indices);
        setWallArrayValue(wallName, "right-wall", rightWall, indices);
        setWallArrayValue(wallName, "bottom-wall", bottomWall, indices);
        setWallArrayValue(wallName, "top-wall", topWall, indices);

    }

    walls.push_back(frontWall);
    walls.push_back(backWall);
    walls.push_back(leftWall);
    walls.push_back(rightWall);
    walls.push_back(bottomWall);
    walls.push_back(topWall);

    return walls;
}

std::vector<gl::GLuint> CubeMeshJsonParser::getIndicesFromVectorOfWalls() const {
    std::vector<gl::GLuint> indices;
    indices.reserve(vecWalls.size() * maxIndices);

    for(const auto& wall : vecWalls){
        const gl::GLuint* begin = &wall.indexArray[0];
        const gl::GLuint* end = begin + maxIndices;

        indices.insert(indices.end(), begin, end);
    }

    return indices;
}

std::vector<gl::GLfloat> CubeMeshJsonParser::getVerticesFromVectorOfWalls() const {
    std::vector<gl::GLfloat> vertices;
    vertices.reserve(vecWalls.size() * maxPoints * maxVertices);

    for(const auto& wall : vecWalls){
        const gl::GLfloat* begin = &wall.pointArray[0][0];
        const gl::GLfloat* end = begin + (maxPoints * maxVertices);

        vertices.insert(vertices.end(), begin, end);
    }
    return vertices;
}
