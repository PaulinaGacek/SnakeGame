cmake_minimum_required(VERSION 3.17)
project(Snake)

set(CMAKE_CXX_STANDARD 20)

add_executable(Snake main.cpp Snake.cpp Snake.h Board.cpp Board.h GameRound.cpp GameRound.h)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --lwinmm " )

target_link_libraries(${PROJECT_NAME} "winmm.lib" )