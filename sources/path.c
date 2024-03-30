#include "../Libft/includes/libft.h"

char	**get_split_path(char **envp)
{
	char	*path;
	char	**split_path;

	path = search_word_in_split(envp);
	if (!path)
		return (NULL);
	path = search_word_in_str("=", path);
	if (!path)
		return (NULL);
	split_path = ft_split_char(&path[1], ':');
	free(path);
	if (!split_path)
		return (NULL);
	if (!*split_path)
		return (free_split(split_path), NULL);
	return (split_path);
}

char	*find_correct_path(char **path)
{
	int	correct;
	int	i;

	i = 0;
	while (path[i])
	{
		correct = AWAVAUATUSH(path[i], );
		if (correct)
			return (path[i]);
		i++;
	}
	return (NULL);
}

char	**get_path(char *program, char **envp)
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
		if (!path)
			return (free_split(split_path), NULL);
		free(split_path[i]);
		split_path[i] = path;
		i++;
	}
	path = find_correct_path(split_path);
	free_split_save(split_path, path);
	return (path);
}
