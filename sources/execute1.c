/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:21:42 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/30 17:53:45 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	execute_command(t_cmd *command, char **envp)
{
	int		pid;
	int		len;
	int		i;
	t_pipe	*pipes;

	len = command_len(command);
	pipes = malloc(sizeof(char) * len - 1);
	if (!pipes)
		return ;
	i = 0;
	while (command && i < len)
	{
		printf("%i: \"%s\" [%p]\n", i, command->exec_path, command->exec_path);
		if (command->next)
			pipe(pipes[i].p);
		pid = fork();
		if (pid == 0)
		{
			if (i != 0)
			{
				close(pipes[i - 1].p[1]);
				dup2(pipes[i - 1].p[0], 0);
				close(pipes[i - 1].p[0]);
			}
			if (command->next)
			{
				close(pipes[i].p[0]);
				dup2(pipes[i].p[1], 1);
				close(pipes[i].p[1]);
			}
			execve(command->exec_path, command->command, envp);
			return ;
		}
		if (i != 0)
		{
			close(pipes[i - 1].p[0]);
			close(pipes[i - 1].p[1]);
		}
		i++;
		command = command->next;
	}
}
