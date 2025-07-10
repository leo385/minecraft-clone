cmake_minimum_required(VERSION 3.10)

project(MinecraftClone VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()


if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)  # Pomijanie ostrzeżeń specyficznych dla MSVC
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")  # Ustaw standard
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/)    
endif()

# Libs path
set(GLFW_DIR ${CMAKE_SOURCE_DIR}/libs/glfw)
set(GLEW_DIR ${CMAKE_SOURCE_DIR}/libs/glew)
set(GLM_DIR ${CMAKE_SOURCE_DIR}/libs)
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/libs/imgui)
set(JSON_DIR ${CMAKE_SOURCE_DIR}/libs/json)

find_package(OpenGL REQUIRED)
if(OpenGL_FOUND)
    message(STATUS "OpenGL found: ${OPENGL_LIBRARIES}")
else()
    message(FATAL_ERROR "OpenGL not found")
endif()

find_package(GLEW REQUIRED)
if(GLEW_FOUND)
  message(STATUS "GLEW found: ${OPENGL_LIBRARIES}")
else()
  message(FATAL_ERROR "GLEW not found")
endif()

# Add libs to MSVC on Windows
if(MSVC)
  add_library(glfw STATIC IMPORTED)
	set_target_properties(glfw PROPERTIES
	      IMPORTED_LOCATION "${GLFW_DIR}/lib-vc2022/glfw3.lib"
		    INTERFACE_INCLUDE_DIRECTORIES "${GLFW_DIR}/include"
	)
endif()

find_package(glfw3 REQUIRED)

# Add glew
if(MSVC)
add_library(glew STATIC IMPORTED)
set_target_properties(glew PROPERTIES
  IMPORTED_LOCATION "${GLEW_DIR}/lib/Release/x64/glew32.lib"
	INTERFACE_INCLUDE_DIRECTORIES "${GLEW_DIR}/include"
)
endif()

# Add GLM both platforms Unix, Windows
add_library(glm INTERFACE)
target_include_directories(glm INTERFACE ${GLM_DIR})

# Include files
include_directories(include)
# Third-party Includes
include_directories(include/external ${GLEW_DIR}/include ${GLFW_DIR}/include ${IMGUI_DIR} ${IMGUI_DIR}/backends ${JSON_DIR}/single_include)
# Types include
include_directories(include/types)
# Abstract class / interfaces include
include_directories(include/interfaces)
# Patterns which are inline
include_directories(include/patterns)

# Add source files
file(GLOB SOURCES "src/*.cpp"

    # IMGUI SOURCE FILES
    "libs/imgui/imgui.cpp"
    "libs/imgui/imgui_draw.cpp"
    "libs/imgui/imgui_widgets.cpp"
    "libs/imgui/imgui_tables.cpp"
    "libs/imgui/backends/imgui_impl_glfw.cpp"
    "libs/imgui/backends/imgui_impl_opengl3.cpp"
)

# make program from .cpp files
add_executable(${PROJECT_NAME} ${SOURCES})

# Powiąż biblioteki z projektem
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${OPENGL_LIBRARIES}
    GLEW::GLEW
    glfw
    glm
)

# Create relative variables path to assets, shaders
add_definitions(-DASSETS_PATH="${CMAKE_SOURCE_DIR}/assets")
add_definitions(-DSHADERS_PATH="${CMAKE_SOURCE_DIR}/shader")

add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLEW)

