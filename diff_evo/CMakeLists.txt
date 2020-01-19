cmake_minimum_required(VERSION 3.10)

include_directories(include)

add_library(diff_evo STATIC
            src/diff_evo.cpp)

# test executable
SET(TEST_EXE "de_test")

ADD_EXECUTABLE("${TEST_EXE}"
               src/test.cpp)

TARGET_LINK_LIBRARIES(${TEST_EXE}
                      diff_evo)