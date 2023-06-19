/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:22:02 by ckarl             #+#    #+#             */
/*   Updated: 2023/01/04 12:24:29 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(unsigned long long n)
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

void	ft_nbr_ptr(unsigned long long n)
{
	if (n >= 16)
	{
		ft_nbr_ptr(n / 16);
		ft_nbr_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_put_c((int)n + 48);
		else
			ft_put_c((int)n + 87);
	}
}

int	ft_put_ptr(unsigned long long n)
{
	int	len;

	len = 0;
	len += write(1, "0", 1);
	len += write(1, "x", 1);
	ft_nbr_ptr(n);
	len += ft_ptrlen(n);
	return (len);
}
