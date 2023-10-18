project(Heap)

set(HEADER_FILES
        PriorityQueue.h
        PriorityQueue_Heap.h
)

set(SOURCE_FILES
        PriorityQueue_Heap.tpp
        empty.cpp
)

add_library(Heap_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})