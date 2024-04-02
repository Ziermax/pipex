/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:40:12 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/01 23:00:54 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define RD 0
# define WR 1

typedef struct s_cmd
{
	char			**args;
	char			*exec_path;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	t_cmd	*cmd_lst;
	int		cmd_len;
	int		**pipes;
	int		fd[2];
}	t_data;

void	print_split(char **split);
void	free_commands(t_cmd **command_lst);
int		command_len(t_cmd *command);
char	*get_path(char *program, char **envp);
t_cmd	*get_cmd_lst(int argc, char **argv, char **envp);
void	execute_command(t_data dt, char **envp);

#endif
