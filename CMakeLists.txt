cmake_minimum_required(VERSION 3.25)
project(Data_Structure_and_Algorithm C CXX)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp)

add_executable(Data_Structure_and_Algorithm ${SOURCE_FILES})

include_directories(Deque Binary\ Search\ Tree Hash\ Table Heap)
add_subdirectory(Deque)
add_subdirectory(Binary\ Search\ Tree)
add_subdirectory(Hash\ Table)
add_subdirectory(Heap)
target_link_libraries(Data_Structure_and_Algorithm Deque_lib BinarySearchTree_lib HashTable_lib Heap_lib)

add_subdirectory(Catch_tests)