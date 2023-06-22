/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:06:29 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/22 16:19:34 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//get entire text line following "PATH=" from envp
char	*get_path_line(char **envp)
{
	char	*envp_path;

	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH", 4) == 0)
			envp_path = *envp;
		envp++;
	}
	return (envp_path + 5);
}

/*find the right path for a specific command (without parameters)
in order to pass it to envp in child/parent using access check function
(existing & executable)*/
char	*get_right_path(char *cmd, char **envp)
{
	char	**all_paths;
	char	*temp_path;

	all_paths = ft_split(get_path_line(envp), ':');
	while (*all_paths)
	{
		temp_path = ft_join_path(*all_paths, cmd);
		if (access(temp_path, F_OK & X_OK) == 0)
			return (temp_path);
		free(temp_path);
		all_paths++;
	}
	return (NULL);
}

/*child process:
- split by single quotes (if present)
- trim first cmd argument by space (at the end) or / (in the beginning)
- dup2 stdin & stdout, close reading end[0]
- execve*/
void	child_process(int in, char **argv, int end[2], char **envp)
{
	char	**cmd1;
	char	*cmd1_path;

	if (find_c(argv[2], 39) != 0)
		cmd1 = ft_split(argv[2], 39);
	else
		cmd1 = ft_split(argv[2], ' ');
	cmd1[0] = trim_front_and_back(cmd1[0]);
	cmd1_path = get_right_path(cmd1[0], envp);
	if (!cmd1_path)
		return (perror(ERR_CMD "1"));
	dup2(in, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(in);
	close(end[0]);
	if (execve(cmd1_path, cmd1, envp) < 0)
		return (perror(ERR_EXEC "(child)"));
	free(cmd1);
	free(cmd1_path);
}

/*parent process:
- split by single quotes (if present)
- trim first cmd argument by space (at the end) or / (in the beginning)
- dup2 stdin & stdout, close writing end[1]
- execve*/
void	parent_process(int out, char **argv, int end[2], char **envp)
{
	char	**cmd2;
	char	*cmd2_path;

	waitpid(0, NULL, 0);
	if (find_c(argv[3], 39) != 0)
		cmd2 = ft_split(argv[3], 39);
	else
		cmd2 = ft_split(argv[3], ' ');
	cmd2[0] = trim_front_and_back(cmd2[0]);
	cmd2_path = get_right_path(cmd2[0], envp);
	if (!cmd2_path)
		return (perror(ERR_CMD "2"));
	dup2(end[0], STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(out);
	close(end[1]);
	if (execve(cmd2_path, cmd2, envp) < 0)
		return (perror(ERR_EXEC "(parent)"));
	free(cmd2);
	free(cmd2_path);
}

//pipex function creating pipe, fork, child, parent
void	pipex(int in, int out, char **argv, char **envp)
{
	int		end[2];
	pid_t	process;

	pipe(end);
	process = fork();
	if (process < 0)
		return (perror("Fork"));
	else if (process == 0)
		child_process(in, argv, end, envp);
	else
		parent_process(out, argv, end, envp);
}
