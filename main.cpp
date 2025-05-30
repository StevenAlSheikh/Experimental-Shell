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

    int main(){
        // we will first declare a string variable that is called nameOfUser and we will set this to xsh
        string nameOfUser = "cssc4457";

        // we then created a while loop which will allow the user to enter in commands on the terminal continuosly.
        while(true){
            cout << nameOfUser << "% ";
            // this is used to store the line of text command
            string lineText;
            getline(cin,lineText);
            // we then create a vector that stores the commands that is typed by the user
            vector<vector<char*>> commands;
            // this is used to parse the command that is entered by the user
        istringstream iss(lineText);

        string command;

        // this other while loop keeps adding the commands seperated by '|' to the vector declared 
            while(getline(iss, command, '|')){
                commands.push_back(command_split(command));
        }
        // the bottom if-else statements determine if the program continues
        if(commands.empty()){
            continue;
        }
        else if(commands[0][0] == NULL){
            continue;
        }
        else if (strcmp(commands[0][0], "exit") == 0) {
            break;
        }
        else if (commands.size() == 1) {
            command_run(commands[0]);
            // this allows for the next command to wait after the previous one has been entered.
            wait(NULL); 
            
        }
        else {
            commands_run_with_pipe(commands);
        }
        // we then made a last loop that loops through the commands vector and deallocate memory for every command that was enetered before.
        for (auto& command : commands) {
            for (auto& arg : command) {
                free(arg);
            }
        }

        }
    return 0;
    }

