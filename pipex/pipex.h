/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:38:29 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/22 17:55:07 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

# define ERR_ARG		"Please run the program as follows \
./pipex infile cmd1 cmd2 outfile"
# define ERR_INPUT		"Input file"
# define ERR_OUTPUT		"Output file"
# define ERR_CMD		"Enter valid command "
# define ERR_EXEC		"Execve "

int		error(char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
int		ft_words(char const *s, char c);
void	pipex(int inputfile, int outputfile, char **argv, char **envp);
void	parent_process(int out, char **argv, int end[2], char **envp);
void	child_process(int in, char **argv, int end[2], char **envp);
char	*get_path_line(char **envp);
char	*get_right_path(char *cmd, char **evnp);
char	*ft_join_path(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		find_c(char *str, char c);
char	*trim_front_and_back(char *str);
char	*trim_back(char *str);
char	*ft_strdup(const char *src);

#endif
