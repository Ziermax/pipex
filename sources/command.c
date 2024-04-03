/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:00:24 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/04/03 19:49:09 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../Libft/includes/libft.h"

int	command_len(t_cmd *command)
{
	int	len;

	len = 0;
	while (command)
	{
		len += 1;
		command = command->next;
	}
	return (len);
}

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
		free_split(aux->args);
		free(aux->exec_path);
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
	new->args = NULL;
	new->next = NULL;
	if (!*command_lst)
		return (*command_lst = new);
	last = *command_lst;
	while (last->next)
		last = last->next;
	last->next = new;
	return (new);
}

t_cmd	*get_cmd_lst(int argc, char **argv, char **envp)
{
	t_cmd	*cmd_lst;
	t_cmd	*new_cmd;
	char	**cmd_split;
	int		i;

	i = 0;
	cmd_lst = NULL;
	while (i < argc)
	{
		cmd_split = ft_split(argv[i]);
		if (!cmd_split)
			return (free_commands(&cmd_lst), NULL);
		new_cmd = add_command(&cmd_lst);
		if (!new_cmd)
			return (free_split(cmd_split), NULL);
		new_cmd->args = cmd_split;
		new_cmd->exec_path = get_path(cmd_split[0], envp);
		if (!new_cmd->exec_path)
			return (free_commands(&cmd_lst), NULL);
		i++;
	}
	return (cmd_lst);
}
