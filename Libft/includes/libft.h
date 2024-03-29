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
void	*ft_calloc(size_t count, size_t size);
void	free_split(char **split);
char	*ft_strjoin(char *str1, char *str2);
char	**ft_split_char(char *str, char c);
char	**ft_split(char *str);

#endif
