cmake_minimum_required(VERSION 3.11.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

project(singularity)
add_library(singularity SHARED
  src/Behavior.cpp
  src/Component.cpp
  src/Curses3.cpp
  src/Curses.cpp
  src/Engine.cpp
  src/Entity.cpp
  src/Object.cpp
  src/Quaternion.cpp
  src/Transform.cpp
  src/Vector2.cpp
  src/Vector3.cpp
  src/Vector4.cpp
)
set_target_properties(singularity PROPERTIES DEBUG_POSTFIX "d")
set_target_properties(singularity PROPERTIES PUBLIC_HEADER include/)
