/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:56:50 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/03 19:57:57 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_pipes(int **pipes)
{
	int	i;

	if (!pipes)
		return ;
	i = 0;
	while (pipes[i])
		free(pipes[i++]);
	free(pipes);
}

int	**create_pipes(int len, int len2)
{
	int	**pipes;
	int	i;

	if (len <= 0 || len2 <= 0)
		return (NULL);
	pipes = malloc(sizeof(int *) * (len));
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		pipes[i] = malloc(sizeof(int) * len2);
		if (!pipes[i])
			return (free_pipes(pipes), NULL);
		i++;
	}
	pipes[i] = NULL;
	return (pipes);
}
