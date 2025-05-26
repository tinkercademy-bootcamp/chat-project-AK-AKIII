# Exercise 2

**Update this README with your answers to the questions below.**

## Sources of Information for Questions from Before

### Socket 
- https://man7.org/linux/man-pages/man2/socket.2.html - System call reference
  for creating communication endpoints
- Or type `man socket` in terminal
- https://man7.org/linux/man-pages/man7/socket.7.html - Socket interface 
  overview and protocol families
- Or type `man 7 socket` in terminal
  - Checked
- When would you want to use a `SOCK_RAW` stream?
  - We'd use SOCK_RAW when we want to send all the data in a specialized way like, not just the payload but also our own headers. Its used when we're making our own protocol that doesn’t use TCP/UDP.
### TCP and IP Protocols
- [IPv4](https://www.rfc-editor.org/info/rfc791) - Internet Protocol specification defining packet structure and routing
- [IPv6](https://www.rfc-editor.org/info/rfc8200) - Next-generation Internet 
  Protocol with expanded address space
- [TCP](https://datatracker.ietf.org/doc/html/rfc9293) - Transmission Control 
  Protocol providing reliable, ordered data delivery
    
### C++
- [C++23 ISO standard draft](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2023/n4950.pdf) - 
  Working draft of the C++ language specification
- Is the above the official C++23 spec? 
  - No, this is just a working draft. Final draft is after the aopprovals.N4950(Linked above) is the latest working draft issued by the WG21 committee (the ISO working group for C++) as of early 2023.
- Where is the official C++23 spec?
  - The official C++23 standard is published by the ISO (International Organization for Standardization) as a formal document available on the ISO website.
- Why was this link chosen instead?
  - The N4950 draft is the most up-to-date freely available working draft from the WG21 commit.This is publicly available and accessible while final official draft is generally not free. Also it represents the current state of the standard before final publication.
- Is this a helpful reference for learning C++?
  - Yes,This would be helpful if we want to look for exact language sematics and new features.
- Can the various implementations of C++ compilers be different from the C++ standard?
  - Yes various implementations of C++ Compilers can be different from the c++ standard for eg. 
    - The C++ standard specifies minimum ranges for types like int, long, etc., but the exact size can differ.
    - Signed integer overflow,different compilers might wrap differently
- What are the most widely used and most significant C++ compilers?
  - GCC(G++)
  - CLANG(LLVM)
  - Microsoft Visual C++ Compiler
  - Intel ICC Compiler
- Where is the equivalent spec for C++26?

- Where do you find the spec for the HTTP protocol?
  - IETF RFC Repository
- What about HTTPS? Is there a spec for that protocol?
  - No but we can study HTTP and TLS(security) specs and then combine them to study for HTTPS.
## Introduction to C++ and Sockets Programming

- Read the code in `src/`
  - Read
- Are there any bugs in this code? 
- What can you do to identify if there are bugs in the code?

## Refactoring: Extract Function

- What is different in this code compared to exercise-1?
- Is this code better or worse than exercise-1?
- What are the tradeoffs compared to exercise-1?
- Are you able to spot any mistakes or inconsistencies in the changes?
  
## Thinking About Performance

- Does writing code this way have any impact on performance?
- What do we mean when we say performance?
- How do we measure performance in a program?

## Play with Git

- There isn't necessarily a single correct answer for how to abstract the code from exercise-1 into functions
- Try different ways to refactor the code from exercise-1 to make it more readable.
- Make sure to commit each change as small and self-contained commit
- This will make it easier to revert your code if you need to
- What is `git tag`? How is `git tag` different from `git branch`?
- How can you use `git tag` and `git branch` to make programming easier and
  more fun?

## Learn Basics of Debugging in Your IDE

- How do you enable debug mode in your IDE?
- In debug mode, how do you add a watch?
- In debug mode, how do you add a breakpoint?
- In debug mode, how do you step through code?

### Memory Management and Debug Mode in Your IDE

- How do you see the memory layout of a `std::string` from your IDE debug mode?
- How do you see the memory layout of a struct from your IDE debug mode?
