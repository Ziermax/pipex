/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:09:23 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/28 17:11:28 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_intlen(int num)
{
	int	len;

	if (!num)
		return (1);
	len = 0;
	while (num)
	{
		len++;
		num = num / 10;
	}
	return (num);
}
