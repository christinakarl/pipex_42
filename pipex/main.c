/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:38:36 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/19 17:28:26 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//check access rights for cmd1 and cmd2
// int	check_access(char *input, char *output)
// {
// 	if (access())
// }

//print error text & return to main
int	error(char *str)
{
	perror(str);
	return (-1);
}

//child process: dup2 stdin & stdout, close reading end[0] which will be used by parent, execve (envp[2])
void	child_process(int in, char **argv, int end[2], char **envp)
{
	char	**cmd1;

	cmd1 = ft_split(argv[2], ' ');
	dup2(in, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(in);
	close(end[0]);

	//execve: check if commands exist first

}

//parent process: dup2 stdin & stdout, close writing end[1] which was used by child, execve (envp[2])
void	parent_process(int out, char **argv, int end[2], char **envp)
{
	char	**cmd2;
	int		status;

	cmd2 = ft_split(argv[4], ' ');
	waitpid(0, &status, 0);
	dup2(end[0], STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(out);
	close(end[1]);

	//execve: check if commands exist first, then cut the PATH= part, then ft_split(envp, ':') >>maybe better to do this in the main
}

//pipex function creating pipe, fork, child, parent
void	pipex(int in, int out, char **argv, char **envp)
{
	int		end[2];
	pid_t	process;
	(void)	envp;

	pipe(end);
	process = fork();
	if (process < 0)
		return (perror("Fork"));
	if (process == 0)
		child_process(in, argv, end);
	else
		parent_process(out, argv, end);


}

//envp = environmental path, all possible paths for shell commands
int main(int argc, char **argv, char **envp)
{
//1. open both input and output file (argv[1] & argv[4]), check if they exist otherwise create outfile or return error
//2. write pipex function with fork, child & parent
//3. waitpid until child has finished before writing to outfile
	int in;
	int out;
	(void)	envp;
	(void)	argc;
	// int	i;

	in = open(argv[1], O_RDONLY);
	out = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (in < 0)
		return (error(ERR_INPUT));
	if (out < 0)
		return (error(ERR_OUTPUT));

	// i = 0;
	// while (*envp[i])
	// {
	// 	ft_putstr_fd(envp[i], 1);
	// 	i++;
	// }

//transform argv to **mycmd1 and **mycmd2 (in case each cmd contains >1 parts, p.e. wc -l), using split if necessary, otherwise strdup, the char ** can then be directly passed to execve as 2nd argument
//check access() for cmd1 and cmd2 to check if they exist and are executable
//3.

}