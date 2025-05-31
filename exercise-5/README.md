# Exercise 5

**Update this README with your answers to the questions below.**

## Comparing File Changes

- What's an easy way to identify the changes in source code from one exercise
  to another?
  - We can use the git command for ex if we want to check changes in 2 different branches tcp server exercise_4 and exercise_5 source code : git diff exercise_4 exercise_5 -- src/tcp_echo_server.cc

## Using Classes

- Here is one way to separate out the code into multiple files
- Is this the best way to do it? 
  - I don't this might be the best way to do. Likely making separate class for client and server would be good.
- What are the advantages and disadvantages?
  - The advantage is that the code is split up so it’s easier to understand. For example, utils.h has all the helper functions that any file can use, server-main starts the server, server-client starts the client, and the net folder has chat-sockets.cc and .h for making the sockets. I didn’t really see any big disadvantages to doing it this way.
## Introduction to Namespace

- There are different ways namespace is being used in this exercise
- Which way is better? What are the advantages and disadvantages?
  - Some ways I saw were: writing the whole namespace before the function, using using namespace, or giving the namespace a shorter alias like changing tt::chat to ttc.
  - If we write the whole namespace, it’s very clear but also gets really long. Using using namespace is fine for small bits of code but might create name conflicts in bigger programs. Aliasing it to a shorter name seems like clearer and easier to type.

## Abstracting Code into Classes

- Abstract the client and server logic into a `Client` and `Server` class
- **Note**: You don't have to use the code in this exercise as a starting point
- You can use the code you wrote from previous exercises instead
- How should you divide the code into files?
  - I think it’d be good to make separate header files for the Client and Server classes to hold the class declarations.
- What namespace and directory structure should you use? Why?
  - I’d probably use a tt::chat::client namespace for the client, kind of like what we did for the server. It’d also make sense to put the client and server code in their own folders along with their headers. 

## Programming Sense of Taste

- How do you judge what makes a particular choice of namespace and directory
  structure? 
  - I think it depends on how easy it is to find and understand the code later. If the namespaces are too long or confusing, it’s harder to read.
- How do you judge what makes a good naming convention or programming style?
  - I’d say a good naming convention is when the names actually tell us what the thing does. If the names are too short or weird, we spend time guessing.
## "Senses" in Programming

- Have you ever heard of programmers referring to "code smells"? How can code
  smell?
  - It just mean that there is code plagiarism or some dependency on other codes
- What does it mean to have a sense of taste in programming? How can code
  taste?
  - It just means how well the code can be written in terms of readability,complexity and clean
- Is there an analogue for every sense?
  - Maybe not sure
- What other code senses can you think of?
  - Similar to our 5 senses,maybe sense of sight means how easy we can figure out the functions and bug of code 
- How many senses do humans have?
  - 5 senses
- When would you want to see something before you touch it?
  - If its not supposed to be touched like  hot substance etc
- When would you want to touch something before you see it?
  - If I can't happen to see it like dark room etc