cmake_minimum_required(VERSION 3.10)

include_directories(include)

add_library(diff_evo STATIC
            src/differential_evolution.cpp)

# test executable
SET(TEST_EXE "test_ex")

ADD_EXECUTABLE("${TEST_EXE}"
               src/test.cpp)

TARGET_LINK_LIBRARIES(${APP_EXE}
                      diff_evo)