cmake_minimum_required(VERSION 3.27)
project(Cadillacs_and_Dinosaur_Game)

set(CMAKE_CXX_STANDARD 23)

add_executable(Cadillacs_and_Dinosaur_Game main.cpp
        Game.cpp
        Game.h
        Player.cpp
        Player.h
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR E:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(E:/SFML/include)

target_link_libraries(Cadillacs_and_Dinosaur_Game sfml-system sfml-window sfml-graphics sfml-audio)
