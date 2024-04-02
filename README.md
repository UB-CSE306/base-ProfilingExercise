# base-ProfilingExercise

This is a first exercise in using the ```gprof``` tool to profile the
execution of a program.  Profiling a program using ```gprof```
involves compiling the code with additional flags to embed
instrumentation code in the executable file.  Look at the included
`Makefile` and referenced documentation for details.

When the instrumented executable is run data is written to a file
(```gmon.out```).  The ```gprof``` tool uses this data to display
information about how much time was spent in each function.

Unless you have ```gprof``` installed on your local machine already,
you should work on this exercise on ```cerf.cse.buffalo.edu``` (or its
twin, ```turing.cse.buffalo.edu```).

Here are some useful resources for you:
1. [the ```gprof``` manual](https://sourceware.org/binutils/docs/gprof/index.html#Top)
2. [tutorial](https://www.thegeekstuff.com/2012/08/gprof-tutorial)

I recommend you read through the (short) tutorial briefly on your own,
then try using ```gprof``` on the included code and data to explore
the difference in runtime between three given functions,
```letterCounts```, ```letterCountsSlow```, and
```letterCountsGlacial```.  Each of these functions computes letter
counts on a text file in a different way.

The primary goals of this exercise is for you to become familiar with
how to compile for ```gprof```use, how to run ```gprof```, and how to
interpret ```gprof``` output to get insight into program performance.

Have fun!
