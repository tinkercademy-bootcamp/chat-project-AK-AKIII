# Exercise 6

**Update this README with your answers to the questions below.**

## Adding Third Party Libraries or Source Code to Your Project

- There is a new file `src/spdlog-hello-world-main.cc`
- It uses the spdlog and fmt libraries. 
  [More info here](https://github.com/gabime/spdlog) - Fast C++ logging 
  library with various sink types and formatting options
- How do you compile this file using the `g++` CLI?
  - g++ exercise-5/src/spdlog-hello-world-main.cc -o myprogram -Iexercise-5/src/spdlog/include -Lexercise-5/src/spdlog/lib -lspdlog -lfmt

- What do you need to change in your makefile to use this library?
  - We’d need to add the -I flags for the include directories and -L for the library directories. Also, will have to make sure to link the libraries themselves (-lspdlog -lfmt) updating the CXXFLAGS or LDFLAGS in the makefile.
- How many different ways can this library be added into your project?
  - Downloading the library and manually copy the files into our project.
  - Cloning the library repo somewhere and use -I and -L flags to include it.
- What are the tradeoffs in the different ways?
  - Copying files manually is simple but can get messy when the library updates
  - Cloning the repo gives us more control but we have to update it ourself.
- Why are there so many different ways to do it?
  - I think its mainly because everyone has different setups and preferences. Also, C++ doesn’t have a single “official” way to handle libraries, so people have come up with different tools.
  
## Static Linking vs Dynamic Linking

- What are the differences between static linking and dynamic linking?
  - In static linking,the library code gets copied into your executable when you compile.
  - In dynamic linking,program uses the shared library (like .so or .dll) when it runs, not when we compile. 
- What are the tradeoffs?
  - Static linking makes a bigger executable but it’s more portable since everything’s in one file.
  - Dynamic linking keeps the executable smaller, but we have to make sure the shared library is present when you run it.
- How do you enable static linking or dynamic linking in your makefile?
  - I thinking link with the static .a file for static linking or the .so/.dll for dynamic linking.
## Git Clone and Building from Source

- Where is `g++` looking for the include files and library files?
  - /usr/include and /usr/lib
- How do you find out?
  - g++ -v this command gives it.
## C++ Package Managers

- Why are there so many C++ package managers?
  - Because there’s no official package manager in C++. Everyone had different needs and tried to solve the problem in their own way.
- Which one is the best one?
  - I think it depends and when i look on online resources it suggests vcpkg and conan as most popular.
- Which are the most notable ways to manage the compilation of C++ projects?
  - Using makefiles or CMake for building projects
  - Using package managers like vcpkg or conan as i said above
  - manually compiling too.