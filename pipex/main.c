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

//print error text & return to main
int	error(char *str)
{
	perror(str);
	return (-1);
}

//get entire text line following "PATH=" from envp
char	*get_PATH_line(char **envp)
{
	char	*envp_PATH;

	// envp_PATH = NULL;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH", 4) == 0)
			envp_PATH = *envp;
		envp++;
	}
	return (envp_PATH + 5);
}

//find the right path for a specific command in order to pass it to envp in child/parent, using access check function
char	*get_right_path(char *cmd, char **envp)
{
	char	**all_paths;
	char	*temp_path;

	all_paths = ft_split(get_PATH_line(envp), ':');
	while (*all_paths)
	{
		temp_path = ft_join_path(*all_paths, cmd);
		if (access(temp_path, 0) == 0)
			return (temp_path);
		free(temp_path);
		all_paths++;
	}
	return (NULL);
}

//child process: dup2 stdin & stdout, close reading end[0] which will be used by parent, execve
void	child_process(int in, char **argv, int end[2], char **envp)
{
	char	**cmd1;
	char	*cmd1_path;

	cmd1 = ft_split(argv[2], ' ');
	cmd1_path = get_right_path(argv[2], envp);
	ft_printf("%s\n", cmd1_path);
	if (!cmd1_path)
		return (perror("Enter valid command 1"));
	if (dup2(in, STDIN_FILENO) < 0)
		return (perror("Dup2 stdin (child)"));
	if (dup2(end[1], STDOUT_FILENO) < 0)
		return (perror("Dup2 stdout (child)"));
	close(in);
	close(end[0]);

	if (execve(cmd1_path, cmd1, envp) < 0)
		return (perror("Execve (child)"));
	free(cmd1);
	free(cmd1_path);

}

//parent process: dup2 stdin & stdout, close writing end[1] which was used by child, execve (envp[2])
void	parent_process(int out, char **argv, int end[2], char **envp)
{
	char	**cmd2;
	char	*cmd2_path;
	int		status;

	waitpid(0, &status, 0);
	cmd2 = ft_split(argv[4], ' ');
	cmd2_path = get_right_path(argv[3], envp);
	if (!cmd2_path)
		return (perror("Enter valid command 2"));

	if (dup2(end[0], STDIN_FILENO) < 0)
		return (perror("Dup2 stdin (parent)"));
	if (dup2(out, STDOUT_FILENO) < 0)
		return (perror("Dup2 stdout (parent)"));
	close(out);
	close(end[1]);

	if (execve(cmd2_path, cmd2, envp) < 0)
		return (perror("Execve (parent)"));
	free(cmd2);
	free(cmd2_path);
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
		child_process(in, argv, end, envp);
	else
		parent_process(out, argv, end, envp);
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

	pipex(in, out, argv, envp);
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