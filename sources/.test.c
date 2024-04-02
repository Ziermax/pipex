/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:50:26 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/01 22:56:03 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int	main(int argc, char **argv, char **envp)
{
	char	*command[3] = {"ct", NULL};
	char	*path = "/bin/cat";
	int		pid;
//	int		pipes[2];

	if (argc != 1)
		return (0);
	argv = NULL;
//	pipe(pipes);
//	dup2(pipes[1], 0);
	pid = fork();
	if (pid != 0)
	{
//		dup2(pipes[0], 0);
		execve("cut", command, envp);
		perror("pipex: %s", command);
	}
	printf("Finish\n");
}
