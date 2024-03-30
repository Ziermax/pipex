/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:01:12 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/30 18:57:39 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# define MY_NULL (int *)0

# define STR_START 1
# define STR_ANY 2
# define STR_END 4

int		ft_strlen(char *str);
int		ft_intlen(int num);
char	*search_word_relative(char *word, char *str, int flag);
char	*search_word_in_str(char *word, char *str);
char	*search_word_in_split(char *word, char **split);
void	*ft_calloc(int count, int size);
void	free_split(char **split);
void    free_split_save(char **split, char *save);
char	*ft_strjoin(char *str1, char *str2);
char    *ft_threejoin(char *str1, char *str2, char *str3);
char	**ft_split_char(char *str, char c);
char	**ft_split(char *str);

#endif
