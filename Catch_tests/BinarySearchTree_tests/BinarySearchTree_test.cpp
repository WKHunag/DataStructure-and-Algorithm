//
// Created by 黃威凱 on 2023/9/3.
//
#include <catch2/catch_test_macros.hpp>
#include <random>
#include <vector>
#include <cstdlib>
#include "BinarySearchTree.h"
#include "BST.h"

//TEST_CASE("Access elements", "[BSTTest]") {
//    BinarySearchTree<int>* bst = new BST<int>();
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<int> distribution(1, 100);
//    std::vector<int> randomList;
//    for (int i = 0; i < 100; ++i) {  // Adjust the loop count as needed
//        int randomNum = distribution(gen);
//        randomList.push_back(randomNum);
//    }
//
//    for (int i = 0; i < 100; i++) {
//        bst -> insertion(randomList[i]);
//        CHECK(bst -> size() == i+1);
//    }
//
//    for (int i = 0; i < 10; i++) {
//        CHECK(bst -> search(randomList[i]) == true);
//    }
//
//    for (int i = 0; i < 10; i++) {
//        CHECK();
//
//        CHECK(bst -> search(randomList[i]) == true);
//    }
//}

