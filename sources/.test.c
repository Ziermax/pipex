/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:50:26 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/03 19:29:20 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int	main(int argc, char **argv, char **envp)
{
	char	*command[3] = {"echo", "HOla", NULL};
	char	*path = "/bin/echo";
	int		pid;
	int		pipes[2];

	if (argc != 1)
		return (0);
	argv = NULL;
	pipe(pipes);
	dup2(pipes[1], 0);
	for (int i = 0; i < 127; i++)
		printf("%d:\t%s\n", i, strerror(i));
	pid = fork();
	if (pid != 0)
	{
		path = "HOLa";
		dup2(pipes[0], 0);
		execve(path, command, envp);
		printf("test: %s: %s\n", path, strerror(errno));
		printf("Failed command pid: %d\n", pid);
		return (0);
	}
	printf("Finish\n");
}
