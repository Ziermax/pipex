#include "../includes/pipex.h"
#include "../Libft/includes/libft.h"

void	free_pipes(int **pipes, int len)
{
	int	i;

	if (!pipes)
		return ;
	i = 0;
	while (i < len && pipes[i])
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

int	**create_pipes(int len, int len2)
{
	int	**pipes;
	int	i;

	if (len <= 0 || len2 <= 0)
		return (NULL);
	pipes = malloc(sizeof(int *) * (len));
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < len)
	{
		pipes[i] = malloc(sizeof(int) * len2);
		if (!pipes[i])
			return (free_pipes(pipes), NULL);
		i++;
	}
	pipes[i] = (int *)NULL;
	return (pipes);
}

void	manage_fd(int fd1, int fd2, int redirect)
{
	close(fd1);
	if (redirect != -1)
		dup2(fd2, redirect);
	close(fd2);

}

void	execute_program(t_cmd *command, char **envp, int **pipes, int i)
{
	int	j;

	j = i - 1;
	if (i != 0)
		manage_fd(pipes[j][WR], pipes[j][RD], RD);
	if (command->next)
		manage_fd(pipes[i][RD], pipes[i][WR], WR);
	execve(command->exec_path, command->command, envp);
}

void	execute_command(t_cmd *command, char **envp)
{
	int	**pipes;
	int	pid;
	int	len;
	int	i;

	len = command_len(command);
	pipes = create_pipes(len, 2);
	if (!pipes)
		return ;
	i = 0;
	while (i < len && command)
	{
		if (command->next)
			pipe(pipes[i]);
		pid = fork();
		if (pid == 0)
			return (execute_program(command, envp, pipes, i));
		if (i != 0)
			manage_fd(pipes[i - 1][0], pipes[i - 1][1], -1);
		command = command->next;
		i++;
	}
	free_pipes(pipes, len);
}
