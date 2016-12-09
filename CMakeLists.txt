cmake_minimum_required(VERSION 3.6)
project(30862_Text_Game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Room.h Room.cpp Item.h Container.h Creature.h Base.h Base.cpp Container.cpp Item.cpp Creature.cpp Trigger.h Map.h Map.cpp Trigger.cpp Condition.cpp Condition.h Border.cpp Border.h Turnon.cpp Turnon.h Attack.cpp Attack.h)
add_executable(30862_Text_Game ${SOURCE_FILES})