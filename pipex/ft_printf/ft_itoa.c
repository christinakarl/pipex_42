/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:54:56 by ckarl             #+#    #+#             */
/*   Updated: 2023/01/04 12:24:59 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_islen(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_intmin(char *str, int a)
{
	if (a == -2147483648)
	{
		str[1] = '2';
		return (a += 2000000000);
	}
	return (a);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_islen(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		n = ft_intmin(str, n);
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i--] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
