# XSH: Experimental Shell

## Project Overview

XSH is a simplified shell implementation that provides basic shell functionality with limited built-in commands and support for executing external programs. It supports launching programs with or without one argument, and constructing pipelines of any length using the pipe `|` operator. This project demonstrates process creation, inter-process communication via pipes, and basic shell parsing and execution logic.

---

## Features

- **Custom shell prompt:** Displays `<class_account_username>% ` (replace with the actual class account username).
- **Execution of external programs:**
  - Supports running executable files by specifying either a full path or a program name to be searched in the system PATH.
  - Supports zero or one argument passed to the executable.
  - Validates the executable before launching; prints an error message if the file is not found or not executable.
- **Pipes:**
  - Supports connecting multiple programs using pipes (e.g., `ls | sort`).
  - Any number of pipes may be chained.
  - Creates the necessary processes and pipes to facilitate inter-process communication.
- **Built-in commands:**
  - `exit` — cleanly terminates the shell.

---

## Accepted Input Formats

Only the following input formats are valid and handled by XSH:

- `executablefilename`
- `executablefilename argument` (only one argument allowed)
- `executablefilename | executablefilename`
- `executablefilename | executablefilename | executablefilename` (and longer pipe chains)
- `exit`

All other inputs are gracefully rejected with appropriate error messages.

---

## Implementation Details

- Program written in C/C++ using POSIX APIs.
- Processes are created using `fork()`, and programs are executed with appropriate `exec()` variants depending on whether the path is absolute or requires PATH searching.
- Pipes are created using `pipe()` to connect standard output of one process to the standard input of the next.
- Careful parsing of input ensures proper tokenization and command validation.
- The main function is kept minimal and serves as a controller delegating tasks to other modules/functions.
- No use of `system()` system call.

---

## Compilation and Execution

The project includes a `Makefile` that builds the executable named `xsh`.

```bash
# Navigate to the project directory
cd ~/a2

# Build the executable
make

# Run the shell
./xsh
```

---

## Project Structure

```
a2/
├── xsh.c             # Main program and shell logic
├── parser.c          # Command parsing and validation
├── executor.c        # Process creation and execution logic, including pipes
├── utils.c           # Helper functions (e.g., path checks, error messages)
├── xsh.h             # Header file with declarations
├── Makefile          # Builds executable 'xsh'
├── README.md         # Project documentation
```

---


## Example Interaction

```
cssc0000% ls
xsh.c  parser.c  executor.c  utils.c  xsh.h  Makefile  README.md

cssc0000% ls | sort
executor.c  Makefile  parser.c  README.md  utils.c  xsh.c  xsh.h

cssc0000% ./xsh
Error: File './xsh' not found or not executable.

cssc0000% exit
Exiting XSH. Goodbye!
```

---

