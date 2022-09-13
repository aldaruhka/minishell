/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programm_part.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:06:59 by dwren             #+#    #+#             */
/*   Updated: 2022/09/01 04:19:40 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_pipes_presence(t_command_list *runner)
{
	while (runner)
	{
		if (runner->type == PIPE)
			return (1);
		runner = runner->next;
	}
	return (0);
}

int	check_builtin_or_not(t_command_list *command)
{
	if (!ft_strncmp(command->content[0], "echo", -1))
	{
		;//echo()
		return (1);//сделай чтоб return (echo());
	}
	if (!ft_strncmp(command->content[0], "cd", -1))
	{
		;//cd()
		return (1);
	}
	if (!ft_strncmp(command->content[0], "pwd", -1))
	{
		;//pwd()
		return (1);
	}
	if (!ft_strncmp(command->content[0], "export", -1))
	{
		;//export()
		return (1);
	}
	if (!ft_strncmp(command->content[0], "unset", -1))
	{
		;//unset()
		return (1);
	}
	if (!ft_strncmp(command->content[0], "env", -1))
	{
		;//env()
		return (1);
	}
	if (!ft_strncmp(command->content[0], "exit", -1))
	{
		;//exit()
		return (1);
	}
	return (0);
}

void	exec_with_pipes(t_data_shell *data)
{
	(void)data;
}

void	exec_without_pipes(t_data_shell *data)
{
	(void)data;
}

void	programm_part(t_data_shell *data)
{
	if (is_pipes_presence(data->command_list))
		exec_with_pipes(data);
	else
		exec_without_pipes(data);
}