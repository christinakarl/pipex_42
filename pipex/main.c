/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:38:36 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/22 16:31:20 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*program imitating the pipe (|) command in shell, single pipe

parameters:
	argc = nr of all arguments incl program name
	argv = infile, cmd1, cmd2, outfile
	envp = environmental path, all possible paths for shell commands

notes on open():
	O_CREAT = create file if it doesn't exist
	O_RDWR = reading & writing rights
	O_TRUNC = erase content if necessary
	0666 = reading & writing rights to user, group, others
*/
int	main(int argc, char **argv, char **envp)
{
	int	in;
	int	out;

	if (argc != 5)
	{
		ft_putstr_fd(ERR_ARG, 2);
		return (-1);
	}
	in = open(argv[1], O_RDONLY);
	out = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (in < 0)
		return (error(ERR_INPUT));
	if (out < 0)
		return (error(ERR_OUTPUT));
	pipex(in, out, argv, envp);
	exit(0);
	return (0);
}
