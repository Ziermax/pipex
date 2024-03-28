/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:40:12 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/28 15:00:12 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_cmd
{
	char			**command;
	char			*exec_path;
	struct s_cmd	*next;
}	t_cmd;

void	free_split(char **split);
char	**ft_split(char *str);
t_cmd	*get_cmd_lst(int argc, char **argv);

#endif
