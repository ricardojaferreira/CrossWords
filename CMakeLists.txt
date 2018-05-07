cmake_minimum_required(VERSION 3.10)
project(CrossWords)

set(CMAKE_CXX_STANDARD 11)

add_executable(CrossWords main.cpp cwplayer/Cwplayer.cpp cwplayer/Console.cpp cwplayer/Console.h cwplayer/FileManager.cpp cwplayer/FileManager.h)