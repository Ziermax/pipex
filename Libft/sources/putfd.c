/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putfd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:31:13 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/02 20:47:20 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	fd_putchar(int fd, int c)
{
	return (write(fd, &c, 1));
}

int	fd_putstr(int fd, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len == 0)
		return (0);
	return (write(fd, str, len));
}

int	fd_putnbr(int fd, int nbr)
{
	int	num;

	if (nbr == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (nbr < 0)
	{
		if (fd_putchar(fd, "-") == -1)
			return (-1);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		if (fd_putnbr(fd, num / 10) == -1)
			return (-1);
		return (fd_putchar(fd, nbr % 10 + '0'));
	}
	return (fd_putchar(fd, nbr + '0'));
}

int	fd_putunbr(int fd, int nbr)
{
	if (nbr > 9)
	{
		if (fd_putunbr(fd, num / 10) == -1)
			return (-1);
		return (fd_putchar(fd, nbr % 10 + '0'));
	}
	return (fd_putchar(fd, nbr + '0'));
}

int	fd_puthex(int fd, int hex)
{
	char	num;

	if (hex >= 16)
	{
		if (fd_puthex(fd, hex / 16) == -1)
			return (-1);
		return (fd_puthex(fd, hex % 16));
	}
	else if (hex > 9)
		return (fd_putchar(fd, hex % 10 + 'a'));
	return (fd_putchar(fd, hex + '0'));
}
