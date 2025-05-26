# Exercise 1

**Update this README with your answers to the questions below.**

## Learning How to Learn

- Answer the following questions in this file and commit and push your changes.
- Bonus sections are more difficult and optional.
- How can you find the information required to complete these tasks?
  - Books and Google for ideas  
- How can you tell if the source of your information is good?
  - I will verify them with official documentation manual 
- How would you define "good" in this situation?
  - Good would mean that the code is accurate, reliable, efficient and secure.

## Learn Basics of g++ CLI

- Compile the TCP client and server using `g++` from command line.
  - Done
- What are the most important command line arguments to learn for `g++`?
  - (-o,-g,-v)
- What is the difference between debug vs release versions?
  - We build the debug version for debugging and the release version for the final release distribution
- What are the tradeoffs between debug and release versions?
  - Debug generates Debug information and does not perform optimization,so its comparatively slower, while the Release version does not generate debug information but is faster
- What arguments would you use in a debug build?
  - (-g /-DEBUG is the one we use most of time)
- What about for release?
  - (-o2 & -o3 , -DNDEBUG  are release)
- What other kinds of build types are useful?
  - Test, 

## Learn Basics of Make

- Create a Makefile that will speed up the process.
  - Done
- [Quickstart tutorial to make](https://makefiletutorial.com/) - Learn make 
  fundamentals with practical examples and common patterns.
    - Done 
- How else can you learn about make?
  - AI tools and geeksforgeeks had a tutorial
- How can you tell if the resource you are using is correct?
  - Cross Verify it with the outputs at Google/other AI tool/friend
- Create a makefile such that when you run `make` with no arguments, it will:
  - Create `build/` directory if it does not exist
  - Create executables **client** and **server** in `build/`, if needed
  - How does make know when it needs to rebuild the executables?
    - By checking file timestamps
  - Change your Makefile such that `make clean` will remove `build/` and all its contents
   = DONE
- What are the most important command line arguments to learn for make?
  - (-k,-h,-i)
- What are the most important directives to learn about in Makefile?
  - targets,variables
- What are the most important commands to implement in your Makefile?
  - all,clean,run,install,test,debug
- Which ones are essential, which ones are nice to haves?
  - I think "all,clean,run" is essential while "test,debug" can be counted in nice have.
## Learn Basics of Git

- Read through the code in `src/`
- Answer any `#Questions` as a comment
- Commit and push your changes to git
- Each commit should be responding to a single task or question
  - Done
- Why is it important to keep your commit to a single task or question?
  - Its will ensure clarity, maintainability, and facilitate efficient collaboration
- Is it better to have a lot of very small commits, or one big commit when everything is working?
  - We should try to keep a small no. of small commits. 
- What are the most important commands to know in git?
  - Git clone, Git branch, Git add , Git Pull , Git Merge
## Introduction to Sockets

- Read the code in `src/tcp-echo-client.cc` and add a way to change the message sent using command line arguments
  - Done use int main(int argc, char* argv[])
- **Example**: `./client "hello message from the command prompt"` should send
  `"hello message from the command prompt"` to the server
- Commit your changes into git
  - Done
- What do all these headers do?
  - argc: an int that holds the number of arguments passed. while 
   Char *argv[]: an array of strings (pointers to char) holding each argument 
- How do you find out which part of the below code comes from which header?
  - We do Cntrl+Right click
- How do you change the code so that you are sending messages to servers other than localhost?
  - We can  change the kServer IP address
- How do you change the code to send to a IPv6 address instead of IPv4?
  - IPv6 contains characters as well apart from numbers while IPv4 use just numbers.We should replace AF_INET (IPv4) with AF_INET6 (IPv6).
- **Bonus**: How do you change the client code to connect by hostname instead of IP address?
  - Unsure
## Introduction to Memory Management

- What is happening in line 26 of `tcp-echo-client.cc`? 
  `if (inet_pton(AF_INET, kServerAddress.c_str(), &address.sin_addr) <= 0) {`
    -This line converts the server IP address from its textual form (a string like "172.31.29.2") into its binary representation required for socket operations.If it returns 0 or less, it means the IP address was invalid or conversion failed, so the program prints an error and exits.
- What is happening in line 31 of `tcp-echo-client.cc`?
  `if (connect(my_sock, (sockaddr *)&address, sizeof(address)) < 0) {`
    - This line attempts to establish a TCP connection between the socket (my_sock) and the server specified by address.
- What is the difference between a pointer and a reference?
  - Pointers: A pointer is a variable that holds the memory address of another variable. It requires the use of the * operator to access or modify the value it points to. One of the key characteristics of pointers is their fixed memory size, which depends on the system architecture: typically 4 bytes on a 32-bit system and 8 bytes on a 64-bit system, regardless of the data type they point to. 
  - References: A reference variable is an alias, that is, another name for an already existing variable. A reference, like a pointer, is also implemented by storing the address of an object.Unlike pointers, references do not require explicit dereferencing and behave syntactically like the original variable. Although references are often implemented internally using pointers (and thus usually occupy 4 bytes on a 32-bit system and 8 bytes on a 64-bit system), compilers frequently optimize them away, especially when passed as function argument .
- When is it better to use a pointer?
  - Pointers are better than references when we need features like dynamic memory allocation, the ability to reassign to different objects, or the option to represent "no object" using nullptr. They're essential in implementing data structures like linked lists and trees, performing pointer arithmetic .
- When is it better to use a reference?
  - References are better than pointers when you want to ensure that a variable always refers to a valid object and you don’t need to reassign or represent null values. They are ideal for passing large objects to functions without copying, improving performance while keeping syntax clean and safe. References are also preferred in operator overloading, function return types, and range-based loops where pointer semantics are unnecessary.
- What is the difference between `std::string` and a C-style string?
  - std::string is a C++ standard library class that manages text as a dynamic, resizable object with built-in functions for easy manipulation and automatic memory management, making it safer and more convenient to use.
  - While a C-style string is a simple array of characters terminated by a null character ('\0'), requiring manual handling of memory and string operations, which can lead to errors like buffer overflows and incorrect termination. Thus, std::string provides a higher-level, more robust way to work with strings compared to the low-level and error-prone C-style strings.
- What type is a C-style string?
  - A C-style string is of type char* or const char* (for string literals), or an array like char name.
  - It points to a sequence of characters ending in a null terminator ('\0')
- What happens when you iterate a pointer?
  - When we iterate a pointer , we move it from one memory address from another while incrementing it.
- What are the most important safety tips to know when using pointers?
  - Always Initializing Pointers
  - Always Check for NULL Before Dereferencing
  - Be Cautious with Pointer Arithmetic
  - Use smart pointers(I need to udnerstand more on it- from next lectures)

## Learn Basics of Creating a C++ Project in Your IDE

- How do you compile and run your project in your IDE?
  - I use terminal of VSCODE to compile using following commands : 
    - g++ main.cpp -o main
    - ./main
## Improving Interactions with LLMs

- What is the most authoritative source of information about `socket()`
  from `<sys/socket.h>`?
    - Official system manual : man 2 socket
- What is the most authoritative source of information about the TCP and IP protocols?
  - IETF RFC Repository (https://datatracker.ietf.org/doc/html/rfc1180#section-2)
- What is the most authoritative source of information about the C++ programming language?
  - cppreference.com , ISO C++ Standard
- What information can you find about using Markdown when structuring prompts to LLMs?
    - Markdown is a simple and powerful way to organize and format prompts, making it easier for LLMs to understand and respond accurately.
- What is the difference between LLM and AI?
  - An LLM is a specific type of AI model designed to understand and generate human language. It’s trained on massive amounts of text data while AI is AI is a broad field of computer science focused on creating systems that can perform tasks that normally require human intelligence like Computer vision,Machine learning etc
- Is it grammatically correct in English to say "a LLM" or "an LLM"? Why?
  - I belive its "an LLM" since the souund feels like "el" instead of L making it vowel kind.
