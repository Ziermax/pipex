/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:26:22 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/04 20:54:59 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../Libft/includes/libft.h"

void	open_file(char *file, int flag, int permissions, int redirect)
{
	int	fd;

	if (permissions)
		fd = open(file, flag, permissions);
	else
		fd = open(file, flag);
	if (fd == -1)
	{
		fd_printf(2, "pipex: %s: %s\n", file, strerror(errno));
		exit(errno);
	}
	if (dup2(fd, redirect) == -1)
		perror(file);
	close(fd);
}

void	here_doc(char *limit)
{
	int		doc[2];
	char	*line;
	char	*aux;
	int		len;

	if (pipe(doc) == -1)
		perror("pipe heredoc");
	line = (void *)1;
	len = ft_strlen(limit);
	while (line)
	{
		fd_printf(1, "pipedoc> ");
		line = get_next_line(STDIN_FILENO);
		aux = search_word_relative(limit, line, STR_START);
		if (!line || (aux && aux[len] == '\n'))
			break ;
		write(doc[1], line, ft_strlen(line));
	}
	if (!line)
		fd_printf(1, "\n");
	if (dup2(doc[0], STDIN_FILENO) == -1)
		perror("heredoc");
	manage_fd(doc[0], doc[1], -1);
}

void	open_read_file(char *file, int heredoc, char *limit)
{
	if (heredoc)
		here_doc(limit);
	else
		open_file(file, O_RDONLY, 0, STDIN_FILENO);
}

void	open_write_file(char *file, int heredoc)
{
	if (heredoc)
		open_file(file, O_WRONLY | O_APPEND | O_CREAT, 420, STDOUT_FILENO);
	else
		open_file(file, O_WRONLY | O_TRUNC | O_CREAT, 420, STDOUT_FILENO);
}
