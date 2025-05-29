# Exercise 6

**Update this README with your answers to the questions below.**

## Adding Third Party Libraries or Source Code to Your Project

- There is a new file `src/spdlog-hello-world-main.cc`
- It uses the spdlog and fmt libraries. 
  [More info here](https://github.com/gabime/spdlog) - Fast C++ logging 
  library with various sink types and formatting options
- How do you compile this file using the `g++` CLI?
- What do you need to change in your makefile to use this library?
- How many different ways can this library be added into your project?
- What are the tradeoffs in the different ways?
- Why are there so many different ways to do it?
  
## Static Linking vs Dynamic Linking

- What are the differences between static linking and dynamic linking?
- What are the tradeoffs?
- How do you enable static linking or dynamic linking in your makefile?

## Git Clone and Building from Source

- Where is `g++` looking for the include files and library files?
- How do you find out?

## C++ Package Managers

- Why are there so many C++ package managers?
  - As what I found information,C++ is old and messy and C++ never had an official one. Everyone had different needs embedded,Windows,Linux devs people compiling from source vs wanting binaries. So instead of one central tool like pip or npm, a bunch of different ones were formed.
- Which one is the best one?
  - I think it depends on our use case. vcpkg is popular one i think.
- Which are the most notable ways to manage the compilation of C++ projects?
  - CMake and Makefiles 