/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:27:51 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/02 18:39:32 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/libft.h"

int	fd_puthex(int fd, unsigned int hex)
{
	char	num;

	if (hex >= 16)
	{
		if (ft_puthex(fd, hex / 16) == -1)
			return (-1);
		if (ft_puthex(fd, hex % 16) == -1)
			return (-1);
	}
	else
	{
		if (hex > 9)
		{
			num = hex % 10 + 'a';
			return (write(fd, &num, 1));
		}
		else
		{
			num = hex + '0';
			return (write(fd, &num, 1));
		}
	}
	return (ft_hexlen(hex));
}

int	fd_putchex(int fd, unsigned int hex)
{
	char	num;

	if (hex >= 16)
	{
		if (ft_puthex(fd, hex / 16) == -1)
			return (-1);
		if (ft_puthex(fd, hex % 16) == -1)
			return (-1);
	}
	else
	{
		if (hex > 9)
		{
			num = hex % 10 + 'A';
			return (write(fd, &num, 1));
		}
		else
		{
			num = hex + '0';
			return (write(fd, &num, 1));
		}
	}
	return (ft_hexlen(hex));
}
