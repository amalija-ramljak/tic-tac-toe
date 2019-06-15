cmake_minimum_required(VERSION 3.9)
project(tictactoe)

set(CMAKE_CXX_STANDARD 14)

add_executable(tictactoe main.cpp TicTacToeGrid.cpp TicTacToeGrid.h)