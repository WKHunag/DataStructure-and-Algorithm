if(EXISTS "/Users/kai/CLionProjects/homework/cmake-build-debug/Catch_tests/Catch_tests_run_tests-b12d07c.cmake")
  include("/Users/kai/CLionProjects/homework/cmake-build-debug/Catch_tests/Catch_tests_run_tests-b12d07c.cmake")
else()
  add_test(Catch_tests_run_NOT_BUILT-b12d07c Catch_tests_run_NOT_BUILT-b12d07c)
endif()
