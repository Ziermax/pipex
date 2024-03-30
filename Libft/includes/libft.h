/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:01:12 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/29 14:12:19 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int		ft_strlen(char *str);
int		ft_intlen(int num);
char	*search_word_in_str(char *word, char *str);
char	*search_word_in_split(char *word, char **split);
void	*ft_calloc(size_t count, size_t size);
void	free_split(char **split);
void    free_split_save(char **split, char *save);
char	*ft_strjoin(char *str1, char *str2);
char    *ft_threejoin(char *str1, char *str2, char *str3);
char	**ft_split_char(char *str, char c);
char	**ft_split(char *str);

#endif
