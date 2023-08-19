cmake_minimum_required(VERSION 3.25)
project(homework)

set(CMAKE_CXX_STANDARD 20)

add_executable(homework main.cpp Deque.h test.cpp test.h Deque_Arr.h Deque_Arr.tpp Node.h Node.tpp Deque_LL.h Deque_LL.tpp)
