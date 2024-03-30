/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:40:12 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/30 20:16:47 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define READ 0
# define WRITE 1

typedef struct s_cmd
{
	char			**command;
	char			*exec_path;
	struct s_cmd	*next;
}	t_cmd;
/*
typedef struct s_data
{
	t_cmd	*command_list;
	int		count;
}	t_data;*/

typedef struct s_pipe
{
	int	[2];
}	t_pipe;

void	print_split(char **split);
void	free_commands(t_cmd **command_lst);
int		command_len(t_cmd *command);
char    *get_path(char *program, char **envp);
t_cmd	*get_cmd_lst(int argc, char **argv, char **envp);
void	execute_command(t_cmd *commnad_lst, char **envp);

#endif
