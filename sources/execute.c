/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 15:16:22 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/04 17:50:27 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../Libft/includes/libft.h"

void	manage_fd(int fd1, int fd2, int redirect)
{
	close(fd1);
	if (redirect != -1)
	{
		if (dup2(fd2, redirect) == -1)
			perror("dup2:");
	}
	close(fd2);
}

void	execute_program(t_cmd *command, char **envp, t_data dt, int i)
{
	int	j;

	j = i - 1;
	if (i != 0)
		manage_fd(dt.pipes[j][WR], dt.pipes[j][RD], STDIN_FILENO);
	else
		if (dt.fd[0] == -1)
			exit(dt.errno_1);
	if (command->next)
		manage_fd(dt.pipes[i][RD], dt.pipes[i][WR], STDOUT_FILENO);
	else
		if (dt.fd[1] == -1)
			exit(dt.errno_2);
	execve(command->exec_path, command->args, envp);
	fd_printf(2, "pipex: %s: %s\n", command->args[0], strerror(errno));
	exit(errno);
}

void	execute_command(t_data *dt, char **envp)
{
	t_cmd	*command;
	int		pid;
	int		i;

	command = dt->cmd_lst;
	i = 0;
	while (command)
	{
		if (command->next)
		{
			if (pipe(dt->pipes[i]) == -1)
				perror("pipe command");
		}
		pid = fork();
		if (pid == 0)
			return (execute_program(command, envp, *dt, i));
		if (i != 0)
			manage_fd(dt->pipes[i - 1][0], dt->pipes[i - 1][1], -1);
		command = command->next;
		i++;
		wait(&dt->status);
		dt->status = errno;
	}
	free_pipes(dt->pipes);
}
