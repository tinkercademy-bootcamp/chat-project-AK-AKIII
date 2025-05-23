# Exercise 1

**Update this README with your answers to the questions below.**

## Learning How to Learn

- Answer the following questions in this file and commit and push your changes.
- Bonus sections are more difficult and optional.
- How can you find the information required to complete these tasks?
  - Books and Google for ideas  
- How can you tell if the source of your information is good?
  - I will verify them with some understanding of code and some reference on AI models 
- How would you define "good" in this situation?
  - 

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
  - We should try to keep a small no of small commits. 
- What are the most important commands to know in git?
  - Git clone, Git branch, Git add , Git Pull , Git Merge
## Introduction to Sockets

- Read the code in `src/tcp-echo-client.cc` and add a way to change the message sent using command line arguments
  - Done use int main(int argc, char* argv[])
- **Example**: `./client "hello message from the command prompt"` should send
  `"hello message from the command prompt"` to the server
- Commit your changes into git
  - Will do
- What do all these headers do?
  - argc: an int that holds the number of arguments passed. while 
   Char *argv[]: an array of strings (pointers to char) holding each argument 
- How do you find out which part of the below code comes from which header?
  - 

- How do you change the code so that you are sending messages to servers other than localhost?
  - We can  change the kServer IP address
- How do you change the code to send to a IPv6 address instead of IPv4?
  - IPv6 contains characters as well apart from numbers while IPv4 use just numbers.
- **Bonus**: How do you change the client code to connect by hostname instead of IP address?
  - Unsure
## Introduction to Memory Management

- What is happening in line 26 of `tcp-echo-client.cc`? 
  `if (inet_pton(AF_INET, kServerAddress.c_str(), &address.sin_addr) <= 0) {`
    -The code 
- What is happening in line 31 of `tcp-echo-client.cc`?
  `if (connect(my_sock, (sockaddr *)&address, sizeof(address)) < 0) {`
- What is the difference between a pointer and a reference?
  - Pointers: A pointer is a variable that holds the memory address of another variable. A pointer needs to be dereferenced with the * operator to access the memory location it points to.   
  - References: A reference variable is an alias, that is, another name for an already existing variable. A reference, like a pointer, is also implemented by storing the address of an object. 
- When is it better to use a pointer?
  - 
- When is it better to use a reference?

- What is the difference between `std::string` and a C-style string?
- What type is a C-style string?
- What happens when you iterate a pointer?
- What are the most important safety tips to know when using pointers?

## Learn Basics of Creating a C++ Project in Your IDE

- How do you compile and run your project in your IDE?

## Improving Interactions with LLMs

- What is the most authoritative source of information about `socket()`
  from `<sys/socket.h>`?
- What is the most authoritative source of information about the TCP and IP protocols?
- What is the most authoritative source of information about the C++
  programming language?
- What information can you find about using Markdown when structuring prompts 
  to LLMs?
- What is the difference between LLM and AI?
- Is it grammatically correct in English to say "a LLM" or "an LLM"? Why?
