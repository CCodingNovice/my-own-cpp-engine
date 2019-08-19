cmake_minimum_required(VERSION 3.13)
project(engine)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/thirdparty/cmake)

set(ENGINE_SOURCES
        src/core/vector.cpp
        src/core/Engine.cpp
        src/core/Object_2d.cpp
        src/core/RigidBody.cpp
        src/core/AABB.cpp
        src/core/Physics.cpp
        src/core/Hitbox.cpp
        src/core/Player.cpp
        src/core/ScreenText.cpp
        src/core/ScreenMenu.cpp
        src/core/Audio.cpp)
set(ENGINE_HEADERS
        src/core/vector.hpp
        src/core/Engine.hpp
        src/core/Object_2d.hpp
        src/core/RigidBody.hpp
        src/core/AABB.hpp
        src/core/Physics.hpp
        src/core/Hitbox.hpp
        src/core/Player.hpp
        src/core/ScreenText.hpp
        src/core/ScreenMenu.hpp
        src/core/Audio.hpp)

add_library(my_engine_library STATIC ${ENGINE_SOURCES} ${ENGINE_HEADERS})
target_include_directories(my_engine_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})

add_executable(engine main.cpp)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_MIXER_LIBRARY} ${SDL2_TTF_LIBRARY} mingw32 SDL2main SDL2 mingw32 SDL2main SDL2 -mwindows my_engine_library)