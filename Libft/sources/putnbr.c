/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:02:55 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/02 18:23:55 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <../includes/libft.h>

int	fd_putnbr(int fd, int nbr)
{
	int	num;

	if (nbr == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (nbr < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		if (fd_putnbr(fd, num / 10) == -1)
			return (-1);
		num = nbr % 10 + '0';
		if (write(fd, &num, 1) == -1)
			return (-1);
	}
	else
	{
		num = nbr + '0';
		if (write(fd, &num, 1) == -1)
			return (-1);
	}
	return (ft_intlen(nbr));
}
