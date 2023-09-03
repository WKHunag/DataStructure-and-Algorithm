project(Deque)

set(HEADER_FILES
        Deque.h
        Deque_Arr.h
        Deque_LL.h
        Node.h
)

set(SOURCE_FILES
        Deque_Arr.tpp
        Deque_LL.tpp
        Node.tpp
        empty.cpp
)

add_library(Deque_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})