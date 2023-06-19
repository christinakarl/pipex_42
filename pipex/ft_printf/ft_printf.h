/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:06:58 by ckarl             #+#    #+#             */
/*   Updated: 2023/01/04 12:08:49 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		print_decide(char const c, va_list args);
int		ft_put_c(int i);
char	*ft_itoa(int n);
char	*ft_itoa_u(unsigned int n);
int		ft_printf(const char *print, ...);
int		ft_put_s(char *str);
int		ft_put_nbr(int n);
int		ft_xlen(unsigned int n);
void	ft_nbr_hex(unsigned int n, char minmaj);
int		ft_put_hex(unsigned int n, char minmaj);
int		ft_ptrlen(unsigned long long n);
void	ft_nbr_ptr(unsigned long long n);
int		ft_put_ptr(unsigned long long n);
int		ft_put_unsign(unsigned int n);

#endif
