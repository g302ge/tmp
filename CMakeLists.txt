cmake_minimum_required(VERSION 3.10)

project(TemplateMetaProgramming)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# import the googletest into this project
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# TODO: define a new macro to generate the tests 

# Max template test 
add_executable(
  max_test
  src/max.cc
)
target_link_libraries(
  max_test
  GTest::gtest_main
)

# quicksort 
add_executable(
  quicksort_test
  src/quicksort.cc
)
target_link_libraries(
  quicksort_test
  GTest::gtest_main
  GTest::gmock
)

# count_if
add_executable(
  count_if_test
  src/count_if.cc
)
target_link_libraries(
  count_if_test
  GTest::gtest_main
  GTest::gmock
)





