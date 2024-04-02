/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 15:16:22 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/02 16:21:48 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../Libft/includes/libft.h"

void	free_pipes(int **pipes)
{
	int	i;

	if (!pipes)
		return ;
	i = 0;
	while (pipes[i])
		free(pipes[i++]);
	free(pipes);
}
//		printf("FREE %d: [%p]\n", i, pipes[i]);

int	**create_pipes(int len, int len2)
{
	int	**pipes;
	int	i;

	if (len <= 0 || len2 <= 0)
		return (NULL);
	pipes = malloc(sizeof(int *) * (len));
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		pipes[i] = malloc(sizeof(int) * len2);
		if (!pipes[i])
			return (free_pipes(pipes), NULL);
		i++;
	}
	pipes[i] = NULL;
	return (pipes);
}
//		printf("MLLC %d: [%p]\n", i, pipes[i]);
//	printf("MLLC %d: [%p]\n", i, pipes[i]);

void	manage_fd(int fd1, int fd2, int redirect)
{
	close(fd1);
	if (redirect != -1)
		dup2(fd2, redirect);
	close(fd2);
}

void	execute_program(t_cmd *command, char **envp, t_data dt, int i)
{
	int	j;

	j = i - 1;
	if (i != 0)
		manage_fd(dt.pipes[j][WR], dt.pipes[j][RD], STDIN_FILENO);
	else
	{
		if (dt.strerror_1)
		{
			write(2, dt.strerror_1, ft_strlen(dt.strerror_1));
			exit(dt.errno_1);
		}
	}
	if (command->next)
		manage_fd(dt.pipes[i][RD], dt.pipes[i][WR], STDOUT_FILENO);
	else
	{
		if (dt.strerror_2)
		{
			write(2, dt.strerror_2, ft_strlen(dt.strerror_2));
			exit(dt.errno_2);
		}
	}
	execve(command->exec_path, command->args, envp);
}

void	execute_command(t_data dt, char **envp)
{
	int	pid;
	t_cmd	*command;
	int	i;

	command = dt.cmd_lst;
	dt.cmd_len = command_len(command);
	dt.pipes = create_pipes(dt.cmd_len, 2);
	if (!dt.pipes)
		return ;
	i = 0;
	while (command)
	{
		if (command->next)
			pipe(dt.pipes[i]);
		pid = fork();
		if (pid == 0)
			return (execute_program(command, envp, dt, i));
		if (i != 0)
			manage_fd(dt.pipes[i - 1][0], dt.pipes[i - 1][1], -1);
		command = command->next;
		i++;
	}
	free_pipes(dt.pipes);
}
