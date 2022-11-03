#Require CMAKE version
cmake_minimum_required(VERSION 2.8)

# Set the name of the project and target:
SET(TARGET "HomologyThicker")

#Grab all source, header files
FILE(GLOB_RECURSE TARGET_SRC  "source/*.cc")
FILE(GLOB_RECURSE TARGET_INC  "include/*.h")
FILE(GLOB_RECURSE TARGET_TEST  "test/*.cc")
SET(  TARGET_SRC ${TARGET_SRC} ${TARGET_INC} ${TARGET_TEST} )

# Define the executable target:
PROJECT(${TARGET})

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )

# # For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)

# enable_testing()

# add_executable(
#   test/test_main
#   test/test_main.cc
# )
# target_link_libraries(
#   test_main
#   GTest::gtest_main
# )

# include(GoogleTest)
# gtest_discover_tests(hello_test)