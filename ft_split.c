/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:19:20 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/22 16:23:27 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//count the nr of words in one string separated by delimitor c
int	ft_words(char const *s, char c)
{
	int	i;
	int	count;
	int	point;

	point = 1;
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && point == 1)
		{
			count += 1;
			point = 0;
		}
		else if (s[i] == c)
			point = 1;
		i++;
	}
	return (count);
}

//duplicate a string using start and end points
char	*ft_dup(char const *str, int start, int end)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(sizeof(*copy) * (end - start + 1));
	if (!copy)
		return (NULL);
	while (start < end)
		copy[i++] = str[start++];
	copy[i] = '\0';
	return (copy);
}

//split a string into a char ** using one character as the delimitor
char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	int		a;
	int		start;

	i = 0;
	a = 0;
	start = -1;
	tab = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1));
	if (!tab || !s)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			tab[a++] = ft_dup(s, start, i);
			start = -1;
		}
		i++;
	}
	tab[a] = 0;
	return (tab);
}
