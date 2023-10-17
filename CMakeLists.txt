cmake_minimum_required(VERSION 3.25)
project(tictactoe C)

set(CMAKE_C_STANDARD 11)

# Add the include directories for CUnit
include_directories(/usr/local/include/CUnit/CUnit.h)

# Add the executable for your main program
add_executable(tictactoe programMain.c tictactoe.c tictactoe.h)

# Add the executable for your test suite
add_executable(testsuite testsuiteMain.c tictactoe.c tictactoe.h)

# Link the necessary libraries for CUnit
target_link_libraries(testsuite /usr/local/lib/libcunit.a)

# Add a custom target to run the test suite
add_custom_target(run_tests COMMAND testsuite)
