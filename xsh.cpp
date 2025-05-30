// Course: CS 480
// Professor Guy Leonard
// Year: 2024
// Programming Assignment #2
// Group members:
// Name: Steven Al-Sheikh
// RedID: 826493311
//  Edoras account: cssc4457
// Name: Moe Jawadi
// RedID: 130102437
// Edoras account: cssc4444

#include <iostream>
#include <sstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#include "xsh.h"
using namespace std;

// this function that we created returns a vector of char pointers after a command has been split
vector<char*> command_split(const string& command) {
    //used to parse the command entered by the user
    istringstream iss(command);
    vector<char*> args;
    string arg;

    // we use this while loop to loop through the string stream to keep adding the commands to the char vector after
    while (iss >> arg) {
        args.push_back(strdup(arg.c_str()));
    }

    // we will add null to the vector when the loop terminates
    args.push_back(NULL);
    return args;
}
// we then implement the function to run the commands with a pipe
void commands_run_with_pipe(vector<vector<char*>> commands){
    // we then declare an int variable that stores the number of commands and set it to the size of the commands vector
    int commandNumbers = commands.size();
    // we have created an array of integers to store the pipe file descriptors
    int pipefiledes[2 * commandNumbers];
    // we then created multiple for loops to check to see if the pipe is < 0
    for (int i = 0; i < commandNumbers - 1; i++) {
        if (pipe(pipefiledes + i * 2) < 0) {
            cerr << "Failed to pipe.\n";
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < commandNumbers; i++) {
        // we then fork the child process
        pid_t pid = fork();

        if (pid == -1) {
            cerr << "Failed to fork.\n";
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) {
            // we will use nested if statements to check if dup2 works
            // if dup2 is < 0 then their is an error
            if (i != 0) {
                if (dup2(pipefiledes[(i - 1) * 2], 0) < 0) {
                    cerr << "Failed to dup2.\n";
                    exit(EXIT_FAILURE);
                }
            }
            if (i != commandNumbers - 1) {
                if (dup2(pipefiledes[i * 2 + 1], 1) < 0) {
                    cerr << "Failed to dup2.\n";
                    exit(EXIT_FAILURE);
                }
            }

            //we will then close the pipe file descriptors each time we run a command
            for (int j = 0; j < 2 * commandNumbers; j++) {
                close(pipefiledes[j]);
            }
            //execute the command
            execvp(commands[i][0], &commands[i][0]);

            cerr << "Failed to exec " << commands[i][0] << ".\n";
            exit(EXIT_FAILURE);
        }
    }

    for (int j = 0; j < 2 * commandNumbers; j++) {
        close(pipefiledes[j]);
    }

    for (int i = 0; i < commandNumbers; i++) {
        wait(NULL);
    }

}
// we then finally made a function that runs the commands
void command_run(vector<char*> argv) {
    // fork the child process
    pid_t pid = fork();

    // we will then check the pid
    // if its -1 the forking has an error and it has failed
    if (pid == -1) {
        cerr << "Failed to fork.\n";
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        execvp(argv[0], &argv[0]);

        cerr << "Failed to exec " << argv[0] << ".\n";
        exit(EXIT_FAILURE);
    }
}