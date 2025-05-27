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
  - Unsure yet
- Where do you find the spec for the HTTP protocol?
  - IETF RFC Repository
- What about HTTPS? Is there a spec for that protocol?
  - No but we can study HTTP and TLS(security) specs and then combine them to study for HTTPS.
## Introduction to C++ and Sockets Programming

- Read the code in `src/`
  - Read
- Are there any bugs in this code? 
  -Yes, tcp_echo_client.cc have empty message bug in line 49. We can fix it in code. I will update that.
- What can you do to identify if there are bugs in the code?
  - We can use gdb debugger to identify the bugs in code

## Refactoring: Extract Function

- What is different in this code compared to exercise-1?
   - All the code is there in function and the functions are in main so it improves the readability of code.
- Is this code better or worse than exercise-1?
  -  Its better in terms of readability and we can check the bugs by expanding the functions easily.
- What are the tradeoffs compared to exercise-1?
  - The tradeoff is that the code gets a lot longer, and tracking how it runs can be a bit harder since you need to jump between multiple functions.
- Are you able to spot any mistakes or inconsistencies in the changes?
  - Not yet but am trying to spot the mistakes/inconsistencies in the chnages.
## Thinking About Performance

- Does writing code this way have any impact on performance?
  - For this kind of program, the impact on performance is usually minimal. Since the functions are small and simple, modern compilers can optimize by inlining them. Instead its just helping in organising the functions.

- What do we mean when we say performance?
  - We mean to measure the Time complexity and Space it takes to execute the program.
- How do we measure performance in a program?
  - We can measure it by checking how long the program takes to run, how much system resources it uses, and comparing it against some standard industry benchmarks for performance.

## Play with Git

- There isn't necessarily a single correct answer for how to abstract the code from exercise-1 into functions
- Try different ways to refactor the code from exercise-1 to make it more readable.
- Make sure to commit each change as small and self-contained commit
  - OKAY
- This will make it easier to revert your code if you need to
- What is `git tag`? How is `git tag` different from `git branch`?
  - A git tag points to a specific commit in our project’s history. It doesn’t change or move and just marks that exact moment in time, making it easy to look back and see exactly how our code was at that point.
  - A git branch is like a separate workspace where we can keep adding new commits as long as we fix the bugs/issues.Branches are more flexible than tag and flexible in updating the commits.
- How can you use `git tag` and `git branch` to make programming easier and more fun?
  - Tags help us label important versions or key moments in our project so we can easily go back to them.
  - Branches help us try new ideas without commiting to main so we can explore different ideas 
  - I think using both can help improve the work and would be clean for repository

## Learn Basics of Debugging in Your IDE

- How do you enable debug mode in your IDE?
  - We can enable debug mode by going to the Run tab and clicking Start Debugging. This lets us run the program with debugging enabled so we can pause. Most IDEs has debugger installed otherwise we will have to install dbg extension.
- In debug mode, how do you add a watch?
  - When the program is paused, we can find the Watch panel on the left side. We can click the + button there and type the variable name we want to watch.
- In debug mode, how do you add a breakpoint?
  - We can add a breakpoint by clicking on the left margin next to the line numbers in the editor where we want the program to stop. A red dot will appear which means the breakdown is set.
- In debug mode, how do you step through code?
  - When the program is paused at a breakpoint, we can press F10 to step over the current line (run it without going inside functions). We can press F11 to step into a function if we want to see what happens inside it.

### Memory Management and Debug Mode in Your IDE

- How do you see the memory layout of a `std::string` from your IDE debug mode?
  - Its there in Command Pallet. We would open it and search for debug and enter the memory address of std::string
- How do you see the memory layout of a struct from your IDE debug mode?
  - We can open the memory viewer at a variable’s address by hovering over it in the variables pane.
  - We can then select view memory option
  
