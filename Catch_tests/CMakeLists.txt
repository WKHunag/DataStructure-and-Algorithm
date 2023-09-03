find_package(Catch2 3 REQUIRED)
add_executable(Catch_tests_run
        Deque_tests/Deque_test.cpp Deque_tests/BinarySearchTree_test.cpp)

target_link_libraries(Catch_tests_run PRIVATE Deque_lib)
target_link_libraries(Catch_tests_run PRIVATE BinarySearchTree_lib)
target_link_libraries(Catch_tests_run PRIVATE Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(Catch_tests_run)