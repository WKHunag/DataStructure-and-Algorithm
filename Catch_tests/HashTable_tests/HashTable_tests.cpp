//
// Created by 黃威凱 on 2023/9/27.
//
#include <catch2/catch_test_macros.hpp>
#include <random>
#include <vector>
#include "HashTable_Chaining.h"

TEST_CASE("Insertion", "[HashTableTest]") {
    HashTable<int, int>* dict = new HashTable_Chaining<int, int>();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 100);
    std::vector<int> randomList;
    for (int i = 0; i < 100; ++i) {  // Adjust the loop count as needed
        int randomNum = distribution(gen);
        randomList.push_back(randomNum);
    }
    for (int i = 0; i < 100; i++) {
        dict -> insertion(i, randomList[i]);
        CHECK(dict -> size() == i+1);
    }
    for (int i = 0; i < 100; i++) {
        CHECK(dict -> get(i) == randomList[i]);
    }
}