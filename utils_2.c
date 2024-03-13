/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:10:31 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/22 16:22:32 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//print error text & return to main
int	error(char *str)
{
	perror(str);
	return (-1);
}

//malloc & copy a string
char	*ft_strdup(const char *src)
{
	char	*copy;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	copy = (char *)malloc(sizeof(*copy) * (i + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*in case the command is given with the path already,
we trim it to get the cmd only, in case there's an extra
space at the end, we use the trim_back function as well*/
char	*trim_front_and_back(char *str)
{
	char	**copy;
	int		len;
	int		x;

	if (find_c(str, '/') == 0)
	{
		str = trim_back(str);
		return (str);
	}
	len = ft_words(str, '/');
	copy = ft_split(str, '/');
	free(str);
	str = ft_strdup(copy[len - 1]);
	x = -1;
	while (copy[++x])
		free (copy[x]);
	free(copy);
	str = trim_back(str);
	return (str);
}

//trim the end of str in case there's a space
char	*trim_back(char *str)
{
	char	**copy;
	int		x;

	if (find_c(str, ' ') == 0)
		return (str);
	copy = ft_split(str, ' ');
	free(str);
	str = ft_strdup(copy[0]);
	x = -1;
	while (copy[++x])
		free (copy[x]);
	free(copy);
	return (str);
}
