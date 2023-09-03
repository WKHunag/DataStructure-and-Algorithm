project(BinarySearchTree)

set(HEADER_FILES
        BinarySearchTree.h
        BST.h
        TreeNode.h
)

set(SOURCE_FILES
        BST.tpp
        TreeNode.tpp
        emtpy.cpp
)

add_library(BinarySearchTree_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})