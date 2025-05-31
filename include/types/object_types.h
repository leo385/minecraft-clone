#pragma once

#include <memory>

namespace component_types {

template <class T> using UniqueComponent = std::unique_ptr<T>;

};
