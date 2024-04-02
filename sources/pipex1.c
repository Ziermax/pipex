/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:06:51 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/01 23:04:06 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		printf(" | | word[%d]: \"%s\" [%p]\n", i, split[i], split[i]);
	printf("\n");
}

void	print_commands(t_cmd *commands)
{
	while (commands)
	{
		printf("Command[%p]\n", commands);
		printf(" | Execute path: \"%s\" [%p]\n",
			commands->exec_path, commands->exec_path);
		print_split(commands->args);
		commands = commands->next;
	}
}

int	open_files(int argc, char **argv, t_data *data)
{
	data->fd[0] = open(argv[1], O_RDONLY);
	if (data->fd[0] != -1)
		dup2(data->fd[0], STDIN_FILENO);
	if (data->fd[0] != STDIN_FILENO)
		close(data->fd[0]);
	data->fd[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 420);
	if (data->fd [1] < 0)
		return (-1);
	dup2(data->fd[1], STDOUT_FILENO);
	close(data->fd[1]);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd_lst;
	t_data	data;

	if (argc < 4)
		return (0);
	if (open_files(argc, argv, &data) == -1)
		return (write(2, "Could not open nor creat outfile\n", 33));
	data.cmd_lst = get_cmd_lst(argc - 3, &argv[2], envp);
	if (!data.cmd_lst)
		return (write(2, "Error mallocking commands\n", 26));
	execute_command(data, envp);
	free_commands(&data.cmd_lst);
}
//	print_commands(data.cmd_lst);
//
//	char	lectura[11];
//	printf("files opened\n");
//	read(0, lectura, 10);
//	lectura[10] = '\0';
//	printf("lectura: \"%s\"\n'%d' '%d' '%d' '%d' '%d'\n", lectura, lectura[0],
//		lectura[1], lectura[2], lectura[3], lectura[4]);
