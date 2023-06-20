# Pipex - School 42 project (level 2)
The aim of this project is to imitate the pipe command in shell.
It should work with this argument line: ./pipex file1 cmd1 cmd2 file2 imitating the following shell command: $> < file1 cmd1 | cmd2 > file2

## Theory
cmd1 will be applied to the content of file1 (input 1), while in a next step the result (output 1) will be used by by cmd2 (input 2) which in the end will write its result (output 2) in file2.

- "<" is an input redirection: the content of file1 will be redirected to stdin
- "|" is the pipe which redirects the output of cmd1 to the input of cmd2
- ">" is an output redirection: the output of cmd2 will be reedirected to file2 instead of the default stdout

## Getting started
- Parse the argv
- Check if file1 and file2 are accessible (access())
-
- It is necessary to create a child for each process, they will all be done at the same time while one might wait for a write end to be closed until reading from the same pipe.
- The structure will be as follows:
pipe()
 |
 |-- fork()
      |
      |-- child // cmd1
      :     |--dup2()
      :     |--close end[0]
      :     |--execve(cmd1)
      :
      |-- parent // cmd2
            |--dup2()
            |--close end[1]
            |--execve(cmd2)
(source: link 2)

// each cmd needs a stdin (input) and returns an output (to stdout)
    infile                                             outfile
as stdin for cmd1                                 as stdout for cmd2
       |                        PIPE                        ↑
       |           |---------------------------|            |
       ↓             |                       |              |
      cmd1   -->    end[1]       ↔       end[0]   -->     cmd2
                     |                       |
            cmd1   |---------------------------|  end[0]
           output                             reads end[1]
         is written                          and sends cmd1
          to end[1]                          output to cmd2
       (end[1] becomes                      (end[0] becomes
        cmd1 stdout)                           cmd2 stdin)
(source: link 2)

-
## Difficulties & potential for improvement

## Useful links
1. https://42-cursus.gitbook.io/guide/rank-02/pipex
2. https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901
