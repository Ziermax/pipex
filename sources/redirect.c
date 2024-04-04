/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:26:22 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/04 17:44:29 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../Libft/includes/libft.h"

void	open_read_file(char *file, t_data *data)
{
	data->fd[0] = open(file, O_RDONLY);
	if (data->fd[0] == -1)
	{
		data->errno_1 = errno;
		fd_printf(2, "pipex: %s: %s\n", file, strerror(errno));
		return ;
	}
	if (dup2(data->fd[0], STDIN_FILENO))
		perror(file);
	close(data->fd[0]);
}

void	open_write_file(char *file, t_data *data)
{
	data->fd[1] = open(file, O_WRONLY | O_TRUNC | O_CREAT, 420);
	if (data->fd[1] == -1)
	{
		data->errno_2 = errno;
		fd_printf(2, "pipex: %s: %s\n", file, strerror(errno));
		return ;
	}
	if (dup2(data->fd[1], STDOUT_FILENO) == -1)
		perror(file);
	close(data->fd[1]);
}

void	here_doc(char *limit, t_data *data, char ***argv, int *argc)
{
	int		doc[2];
	char	*line[2];
	int		limit_len;

	if (pipe(doc) == -1)
		perror("pipe heredoc");
	limit_len = ft_strlen(limit);
	while (1)
	{
		fd_printf(1, "pipedoc> ");
		line[0] = get_next_line(STDIN_FILENO);
		line[1] = search_word_relative(limit, line[0], STR_START);
		if (!line[0] || (line[1] && line[1][limit_len] == '\n'))
			break ;
		write(doc[1], line[0], ft_strlen(line[0]));
	}
	if (!line[0])
		fd_printf(1, "\n");
	if (dup2(doc[0], STDIN_FILENO) == -1)
		perror("heredoc");
	manage_fd(doc[0], doc[1], -1);
	data->fd[0] = 0;
	*argv = &(*argv)[1];
	*argc -= 1;
}
