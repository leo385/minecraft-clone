#pragma once

#include <array>

namespace patterns::cube {

inline constexpr std::array<const char *, 5> vertexOrderPattern{"x", "y", "z",
                                                                "u", "v"};

inline constexpr std::array<const char *, 4> pointOrderPattern{
    "left-bottom-point", "right-bottom-point", "right-top-point",
    "left-top-point"};

inline constexpr std::array<const char *, 6> wallOrderPattern{
    "front-wall", "back-wall",   "left-wall",
    "right-wall", "bottom-wall", "top-wall"};

}; // namespace patterns::cube
