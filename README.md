# USU CS3100 – Operating Systems & Concurrency
All work programmed in C++ on a Raspberry Pi, and optimized to run with Raspbian. 

## Assignments:
### 1: Command Line Arguments
Implement a program that computes the Fibonacci of a specified number, estimates the value of 'e' using the specified number of iterations (of a Taylor series), or computes the value of 'pi' to the specified number of decimal places.  Please feel free to use the Internet to find resources that explain how to estimate the value of 'e' using a Taylor series and how to compute the value of  'pi' to some number of specified digits. In the case of no or invalid parameters, the program should show help instructions. 

Valid ranges for the Fibonacci [n] parameter are: 0 to 14
Valid ranges for the 'e' [n] parameter are: 1 to 30
Valid ranges for the 'pi' [n] parameter are: 1 to 10

### 2: Command Line Arguments + makefile
Working from your first assignment, split it into the following different source files:

Assign2.cpp
Assign2Fib.hpp & Assign2Fib.cpp
Assign2e.hpp & Assign2e.cpp
Assign2pi.hpp & Assign2pi.cpp

Where Assign2.cpp contains the main code that checks the command line args, calls the functions and reports the appropriate values to the console.  Then other source files contain the code that performs the different computations, Fibonacci, e estimation, and pi computation.

Write a make file that individually compiles the source files and then links them together into a single program.  Be sure to include a "clean" target in your makefile that removes all the object files and the program executable.

### 3: Shell
Write a C++ program that will act as a command line interpreter for Linux.  Use the “[cmd]:” string for your prompt. For example, when a user types a line such as…

```word1 word2 word3```

...the shell interprets 'word1' as the name of an executable program and 'word2' and 'word3' as parameters to be passed to that program in argv.  Your shell should accept any number of command line parameters.

The shell should use the directory system in the order specified by the PATH environment variable to locate the executable file (i.e. You don't have to do anything, don't send me an email asking how to do this, it automatically happens). If the file is found, the shell should pass all parameters in argv and be executed. When the executable file has completed or terminated, the shell program should again resume with the next prompt.  Your shell program must wait to display the next command prompt until the previous command has finished executing.

The shell should track the amount of time spent executing child processes.  Whenever the command 'ptime' is entered into your shell, the number of seconds, accurate to microseconds, spent executing (waiting for) child processes must be displayed.

The shell should keep a history of the previous commands entered, with no maximum hard-coded history length.  If the user enters the command 'history', the shell should provide a listing of the complete command shell history.  If the user enters the command '^ 10', for example, the 10th command in the history buffer should be executed (a 1 based index).

The command 'exit' is used to terminate your shell program, when entered, your shell program should end.

Write a makefile that builds your program, including a 'clean' target.
You must use fork, execvp, wait and std::chrono to complete this assignment.
Your shell must accept any number of parameters, if the max number of parameters is hard-coded, up to 6 points will be taken off.
Your shell must not have any global variables, up to 10 points taken off for global variables.
Your shell must not crash when the user enters bad commands or bad command arguments.

### 4: Shell + output piping
Update your command shell to provide the ability to pipe the output of one command to the input of another, using the vertical bar | as the pipe separator.  You only need to support piping between two commands.  This part of the assignment is worth 20 points.  If you enhance your shell to pipe between any number of programs, I'll award 5 bonus points that I'll add to a previous assignment on which you didn't receive full credit; you can also just do it to be cool even if you have full credit on all your assignments (and no, don't ask, I won't add those points to a quiz).

You must also correct any problems you know about and were also identified by the grader from assignment 3.  This is worth 10 points.