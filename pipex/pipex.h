/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:38:29 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/19 17:24:48 by ckarl            ###   ########.fr       */
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
# include "ft_printf/ft_printf.h"

# define ERR_INPUT		"Input file"
# define ERR_OUTPUT		"Output file could not be created"
# define ERR_COMMAND	"Please enter valid commands"

int		error(char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
void	pipex(int inputfile, int outputfile, char **argv, char **envp);
void	parent_process(int out, char **argv, int end[2], char **envp);
void	child_process(int in, char **argv, int end[2], char **envp);
char	*get_PATH_line(char **envp);
char	*get_right_path(char *cmd, char **evnp);
char	*ft_join_path(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);

#endif
