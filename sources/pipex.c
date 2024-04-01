/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:06:51 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/01 21:53:45 by mvelazqu         ###   ########.fr       */
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

int	open_files(int argc, char **argv)
{
	int	fd[2];

	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] == -1)
		fd[0] = STDIN_FILENO;
	dup2(fd[0], STDIN_FILENO);
	if (fd[0] != STDIN_FILENO)
		close(fd[0]);
	fd[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 420);
	if (fd [1] < 0)
		return (-1);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd_lst;

	if (argc < 4)
		return (0);
	if (open_files(argc, argv) == -1)
		return (write(2, "Could not open nor creat outfile\n", 33));
	cmd_lst = get_cmd_lst(argc - 3, &argv[2], envp);
	if (!cmd_lst)
		return (write(2, "Error mallocking commands\n", 26));
	execute_command(cmd_lst, envp);
	free_commands(&cmd_lst);
}
//	print_commands(cmd_lst);
//
//	char	lectura[11];
//	printf("files opened\n");
//	read(0, lectura, 10);
//	lectura[10] = '\0';
//	printf("lectura: \"%s\"\n'%d' '%d' '%d' '%d' '%d'\n", lectura, lectura[0],
//		lectura[1], lectura[2], lectura[3], lectura[4]);
