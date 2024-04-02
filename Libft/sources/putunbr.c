/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:25:29 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/02 18:27:43 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/libft.h>
#include <unistd.h>

int	fd_putunbr(int fd, unsigned int nbr)
{
	int	num;

	if (nbr > 9)
	{
		if (fd_putunbr(fd, nbr / 10) == -1)
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
	return (ft_untlen(nbr));
}
