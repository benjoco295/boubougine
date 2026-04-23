#~ cmake_minimum_required(VERSION 3.10)
#~ project(boubougine LANGUAGES CXX)

#~ set(CMAKE_CXX_STANDARD 17)
#~ set(CMAKE_CXX_STANDARD_REQUIRED ON)

#~ find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
#~ find_package(glm REQUIRED) # optionnel si vous l'utilisez

#~ # Use GLEW for GL function loading
#~ find_package(GLEW REQUIRED)

#~ add_executable(boubougine main.cpp)

#~ target_include_directories(boubougine PRIVATE ${GLEW_INCLUDE_DIRS})
#~ target_link_libraries(boubougine PRIVATE sfml-system sfml-window sfml-graphics ${GLEW_LIBRARIES} GL)

cmake_minimum_required(VERSION 3.10)
project(mini3d_sfml LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
find_package(GLEW REQUIRED)
add_executable(mini3d
  src/main.cpp
  src/renderer.cpp
  src/shader.cpp
  src/mesh.cpp
  src/camera.cpp
)
target_include_directories(mini3d PRIVATE src ${GLEW_INCLUDE_DIRS})
target_link_libraries(mini3d PRIVATE sfml-system sfml-window sfml-graphics ${GLEW_LIBRARIES} GL)


