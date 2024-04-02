/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:40:00 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/02 20:47:23 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_lunglen(unsigned long nbr)
{
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

static int	fd_putmem(int fd, unsigned long mem)
{
	int	num;

	if (mem >= 16)
	{
		if (ft_mem(fd, hex / 16) == -1)
			return (-1);
		if (ft_mem(fd, mem % 16) == -1)
			return (-1);
	}
	else
	{
		if (mem > 9)
		{
			mem = hex % 10 + 'a';
			return (write(fd, &num, 1));
		}
		else
		{

	}
}

int	fd_printmem(int fd, unsigned long mem)
{
	if (write(fd, "0x", 2) == -1)
		return (-1);
	if (fd_putmem(fd, mem) == -1)
		return (-1);
	return (ft_lunglen(mem));
}
