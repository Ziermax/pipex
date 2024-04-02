/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:59:39 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/02 18:02:32 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	fd_putstr(int fd, char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (write(fd, "(null)", 6));
	while (str[len])
		len++;
	return (write(fd, str, len));
}
