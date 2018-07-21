cmake_minimum_required(VERSION 3.11.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

project(SingularityBase)
add_library(SingularityBase SHARED
  src/Base/Behavior.cpp
  src/Base/Component.cpp
  src/Base/Engine.cpp
  src/Base/Entity.cpp
  src/Base/MeshRenderer.cpp
  src/Base/Object.cpp
  src/Base/Quaternion.cpp
  src/Base/Transform.cpp
  src/Base/Vector2.cpp
  src/Base/Vector3.cpp
  src/Base/Vector4.cpp
)
set_target_properties(SingularityBase PROPERTIES LINK_FLAGS "-lassimp -lstdc++fs")
set_target_properties(SingularityBase PROPERTIES DEBUG_POSTFIX "d")
set_target_properties(SingularityBase PROPERTIES PUBLIC_HEADER include/)

project(SingularityCurses)
add_library(SingularityCurses SHARED
  src/Curses/Curses3.cpp
  src/Curses/Curses.cpp
)
set_target_properties(SingularityCurses PROPERTIES LINK_FLAGS "-lncurses")
set_target_properties(SingularityCurses PROPERTIES DEBUG_POSTFIX "d")
set_target_properties(SingularityCurses PROPERTIES PUBLIC_HEADER include/)
