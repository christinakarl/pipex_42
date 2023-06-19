# Pipex - School 42 project (level 2)

## Theory
>The aim of this project is to imitate the pipe command in shell.
>It should work with this argument line: ./pipex file1 cmd1 cmd2 file2 and imitate the following shell command: $> < file1 cmd1 | cmd2 > file2
>
>cmd1 will be applied to the content of file1 (input 1), while in a next step the result (output 1) will be used by by cmd1 (input 2) which in the end will write its result (output 2) in file2.
>
- "<" is an input redirection: the content of file1 will be redirected to stdin
- "|" is the pipe which redirects the output of cmd1 to the input of cmd2
- ">" is an output redirection: the output of cmd2 will be reedirected to file2 instead of the default stdout

## Getting started

## Difficulties & potential for improvement

## Useful links