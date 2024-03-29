/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:21:42 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/29 19:36:28 by mvelazqu         ###   ########.fr       */
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
		printf("%i: \"%s\"\n", i, command->exec_path);
		pid = fork();
		if (command->next)
		{
			pipe(pipes[i].p);
			printf("Pipe creada %d [%d, %d]\n", i, pipes[i].p[0], pipes[i].p[1]);
		}
		if (pid == 0)
		{
			if (i != 0)
			{
				printf("Closing writing %d:\n", i);
				printf("pipe[%d]\n", i - 1);
				printf("close: %d\ndup2(%d, 0)\nclose: %d\n\n",
						pipes[i - 1].p[1],pipes[i - 1].p[0],pipes[i - 1].p[0]);
//				close(pipes[i - 1].p[1]);
				dup2(pipes[i - 1].p[0], 0);
//				close(pipes[i - 1].p[0]);
			}
			if (command->next)
			{
				printf("Closing reading %d:\n", i);
				printf("pipe[%d]\n", i);
				printf("close: %d\ndup2(%d, 1)\nclose: %d\n\n",
						pipes[i].p[0],pipes[i].p[1],pipes[i].p[1]);
//				close(pipes[i].p[0]);
				dup2(pipes[i].p[1], 1);
//				close(pipes[i].p[1]);
			}
			printf("%d\n", execve(command->exec_path, command->command, envp));
			return ;
		}
		if (i != 0)
		{
//			close(pipes[i - 1].p[0]);
//			close(pipes[i - 1].p[1]);
			printf("pipe[%d]:\nclose: %d\nclose: %d\n\n", i - 1,
				pipes[i - 1].p[0], pipes[i - 1].p[1]);
		}
		i++;
		command = command->next;
	}
}
