cmake_minimum_required(VERSION 3.6)
project(30862_Text_Game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Room.h Room.cpp Item.h Container.h Creature.h)
add_executable(30862_Text_Game ${SOURCE_FILES})