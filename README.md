# Tic-Tac-Toe C Implementationa and Testing
## CPII Assignment 1

## Description

This C project implements a simple command-line-based Tic-Tac-Toe game. It comprises several key files:

- `programMain.c`: This file contains the main function of the Tic-Tac-Toe game, which serves as the entry point for the game.

- `tictactoe.c`: The `tictactoe.c` file houses the functions and logic that power the Tic-Tac-Toe game. It contains the game's core functionality.

- `tictactoe.h`: This header file contains function declarations and data structures needed for the Tic-Tac-Toe game, allowing other parts of the program to interact with the game logic.

- `CMakeLists.txt`: The CMake configuration file is used to build the project. It defines the build targets, dependencies, and other project-specific settings.

- `testsuiteMain.c`: This file contains the test suite for the Tic-Tac-Toe game. It's responsible for running tests to ensure the correctness of the game's functions.

## Installation

To build and run the Tic-Tac-Toe game, follow these steps:

1. Clone the repository:

   ```bash
   $ git clone https://github.com/beaamoo/tictactoe-C-testing.git
   $ cd tictactoe-C-testing

2. Create a new directory, let's call it build, and navigate to it.

    ```bash
    $ mkdir build
    $ cd build

3. Compile the program and the test suite using CMake:

   ```bash
     cmake ..
     make

5. Once the compilation is successful, you can run the test suite by executing the following command:

   ```bash
   ./testsuite
   
This command will execute the testsuite executable, which contains the test cases for your program.
The test suite will run all the test cases and display the results, indicating whether each test case passed or failed.
Make sure you are in the correct directory where the testsuite executable is located before running the command.
  
  ## Using LLDB Debugger
  To use the LLDB debugger for your Tic-Tac-Toe game from the console, follow these steps:

1. Compile your code with debugging symbols enabled. Use the -g flag when compiling. For example:

    ```bash
    gcc -g -o tictactoe programMain.c tictactoe.c

2. Run lldb with your compiled program. For example:

    ```bash
    lldb tictactoe

3. Set a breakpoint at the line where player one wins. In this case, it is after the checkWin() function call. Use the breakpoint set command followed by the line number. For example:

    ```bash
    breakpoint set -f programMain.c -l 47

4. Start the execution of your program with the run command. For example:

    ```bash
    run

5. When the program hits the breakpoint, use the print command to inspect the current values of the variables. For example:

    ```bash
    frame variables

6. Continue the execution of your program with the continue command. For example:

    ```bash
    continue

You can use various LLDB commands to inspect variables, step through your code, and troubleshoot issues as needed.






