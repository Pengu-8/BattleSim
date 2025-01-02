cmake_minimum_required(VERSION 3.29)
project(BattleSim)

set(CMAKE_CXX_STANDARD 20)

add_executable(BattleSim main.cpp
        menu.h
        menu.cpp
        game.h
        game.cpp
        herodule.h
        herodule.cpp
)