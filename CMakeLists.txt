cmake_minimum_required(VERSION 3.14)
project(count-min-sketch)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b10fad38c4026a29ea6561ab15fc4818170d1c10.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add the include folder to the project
include_directories(include)

# Create a library from your source files in the src folder
add_library(count_min_sketch_lib
  src/hash_family.cpp
  src/ivy_cms.cpp
  src/MurmurHash3.cpp
)

# Create an executable for the tests
add_executable(ivy_cms_test
  test/ivy_cms_test.cpp
)

# Link the executable with the GoogleTest libraries and your project library
target_link_libraries(ivy_cms_test
  GTest::gtest_main
  count_min_sketch_lib
)

include(GoogleTest)
gtest_discover_tests(ivy_cms_test)