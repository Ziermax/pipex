char	*search_word_in_str(char *word, char *str)
{
	int	i;

	if (!word || !str)
		return (NULL);
	while (*str)
	{
		i = 0;
		while (word[i] && str[i] == word[i])
			i++;
		if (word[i] == '\0')
			return (str);
		str++;
	}
	return (NULL);
}

char	*search_word_in_split(char *word, char **split)
{
	char	*found;
	int	i;

	if (!word || !split)
		return (NULL);
	i = 0;
	while (split[i])
	{
		found = search_word_in_str(word, split[i]);
		if (found)
			return (found);
		i++;
	}
	return (NULL);
}
