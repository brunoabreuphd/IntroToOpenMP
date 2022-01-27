# IntroToOpenMP

### Exercises for Intro to Parallel Computing with OpenMP Workshop presented on 2/9/2022

This workshop is offered by the [National Center for Supercomputing Applications](https://www.ncsa.illinois.edu/).
Each exercise is comprised of a serial code (**/serial** folder), the OpenMP-parallelized version of it (**/solution** folder), and pseudo-code with comments/hints on how to parallelize it (**/hint#** folders). Makefiles are available for compilation with GCC. Exercises are implemented in C++ and Fortran, being identical except for the unavoidable syntax differences. In addition, there is always a **/yourwork** folder that you can use to play with the code and try out your directives. In that folder, you will find the base serial code to each exercise as a starting point (the same found in **/serial**).

## Recommended usage
The exercises present toy applications that perform a simple task, such as the calculation of a dot production betweeen two vectors. They are intended to be interactive: I really think it is important for you to try to insert your own OpenMP directives, compile and run the code before looking into the hints, and use the solution as your last resource. The way you approach this is totally flexible and you should do what you feel comfortable with. Below is my recommendation:

1. Take a look at the serial code and make sure you understand what it is doing. I inserted many comments that you may find useful.
2. Try to identify the portions of the code that could benefit from parallelism. You may be able to go much beyond what I've done, so don't be shy.
3. Use the **/yourwork** area to write your parallelized version. 
4. If you find it hard to make progress, take a look at the pseudo code in the **/hint#** folders. These are progressive hints, so start with 1, try to implement it, make sure it compiles and works as you would expect, then move on to 2, 3 and so on.
5. Once you are done and are sure your code behaves as expected, check out one possible solution that I implemented in the **/solution** folder. You can also use this a last resource after you exhaust your attempts to parallelize the code.
6. Have a different solution? I want to know about it! Open a GitHub issue here and describe it! I will be happy to add that to this repo.

### yourwork space
If you are working on this from a remote server, I recommend cloning the entire repo and then using the **/yourwork** folders to work on the exercises. You can have that file open in your terminal using a text editor (vi, nano, emacs) and, if you want to check on the hints (or the solution), you can use your browser and look at the files on GitHub, as opposed to have yet another ssh session running (or even worse, having to close and open files every time).

### Makefile
The workspace has a **Makefile** that takes the source code, which is named *ExerciseName_yourwork.<cpp/f90>* and compiles it into an executable *ExerciseName_yourwork.exe* (you will also get an object file that can be ignored). This Makefile already includes the OpenMP flags for GCC.
  

## Exercise 1 - Data Sharing 


