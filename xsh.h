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

#pragma once
#ifndef XSH_H_
#define XSH_H_
#include <iostream>
#include <sstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
using namespace std;

//define methods
vector<char*> command_split(const string& command);
void commands_run_with_pipe(vector<vector<char*>> commands);
void command_run(vector<char*> argv);

#endif