#include "../includes/pipex.h"
#include "../Libft/includes/libft.h"

void	free_pipes(int **pipes)
{
	int	i;

	if (!pipes)
		return ;
	i = 0;
	printf("PIPE DIRF [%p]\n", pipes);
	while (pipes[i])
	{
		printf("i: %d, pipes[%d]: [%p]\n",i , i, pipes[i]);
		printf("PIPE FREE [%p]\n", pipes[i]);
		free(pipes[i]);
		i++;
		printf("PIPE DIRL [%p]\n", pipes);
	}
	printf("PIPE DIRF [%p]\n", pipes);
	printf("Aqui esta el problema\n");
	printf("PIPE FREE [%p]\n", pipes);
	free(pipes);
}

int	**create_pipes(int len, int len2)
{
	int	**pipes;
	int	i;

	if (len <= 0 || len2 <= 0)
		return (NULL);
	pipes = calloc(sizeof(int *), (len));
	printf("PIPE MLLC [%p]\n", pipes);
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < len)
	{
		pipes[i] = (int *)calloc(sizeof(int) , len2);
		if (!pipes[i])
			return (free_pipes(pipes), NULL);
		printf("PIPE MLLC [%p]\n", pipes[i]);
		i++;
	}
	printf("len: %d, i: %d, pipes[%d]: [%p]\n", len, i, i - 1, pipes[i - 1]);
	pipes[i] = (int *)NULL;
//	pipes[i] = (int *)MY_NULL;
	printf("len: %d, i: %d, pipes[%d]: [%p]\n", len, i, i, pipes[i]);
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
	if (i != 0)
		manage_fd(pipes[i - 1][1], pipes[i - 1][0], READ);
	if (command->next)
		manage_fd(pipes[i][0], pipes[i][1], WRITE);
	execve(command->exec_path, command->command, envp);
	exit(1);
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
	//	printf("%i: \"%s\" [%p]\n", i, command->exec_path, command->exec_path);
		if (command->next)
			pipe(pipes[i]);
		pid = fork();
		if (pid == 0)
			return (execute_program(command, envp, pipes, i));
		if (i != 0)
			manage_fd(pipes[i - 1][0], pipes[i - 1][1], -1);
		command = command->next;
		printf("PIPE DIR: [%p]\n", pipes);
	}
	printf("PIPE LAST [%p]\n", pipes);
	free_pipes(pipes);
}
