/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:06:51 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/04 20:48:03 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../Libft/includes/libft.h"

void	pexit(char *str, int error)
{
	write(2, str, ft_strlen(str));
	exit(error);
}

void	rearrange_arg(int *argc, char ***argv)
{
	if (*argc < 6)
		pexit("Wrong number of arguments\n", 0);
	*argc -= 1;
	*argv = &(*argv)[1];
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc < 5)
		pexit("Wrong number of arguments\n", 0);
	data.infile = argv[1];
	data.outfile = argv[argc - 1];
	data.limit = argv[2];
	data.heredoc = !ft_strcmp("here doc", argv[1]);
	if (data.heredoc)
		rearrange_arg(&argc, &argv);
	data.cmd_lst = get_cmd_lst(argc - 3, &argv[2], envp);
	if (!data.cmd_lst)
		pexit("Error mallocking commands\n", 0);
	data.cmd_len = command_len(data.cmd_lst);
	data.pipes = create_pipes(data.cmd_len, 2);
	if (!data.pipes)
		pexit("Error mallocking pipes\n", errno);
	execute_command(&data, envp);
	free_pipes(&data.pipes);
	free_commands(&data.cmd_lst);
	return (data.status);
}
