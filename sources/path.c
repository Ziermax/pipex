/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:43:19 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/30 17:39:57 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/libft.h"

char	**get_split_path(char **envp)
{
	char	*path;
	char	**split_path;

	path = search_word_in_split("PATH", envp);
	if (!path)
		return (NULL);
	path = search_word_in_str("=", path);
	if (!path)
		return (NULL);
	split_path = ft_split_char(&path[1], ':');
	if (!split_path)
		return (NULL);
	if (!*split_path)
		return (free_split(split_path), NULL);
	return (split_path);
}

char	*find_correct_path(char **path)
{
	char	*correct;
	int		i;

	i = 0;
	while (path[i])
	{
		correct = search_word_relative("/bin/", path[i], STR_START);
		if (correct)
			return (path[i]);
		i++;
	}
	return (NULL);
}

#include <stdio.h>
char	*get_path(char *program, char **envp)
{
	char	**split_path;
	char	*path;
	int		i;

	split_path = get_split_path(envp);
	if (!split_path)
		return (NULL);
	i = 0;
	while (split_path[i])
	{
		path = ft_threejoin(split_path[i], "/", program);
		printf("PATH: \"%s\" [%p]\n", path, path);
		if (!path)
			return (free_split(split_path), NULL);
		printf("SOLO FREE %p\n", split_path[i]);
		free(split_path[i]);
		split_path[i] = path;
		i++;
	}
	path = find_correct_path(split_path);
	free_split_save(split_path, path);
	return (path);
}
