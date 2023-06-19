/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:15:09 by ckarl             #+#    #+#             */
/*   Updated: 2023/01/04 12:29:22 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *print, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, print);
	while (print[i])
	{
		if (print[i] == '%')
		{
			len += print_decide(print[i + 1], args);
			i++;
		}
		else
			len += write(1, &print[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

int	print_decide(char const c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_put_c(va_arg(args, int));
	else if (c == 's')
		len += ft_put_s(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len += ft_put_nbr(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		len += ft_put_hex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		len += ft_put_ptr(va_arg(args, unsigned long long));
	else if (c == 'u')
		len += ft_put_unsign(va_arg(args, unsigned int));
	else if (c == '%')
		len += write(1, "%", 1);
	else if (len == 0)
		return (-1);
	return (len);
}
