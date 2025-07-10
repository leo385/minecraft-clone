#pragma once

#include <nlohmann/json.hpp>

using json = nlohmann::json;

class IReadableJson {
public:
  virtual ~IReadableJson() = default;

  virtual json getDataFromJsonFile(const std::string &filename) const = 0;
};
