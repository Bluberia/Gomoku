cmake_minimum_required (VERSION 3.8)
project (pbrain-gomoku-ai)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SRCS src/*.cpp src/*.hpp src/*.h)
add_executable(pbrain-gomoku-ai ${SRCS})

