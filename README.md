# Operating-Systems-PA2
This assignment was locked Jun 14, 2024 at 11:45pm.
This page last modified 30 May, 2024

You shall implement an Experimental Shell, “XSH”.  XSH shall provide the following functions:

Provide a shell-like interface for launching new programs:  When XSH starts running, it will print a prompt "cssc0000% " (replace cssc0000 with your class account username) and then wait for the user to type in a file name. Note, XSH will only have two shell built-in functions (shell builtin functions typically include cd, setenv, printenv, bg, fg, etc) which is described in the following items.
All shells are able to start/run new programs.  When XSH is running, if the user enters a filename and hits the “enter” key, XSH then reads the filename entered and determines if the file is an executable file. If it isn't, XSH will print a useful error message to the user and then return to #1 above (display a new prompt and wait for user input). If it is an executable file, then XSH will create a new process and run this program in the new process.  -- Note,  you will need to determine whether the filename is a fully qualified path name or if the file needs to be searched for (fully qualified pathnames begin with a slash (i.e. "/"), use the correct variant of ‘exec’ to do this.
XSH will provide a builtin function, pipe, to allow users to create two processes with a pipe for the two processes to use to communicate with each other. For example, the following is legal input:
               "cssc0000% ls | sort"  (output of ls is sent to the input of sort)

In this example, XSH will create two processes and a pipe for them to use for communication between the two processes.  In this example, the first process (ls program) would send its output to the second process (sort program) which would read from the pipe.

The second builtin function is exit.  If the user types "exit" (then hits the “enter” key), your program shall gracefully close itself down and terminate.
NOTE - The ONLY valid input formats are the following (gracefully reject/don't accept all others):

xsh% executablefilename
xsh% executablefilename argument <- (only one argument, no more than one)
xsh% executablefilename | executablefilename
xsh% executablefilename | executablefilename | executablefilename <- (any number of pipes may be constructed on the command line)
xsh% exit
Your program will be tested by compiling it and executing it on edoras using these features and some bad input.

Your program shall be written such that it compiles and executes cleanly when using the gcc/g++ compiler on edoras.  You shall create a sub-directory named "a2" in your home directory. In a2, you shall place your source files (multiple source files are required), your header file, your Makefile, and a README file (follow instructions from assignment #1 for the README file).  Additionally, identify in your README file who worked on which lines of code in this project (if you used Agile/Pair programming state who was writing and who was providing input for each function/method).  Your source files SHALL CONTAIN sufficient comments for making the source easy to read. Points will be taken off for poorly (or non) commented source. Your main() should be a small function (it should look like a "table of contents" for your program).  Name the executable "dsh".

Create ~/a2 by hand.
Create multiple c/c++ source files, an include file, a Makefile, and a README file. Put them into ~/a2.
The Makefile shall create an executable by the name of xsh in the same directory (~/a2).
The system call "system()" will NOT be allowed
TURNING IN YOUR WORK (only one of you turns in the project!  Put both of your names and usernames in all files!):

Make sure that all of your files (all source files, Makefile, README file, test files, etc) are in the a2 sub- directory of the class account
