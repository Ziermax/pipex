/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:06:51 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/03 20:34:44 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../Libft/includes/libft.h"

void	open_files(int argc, char **argv, t_data *data)
{
	data->fd[0] = open(argv[1], O_RDONLY);
	if (data->fd[0] == -1)
	{
		data->errno_1 = errno;
		fd_printf(2, "pipex: %s: %s\n", argv[1], strerror(errno));
	}
	else
		dup2(data->fd[0], STDIN_FILENO);
	close(data->fd[0]);
	data->fd[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 420);
	if (data->fd[1] == -1)
	{
		data->errno_2 = errno;
		fd_printf(2, "pipex: %s: %s\n", argv[argc - 1], strerror(errno));
		return ;
	}
	dup2(data->fd[1], STDOUT_FILENO);
	close(data->fd[1]);
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		comms;

	if (argc < 5)
		return (fd_printf(2, "Wrong number of arguments\n"));
	open_files(argc, argv, &data);
	comms = 2;
	data.cmd_lst = get_cmd_lst(argc - comms - 1, &argv[comms], envp);
	if (!data.cmd_lst)
		return (fd_printf(2, "Error mallocking commands\n"));
	execute_command(&data, envp);
	free_commands(&data.cmd_lst);
	return (data.status);
}
