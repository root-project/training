# C++ Interpreter Learning Module Exercises
Welcome to the exercises of the **C++ Interpreter** learning module!

## Compile and run a simple program
The file *simpleProgram.cpp* contains a trivial program that is waiting for you
to be compiled and run. Using the GCC compiler, you can compile and run it
putting in practice what you learned during the lecture.

## Start a ROOT session
Carry out these simple tasks:
 - Fire up ROOT
 - Verify it works as a calculator
 - List the files in /etc from within the ROOT prompt
 - Inspect the help
 - Quit

## Geometric series
Can you create a macro to execute the geometric series exercise we saw together during the lectures?
The solution can be found in the *geometricSeries.C* macro.

## Complete a simple ROOT macro
Consider the file *myMacro.C*. It is a simple ROOT macro. In this exercise, you
will fill in the code you interactively typed into the interpreter to verify the
value of the *TMath::Gaus* function.
Run the macro with ROOT in three ways:
- Directly invoking ROOT as interpreter for it
- Executing it from within the prompt
- Loading it from the prompt and then invoking the *myMacro* function

The final step consists in compiling the macro as executable with the compiler.
Add to the compiler invocation the following arguments: *`` `root-config --cflags --libs` ``*:
this is needed to expose to the compiler the details about ROOT which are needed
to link its libraries to the executable.
### Follow up question
Can you comment about the headers which need to be included in case ROOT is used
or the compiler is invoked?
