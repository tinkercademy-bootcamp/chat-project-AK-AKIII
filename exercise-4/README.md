# Exercise 4

**Update this README with your answers to the questions below.**

## Learning Multi-File C++ Projects

- Move code that can be shared between `tcp_echo_server.cc` and 
  `tcp_echo_client.cc` to separate `.h` and `.cc` files
- How would you compile from the command line?
  - g++ -o tcp_echo_server tcp_echo_server.cc tcp_common.cc
  - g++ -o tcp_echo_client tcp_echo_client.cc tcp_common.cc

- How would you compile using make?
  - I would make a makefile and then on write the command `make` on the terminal
- How would you compile using VS Code
  - I would install an extension either CodeRunner or some other depending on preferences and compile using the run button on VS Code.
### Compiling vs Linking

- What is the difference between compiling and linking in C++?
  - Compiling uses a compiler which translates source code to machine code while linker basically combines object files to executable ones.
- What is the difference between creating an executable and creating a 
  library?
  - I think creating an executable produces a stand alone runnable program, while creating a library produces reusable code to be linked by other programs.
- How do you compile a library, and then use that library to compile an
  executable?
  - I use these steps :
    - g++ -c tcp.cpp -o tcp.o 
    - 
### Reminder 
[Quickstart tutorial to make](https://makefiletutorial.com/) - Learn make 
fundamentals with practical examples and common patterns.

## Experiments in Performance

- Is it better to have many small files spread across many directories, or
  a few large files across fewer directories?
  - I believe that many small files across directories is generally better for large projects because it improves readability and maintaibility.
- Is there a difference in compilation time between the two?
  - Yes I think keeping small files spread across many directories improves time of compilation as we will ahve to compile only changed files.
- How can you assess performance other than compilation speed?
  - We can check memory usage and CPU utilization and Memory Leaks and Errors for assessing the performance other than compilation speed.