# base-ProfilingExercise
This is a first exercise in using the ```gprof``` tool to profile the
execution of a program.  Profiling a program using ```gprof```
involves compiling the code with the ```-pg``` option to embed
instrumentation code in the executable file.  When the instrumented executable is run data is written to a file (```gmon.out```).  The ```gprof``` tool uses this data to display information about how much time was spent in each function.

Unless you have ```gprof``` installed on your local machine already, you should work on this exercise on ```timberlake.cse.buffalo.edu```.

Here are some useful resources for you:
1. [the ```gprof``` manual](https://sourceware.org/binutils/docs/gprof/index.html#Top)
2. [tutorial](https://www.thegeekstuff.com/2012/08/gprof-tutorial)

I recommend you read through the (short) tutorial briefly on your own, then try using ```gprof``` on the included code to explore the difference in runtime between two functions which compute letter-counts on a given text file.  The two functions are called ```letterCounts``` and ```letterCountsSlow```.  The given tests just use one data file, but you can try all the given data files.  One of them is significantly longer than the others.

The primary goals of this exercise is for you to become familiar with how to compile for ```gprof```use, how to run ```gprof```, and how to interpret ```gprof``` output to get insight into program performance.

Have fun!
