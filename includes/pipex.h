/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:40:12 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/29 14:27:17 by mvelazqu         ###   ########.fr       */
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

t_cmd	*get_cmd_lst(int argc, char **argv);

#endif
