# Pipex - School 42 project (level 2)
The aim of this project is to imitate the pipe command in shell.
It should work with this argument line: ./pipex file1 cmd1 cmd2 file2 imitating the following shell command: $> < file1 cmd1 | cmd2 > file2

## Theory
cmd1 will be applied to the content of file1 (input 1), while in a next step the result (output 1) will be used by by cmd2 (input 2) which in the end will write its result (output 2) in file2.
- "<" is an input redirection: the content of file1 will be redirected to stdin
- "|" is the pipe which redirects the output of cmd1 to the input of cmd2
- ">" is an output redirection: the output of cmd2 will be reedirected to file2 instead of the default stdout

This project is an introduction to the fork() function which creates two sub-processes running simultaneously.

## Structure
- Parse the argv, check if input & output file exist & rights are given
- fork(), make parent process wait for child process to finish
- In both child & parent:
    - Check if cmd1 and cmd2 are accessible and split/trim according to their format, handle command errors
    - Execute the command(s)

## Difficulties & potential for improvement
- handled the cases of command given with their specific path (p.e. /bin/ls) and quote mix (p.e. "grep 'char *'")
- only handling one single pipe, which means max. 2 commands

## Useful links
1. https://42-cursus.gitbook.io/guide/rank-02/pipex
2. https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901
