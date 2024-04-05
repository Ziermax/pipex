/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:06:51 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/05 19:52:49 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../Libft/includes/libft.h"

void	rearrange_arg(int *argc, char ***argv)
{
	if (*argc < 6)
		error_printf(0, "Wrong number of arguments\n");
	*argc -= 1;
	*argv = &(*argv)[1];
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc < 5)
		error_printf(0, "Wrong number of arguments\n");
	data.infile = argv[1];
	data.outfile = argv[argc - 1];
	data.limit = argv[2];
	data.heredoc = !ft_strcmp("here doc", argv[1]);
	if (data.heredoc)
		rearrange_arg(&argc, &argv);
	data.cmd_lst = get_cmd_lst(argc - 3, &argv[2], envp);
	if (!data.cmd_lst)
		error_printf(0, "Error mallocking commands\n");
	data.pipes = create_pipes(command_len(data.cmd_lst), 2);
	if (!data.pipes)
		error_printf(errno, "Error mallocking pipes\n");
	execute_command(&data, envp);
	free_pipes(data.pipes);
	free_commands(&data.cmd_lst);
	return (0);
}
