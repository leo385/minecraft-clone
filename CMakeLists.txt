cmake_minimum_required(VERSION 3.10)

# Ustaw nazwę projektu i jego wersję
project(MinecraftClone VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#set(CMAKE_C_COMPILER clang)
#set(CMAKE_CXX_COMPILER clang++)

# Flagi dla clanga
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


# Find opengl WIN
find_package(OpenGL REQUIRED)

# Wypisanie statusu OpenGL
if(OpenGL_FOUND)
    message(STATUS "OpenGL found: ${OPENGL_LIBRARIES}")
else()
    message(FATAL_ERROR "OpenGL not found")
endif()

# Add glfw

add_library(glfw STATIC IMPORTED)

if(MSVC)
	set_target_properties(glfw PROPERTIES
	      IMPORTED_LOCATION "${GLFW_DIR}/lib-vc2022/glfw3.lib"
		    INTERFACE_INCLUDE_DIRECTORIES "${GLFW_DIR}/include"
	)
else()
	set_target_properties(glfw PROPERTIES
	IMPORTED_LOCATION "${GLFW_DIR}/lib-mingw-w64/libglfw3.a"
		    INTERFACE_INCLUDE_DIRECTORIES "${GLFW_DIR}/include"
	)
endif()


# Add glew
add_library(glew STATIC IMPORTED)
set_target_properties(glew PROPERTIES
  IMPORTED_LOCATION "${GLEW_DIR}/lib/Release/x64/glew32.lib"
	INTERFACE_INCLUDE_DIRECTORIES "${GLEW_DIR}/include"
)

# Add GLM
add_library(glm INTERFACE)
target_include_directories(glm INTERFACE ${GLM_DIR})

# Include files
include_directories(include ${GLEW_DIR}/include ${GLFW_DIR}/include)

# Zdefiniuj pliki źródłowe
file(GLOB SOURCES "src/*.cpp")

# Tworzenie wykonywalnego pliku
add_executable(${PROJECT_NAME} ${SOURCES})

# Powiąż biblioteki z projektem

target_link_libraries(${PROJECT_NAME} PRIVATE 
    glew
    glfw
    ${OPENGL_LIBRARIES} 
    glm
)

# Create relative variables path to assets, shaders
add_definitions(-DASSETS_PATH="${CMAKE_SOURCE_DIR}/assets")
add_definitions(-DSHADERS_PATH="${CMAKE_SOURCE_DIR}/shader")

