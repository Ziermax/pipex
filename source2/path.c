/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:43:19 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/04 17:17:31 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/libft.h"
#include "../includes/pipex.h"

char	**get_split_path(char **envp)
{
	char	*path;
	char	**split_path;

	path = search_word_in_split("PATH", envp);
	if (!path)
		return (ft_calloc(sizeof(char *), 1));
	path = search_word_in_str("=", path);
	if (!path)
		return (ft_calloc(sizeof(char *), 1));
	split_path = ft_split_char(&path[1], ':');
	if (!split_path)
		return (NULL);
	return (split_path);
}

char	*find_correct_path(char **path)
{
	int	correct;
	int	i;

	i = 0;
	while (path[i])
	{
		correct = access(path[i], X_OK);
		if (correct == 0)
			return (path[i]);
		i++;
	}
	return (NULL);
}

char	*get_path(char *program, char **envp)
{
	char	**split_path;
	char	*path;
	int		i;

	if (!program)
		return (ft_calloc(sizeof(char), 1));
	split_path = get_split_path(envp);
	if (!split_path)
		return (NULL);
	i = 0;
	while (split_path[i])
	{
		path = ft_threejoin(split_path[i], "/", program);
		if (!path)
			return (free_split(split_path), NULL);
		free(split_path[i]);
		split_path[i] = path;
		i++;
	}
	path = find_correct_path(split_path);
	free_split_save(split_path, path);
	if (!path)
		path = ft_strdup(program);
	return (path);
}
