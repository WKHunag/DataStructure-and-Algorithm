project(HashTable)

set(HEADER_FILES
        HashTable.h
        HashTable_Chaining.h
)

set(SOURCE_FILES
        HashTable_Chaining.tpp
        empty.cpp
)

add_library(HashTable_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})