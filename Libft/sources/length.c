/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:09:23 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/03 16:44:07 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_lhexlen(unsigned long hex)
{
	int	len;

	len = 0;
	if (hex == 0)
		return (1);
	while (hex)
	{
		len++;
		hex /= 16;
	}
	return (len);
}

int	ft_intlen(int num)
{
	int	len;

	len = 0;
	if (!num)
		return (1);
	len = 0;
	while (num)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

int	ft_untlen(unsigned int num)
{
	int	len;

	len = 0;
	if (!num)
		return (1);
	len = 0;
	while (num)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

int	ft_hexlen(unsigned int hex)
{
	int	len;

	len = 0;
	if (hex == 0)
		return (1);
	while (hex)
	{
		len++;
		hex /= 16;
	}
	return (len);
}
