# IntroToOpenMP

### Exercises for Intro to Parallel Computing with OpenMP Workshop presented on 2/9/2022

This workshop is offered by the [National Center for Supercomputing Applications](https://www.ncsa.illinois.edu/).
Each exercise is comprised of a serial code (**/serial** folder), the OpenMP-parallelized version of it (**/solution** folder), and pseudo-code with comments/hints on how to parallelize it (**/hint#** folders). Makefiles are available for compilation with GCC. Exercises are implemented in C++ and Fortran, being identical except for the unavoidable syntax differences. In addition, there is always a **/yourwork** folder that you can use to play with the code and try out your directives. In that folder, you will find the base serial code to each exercise as a starting point (the same found in **/serial**).

## Getting a session on Expanse
During the workshop, you will be editing files, compiling code and, most importantly, **running** things. We don't want to do this in the system's login nodes (the place where you arrive to after logging in through XSEDE's SSO Hub). We want to grab a chunk of a compute node. Follow the steps below.

### Log in
1. Log in to XSEDE's SSO Hub from your local terminal:

    ```
    ssh -l <YourXSEDEUsername> login.xsede.org
    ```
2. Log in to SDSC's Expanse:


    ```
    gsissh expanse
    ```
  
You are now sitting on a login node in Expanse. 
  

### Grab a chunk of a compute node
Copy and paste the following command on your terminal to get 16 cores on a **compute** node:

```
srun --partition=shared --pty --account=nsa108 --nodes=1 --ntasks-per-node=1 --cpus-per-task=16 --mem=30G -t 02:00:00 --wait=0 --export=ALL /bin/bash
```


### Move to the project area and download the exercises source code
In addition to be using a compute node, we will also be using the **project** storage area of Expanse. Besides being the recommended place to always run your applications (**project** has faster access than **home** from the compute nodes), this will also allow members within the same project (all of us here) to read each other's files (not write to them!). Move from your **home** area to the **project** area with the command:

```
cd /expanse/lustre/projects/nsa108/<YourXSEDEUsername>
```

Now simply *git clone* this repository:

```
git clone https://github.com/babreu-ncsa/IntroToOpenMP.git
```

You should be ready to go now! If you know how to get around with *git*, you can alternatively fork this repo and clone it from your account.


## Recommended usage
The exercises present toy applications that perform a simple task, such as the calculation of a dot product betweeen two vectors. They are intended to be interactive: I really think it is important for you to try to insert your own OpenMP directives, compile and run the code before looking into the hints, and use the solution as your last resource. The way you approach this is totally flexible and you should do what you feel comfortable with. Below is my recommendation:

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
  

## Exercise 1 - Loop Scheduling
By default, when parallelize a loop without specifying the **schedule** directive, OpenMP splits the iterations evenly over the entire team of threads. This is normally efficient, since in a lot of cases the workload of each iteration is identical. However, if you know that your loop has different workloads for different iterations, other scheduling options can perform much better, since the execution time will be dominated by the thread that finishes execution last.
The general rule here is: don't speculate too much, test it!

### [saxpy](./Ex1_LoopScheduling/saxpy)
This simple code implements a common operation: **S**ingle-precision **A** x **X** **p**lus **Y**. Depending on the size of the array, different scheduling options can heve different performance as a consequence of having to access different memory addresses.


## Exercise 2 - Data Sharing
Data concurrency (or racing) and data dependency are common problems when parallelizing serial applications that make your parallelized code run different than the serial version, giving different results-- even worse, these results can change from execution to execution and, sometimes, give the right results!
The good practice here is always being explicit about each variables are shared between threads and which ones should be private, where each thread has its own copy to work on.

### [indexgame](./Ex2_DataSharing/indexgame)
This simple code takes a matrix filled with random numbers and shuffles the entries in a deterministic way, which allows you to check the consistency of your results. The transformation of indexes that is currently implemented is highly (and obviously) non-linear:

![image](https://user-images.githubusercontent.com/84105092/151406631-3784c39e-76bd-46d9-90cc-8d04d3df102c.png)


## Exercise 3 - Reduction Clauses
It is often the case where we want to gather the private results from the work on each thread into a single variable that is passed out of the parallel region. For that purpose, reduction clauses are extremely handy and highly flexible.

### [dotprod](./Ex3_Reductions/dotprod)
This implements a simple dot product between two vectors to illustrate the use of an addition-reduction clause that, without this construct, would be a little tedious to implement.

## Comments and Hints syntax
Comments that are sprinkled over the code files start with **//** for C++ and **!** for Fortran. Hints start with a **// !! HINT#** and finish with **!!** for C++, start with **! ## HINT#** and finish with **##** for Fortran. 
