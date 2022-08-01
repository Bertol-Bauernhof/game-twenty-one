cmake_minimum_required(VERSION 3.22)
project(GameTwentyOne)

set(CMAKE_CXX_STANDARD 14)

add_executable(GameTwentyOne main.cpp LayoutGUI.cpp cmake-build-debug/LayoutGUI.h Service.cpp cmake-build-debug/Service.h Combination.cpp cmake-build-debug/Combination.h)
