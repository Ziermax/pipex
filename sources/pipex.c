/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:06:51 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/04 17:54:47 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../Libft/includes/libft.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*outfile;

	if (argc < 5)
		return (fd_printf(2, "Wrong number of arguments\n"));
	outfile = argv[argc - 1];
	if (!ft_strcmp("here doc", argv[1]))
	{
		if (argc < 6)
			return (fd_printf(2, "Wrong number of arguments\n"));
		here_doc(argv[2], &data, &argv, &argc);
	}
	else
		open_read_file(argv[1], &data);
	open_write_file(outfile, &data);
	data.cmd_lst = get_cmd_lst(argc - 3, &argv[2], envp);
	if (!data.cmd_lst)
		return (fd_printf(2, "Error mallocking commands\n"));
	data.cmd_len = command_len(data.cmd_lst);
	data.pipes = create_pipes(data.cmd_len, 2);
	if (!data.pipes)
		perror("pipe mallocking");
	execute_command(&data, envp);
	free_commands(&data.cmd_lst);
	return (data.status);
}
