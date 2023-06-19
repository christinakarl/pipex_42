/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:20:06 by ckarl             #+#    #+#             */
/*   Updated: 2023/01/04 12:21:37 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr(int n)
{
	int		len;
	char	*nbr;

	nbr = ft_itoa(n);
	len = ft_put_s(nbr);
	free(nbr);
	return (len);
}

int	ft_put_unsign(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_itoa_u(n);
	len = ft_put_s(str);
	free(str);
	return (len);
}
