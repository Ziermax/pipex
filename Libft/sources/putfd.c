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

#include "../"

int	putchar(int fd, int c)
{
	return (write(fd, &c, 1));
}

int	:wq

