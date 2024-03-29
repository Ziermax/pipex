/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:06:51 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/29 14:02:21 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		printf(" | word[%d]: \"%s\"\n", i, split[i]);
}

void	print_commands(t_cmd *commands)
{
	while (commands)
	{
		printf("Command[%p]\n", commands);
		printf("Execute path: \"%s\"\n", commands->exec_path);
		print_split(commands->command);
		commands = commands->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*command_lst;
//	int		files[2];

	if (argc < 5)
		return (0);
//	open_files(argc, argv);
	command_lst = get_cmd_lst(argc - 3, &argv[2]);
	if (!command_lst)
		return (write(2, "Error mallocking commands\n", 26));
	print_commands(command_lst);
	envp = NULL;
//	execute_command(command_lst);
}
