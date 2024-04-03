/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:19:50 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/03 20:34:42 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../Libft/includes/libft.h"

void	here_doc(int argc, char **argv, t_data *data)
{
	int		doc[2];
	char	line;

	pipe(doc);
	line = (void *)1;
	while (line)
	{
		fd_printf(1, "heredoc> ");
		line = get_next_line(STDIN_FILENO);
		write(doc[1], line, ft_strlen(line));
	}
	dup2(doc[0], STDIN_FILENO);
	close(doc[0]);
	close(doc[1]);
	data->fd[0] = 2147483647;
	data->fd[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 420);
	if (data->fd[1] == -1)
	{
		data->errno_2 = errno;
		fd_printf(2, "pipex: %s: %s\n", argv[argc - 1], strerror(errno));
		return ;
	}
	dup2(data->fd[1], STDOUT_FILENO);
	close(data->fd[1]);
}
