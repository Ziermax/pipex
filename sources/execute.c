/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 15:16:22 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/05 18:05:37 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../Libft/includes/libft.h"

void	exit_free(t_data *data)
{
	free_pipes(data->pipes);
	free_commands(&data->cmd_lst);
	perror("Forking");
}

void	manage_fd(int fd1, int fd2, int redirect)
{
	close(fd1);
	if (redirect != -1 && dup2(fd2, redirect) == -1)
		perror("dup2:");
	close(fd2);
}

void	execute_program(t_cmd *command, char **envp, t_data dt, int i)
{
	int	j;

	j = i - 1;
	if (i != 0)
		manage_fd(dt.pipes[j][WR], dt.pipes[j][RD], STDIN_FILENO);
	else
		open_read_file(dt.infile, dt.heredoc, dt.limit);
	if (command->next)
		manage_fd(dt.pipes[i][RD], dt.pipes[i][WR], STDOUT_FILENO);
	else
		open_write_file(dt.outfile, dt.heredoc);
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
		if (command->next && pipe(dt->pipes[i]) == -1)
			perror("Piping");
		pid = fork();
		if (pid == -1)
			exit_free(dt);
		if (pid == 0)
			return (execute_program(command, envp, *dt, i));
		if (i != 0)
			manage_fd(dt->pipes[i - 1][0], dt->pipes[i - 1][1], -1);
		command = command->next;
		i++;
		wait(&pid);
	}
}
