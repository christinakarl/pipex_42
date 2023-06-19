/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:16:33 by ckarl             #+#    #+#             */
/*   Updated: 2023/01/04 12:19:43 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void	ft_nbr_hex(unsigned int n, char minmaj)
{
	if (n >= 16)
	{
		ft_nbr_hex(n / 16, minmaj);
		ft_nbr_hex(n % 16, minmaj);
	}
	else
	{
		if (n <= 9)
			ft_put_c((int)n + 48);
		else
		{
			if (minmaj == 'x')
				ft_put_c((int)n + 87);
			else
				ft_put_c((int)n + 55);
		}
	}
}

int	ft_put_hex(unsigned int n, char minmaj)
{
	int	len;

	len = 0;
	ft_nbr_hex(n, minmaj);
	len = ft_xlen(n);
	return (len);
}
