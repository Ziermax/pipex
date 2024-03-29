/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:00:24 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/29 14:10:29 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../Libft/includes/libft.h"

void	free_commands(t_cmd **command_lst)
{
	t_cmd	*aux;
	t_cmd	*tmp;

	if (!command_lst)
		return ;
	aux = *command_lst;
	while (aux)
	{
		tmp = aux->next;
		free_split(aux->command);
		free(aux);
		aux = tmp;
	}
	*command_lst = NULL;
}

t_cmd	*add_command(t_cmd **command_lst)
{
	t_cmd	*new;
	t_cmd	*last;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (free_commands(command_lst), NULL);
	new->command = NULL;
	new->next = NULL;
	if (!*command_lst)
		return (*command_lst = new);
	last = *command_lst;
	while (last->next)
		last = last->next;
	last->next = new;
	return (new);
}

char	*get_path(char *folder, char *program)
{
	char	*path;
	int		len_p;
	int		len_f;

	len_f = 0;
	len_p = 0;
	while (folder[len_f])
		len_f++;
	while (program[len_p])
		len_p++;
	if (!len_p && !len_f)
		return (NULL);
	path = malloc(sizeof(char) * (len_p + len_f + 1));
	if (!path)
		return (NULL);
	return (NULL);
}

t_cmd	*get_cmd_lst(int argc, char **argv)
{
	t_cmd	*command_lst;
	t_cmd	*new_command;
	char	**command_split;
	int		i;

	i = 0;
	command_lst = NULL;
	while (i < argc)
	{
		printf("%d < %d\n", i , argc);
		command_split = ft_split(argv[i]);
		if (!command_split)
			return (free_commands(&command_lst), NULL);
		new_command = add_command(&command_lst);
		if (!new_command)
			return (free_split(command_split), NULL);
		new_command->command = command_split;
		i++;
	}
	return (command_lst);
}
