//
// Created by 黃威凱 on 2023/9/3.
//
#include <catch2/catch_test_macros.hpp>
#include <random>
#include <vector>
#include "Deque.h"
#include "Deque_Arr.h"

TEST_CASE("AddFirsts", "[DequeTest]") {
    Deque<int>* deque_arr = new Deque_Arr<int>();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 100);
    std::vector<int> randomList;
    for (int i = 0; i < 100; ++i) {  // Adjust the loop count as needed
        int randomNum = distribution(gen);
        randomList.push_back(randomNum);
    }
    for (int i = 0; i < 100; i++) {
        deque_arr -> addFirst(randomList[i]);
        CHECK(deque_arr -> size() == i+1);
    }
    for (int i = 0; i < 100; i++) {
        CHECK(deque_arr -> get(i) == randomList[99-i]);
    }
}

TEST_CASE("AddLasts", "[DequeTest]") {
    Deque<int>* deque_arr = new Deque_Arr<int>();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 100);
    std::vector<int> randomList;
    for (int i = 0; i < 100; ++i) {  // Adjust the loop count as needed
        int randomNum = distribution(gen);
        randomList.push_back(randomNum);
    }
    for (int i = 0; i < 100; i++) {
        deque_arr -> addLast(randomList[i]);
        CHECK(deque_arr -> size() == i+1);
    }
    for (int i = 0; i < 100; i++) {
        CHECK(deque_arr -> get(i) == randomList[i]);
    }
}
