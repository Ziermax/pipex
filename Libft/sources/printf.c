/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:18:41 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/02 20:47:25 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "../includes/libft.h"

static int	ft_lunglen(unsigned long hex)
{
	int len;

	if (hex == 0)
		return (1);
	while (hex)
	{
		len++;
		hex /= 16;
	}
	return (len);
}

static int	fd_printnbr(int fd, int nbr, int n)
{
	if (n == 'd' || n == 'i')
	{
		if (fd_putnbr(fd, nbr) == -1)
			return (-1);
		return(ft_intlen(nbr));
	}
	if (fd_putunbr(fd, (unsigned int)nbr) == -1)
		return (-1);
	return (ft_intlun(nbr));
}

static int	fd_printhex(int fd, int hex, int x)
{
	if (x == 'x' && fd_puthex(fd, hex) == -1)
		return (-1);
	else if (x == 'X' && fd_putchex(fd, hex) == -1)
		return (-1);
	return (ft_hexlen(hex));
}

static int	fd_percentge(int fd, char c, va_list ap, int *len)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret = (fd_putchar(fd, va_arg(ap, int)));
	else if (c == 's')
		ret = (fd_putstr(fd, va_arg(ap, char *)));
	else if (c == 'p')
		ret = (fd_printmem(fd, va_arg(ap, long)));
	else if (c == 'd' || c == 'i' || c == 'u')
		ret = (fd_printnbr(fd, va_arg(ap, int), c));
	else if (c == 'x' || c == 'X')
		ret = (fd_printhex(fd, va_arg(ap, unsigned int)), c);
	else if (c == '%')
		ret = (fd_putchar(fd, '%'));
	*len += ret;
	return (ret);
}

int	fd_printf(int fd, char *str, ...)
{
	va_list	ap;
	int		ret;
	int		i;

	ret = 0;
	va_start(ap, str);
	while (*str)
	{
		i = 0;
		while (str[i] && str[i] != '%')
			i++;
		if (write(fd, str, i) == -1)
			return (va_end(ap), -1);
		ret += i;
		str = &str[i];
		if (*str == '%')
		{
			if (fd_percentge(fd, *(++str), ap, &ret) == -1)
				return (va_end(ap), -1);
		}
		if (*str)
			str++;
	}
	return (va_end(ap), ret);
}
