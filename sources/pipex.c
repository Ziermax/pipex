/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:06:51 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/30 17:12:44 by mvelazqu         ###   ########.fr       */
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
		print_split(commands->command);
		commands = commands->next;
	}
}

//	open_files(argc, argv);
int	main(int argc, char **argv, char **envp)
{
	t_cmd	*command_lst;

	if (argc < 5)
		return (0);
		command_lst = get_cmd_lst(argc - 3, &argv[2], envp);
	if (!command_lst)
		return (write(2, "Error mallocking commands\n", 26));
	print_commands(command_lst);
//	execve(command_lst->exec_path, command_lst->command, envp);
	execute_command(command_lst, envp);
	free_commands(&command_lst);
}
