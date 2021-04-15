# Nutshell

## Introduction

The Nutshell is a command interpretor which uses Lex and Yacc (Flex and Bison) to parse and scan built in and non-built in command inputs. This project was implemented by Jordan Hanson and Zack Galpern. The bulk of the code was written in nutshscanner.l (Flex) and nutshparser.y (Bison). The Nutshell was compiled in C language with gcc 9.3.0.

The features implemented by Jordan were built in commands, pipes, and I/O redirection.

The features implemented by Zack were non-built in commands, wildcard matching, and environment variable expansion.


## Features Not Implemented

- Tilde Expansion
- File Name Completion 

## Features Implemented

Features of the Nutshell include built in and non-built in commands, pipes, I/O redirection, wildcard matching, and environment variable expansion. Built in commands were programmed directly into the parser, while non-built in commands were called using the execv() Linux/UNIX function.

### Built In Commands  

| Feature       | Description |
| ------------- | ----------- |
| **setenv** *variable* *word* | Sets an environment variable *variable* equal to *word* and stores it in the shell. |
| **printenv** | Prints all of the environment variables in a list
| **unsetenv** *variable* | Removes the *word* portion of an environment *variable*. |
| **cd** *word* | Changes the current directory to be *word*. If no arguments are passed, **cd** changes the directory to the home directory. |
| **alias** *name* *word* | Sets a variable *name* equal to the value of *word*. The alias can be used in place of the *name* to execute commands as a shortcut. |
| **unalias** *name* | Deletes the alias with the value of *name*. |
| **alias** | Prints a list of all of the aliases and their values. |
| **bye** | Exits the Nutshell. |  


### Non-built In Commands

Non-built in commands include **ls**, **pwd**, **wc**, **sort**, **page**, **nm**, **cat**, **mv**, **ping**, **echo**, etc. These commands can be ran with or without arguments. 

To execute these commands, the shell searches through the current *PATH* to see if the command file already exists in the shell. If it does, then nothing happens. If the command is indeed not built in, then the execv() function is called with the PATH to the command and the command arguments.   


### Other Features

- Pipe Support

- I/O Redirection

- Environment Variable Expansion

- Wildcard Matching
