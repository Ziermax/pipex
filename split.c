/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:39:06 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/27 16:44:19 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	count_words(char *str)
{
	int	words;

	words = 0;
	while (*str)
	{
		while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
			str++;
		if (*str)
			words += 1;
		while (*str && *str != ' ' && (*str < '\t' || *str > '\r'))
			str++;
	}
	return (words);
}

char	*get_word(char **position)
{
	char	*str;
	char	*word;
	int		len;

	len = 0;
	str = *position;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (str[len] && str[len] != ' ' && (str[len] < '\t' || str[len] > '\r'))
		len++;
	*position = &str[len];
	if (!len)
		return (NULL);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	word[len--] = '\0';
	while (len >= 0)
	{
		word[len] = str[len];
		len--;
	}
	return (word);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

char	**ft_split(char *str)
{
	char	**split;
	int		words;
	int		i;

	words = count_words(str);
	if (!words)
		return ((void *)1);
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < words)
	{
		split[i] = get_word(&str);
		if (!split[i++])
			return (free_split(split), NULL);
	}
	split[i] = NULL;
	return (split);
}
/*
int	main(int argc, char **argv)
{
	char	**split;

	if (argc != 2)
		return (0);
	split = ft_split(argv[1]);
	if (!split)
		return (0);
	forx (int i = 0; split[i]; i++)
		printf("split[%d]: \"%s\"\n", i, split[i]);
	free_split(split);

	char	*word;

	if (argc != 2)
		return (0);
	word = (void *)1;
	while (word)
	{
		word = get_word(&argv[1]);
		printf("word: \"%s\"\n", word);
		printf("Y me quede en: \"%s\"\n", argv[1]);
		free(word);
	}
}*/
