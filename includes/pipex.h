/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:40:12 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/04 20:45:11 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/errno.h>
# include <sys/wait.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define RD 0
# define WR 1
# define WNA "Wrong number of arguments\n"

typedef struct s_cmd
{
	char			**args;
	char			*exec_path;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	t_cmd	*cmd_lst;
	int		status;
	int		cmd_len;
	int		**pipes;
	int		heredoc;
	char	*infile;
	char	*outfile;
	char	*limit;
	int		fd[2];
	int		errno_1;
	int		errno_2;
}	t_data;

//void	open_read_file(char *file, t_data *data);
//void	open_write_file(char *file, t_data *data);
void	open_read_file(char *file, int heredoc, char *limit);
void	open_write_file(char *file, int heredoc);
void	here_doc(char *limit, t_data *data, char ***argv, int *argc);
void	manage_fd(int fd1, int fd2, int redirect);
void	free_pipes(int **pipes);
int		**create_pipes(int len, int len2);
int		command_len(t_cmd *command);
void	free_commands(t_cmd **command_lst);
char	*get_path(char *program, char **envp);
t_cmd	*get_cmd_lst(int argc, char **argv, char **envp);
void	execute_command(t_data *dt, char **envp);

#endif
