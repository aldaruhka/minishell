/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_path_and_argv.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:37:39 by dwren             #+#    #+#             */
/*   Updated: 2022/08/02 14:00:22 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_for_all_execve(t_programm *programms)
{
	while (programms)
	{
		if (programms->programm_path)
			wait(0);
		programms = programms->next;
	}
}

void	free_splited_argv(char **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			free(s[i]);
			i++;
		}
	}
	free(s);
}

int	free_arguments_for_execve(t_programm *programms)
{
	t_programm	*tmp;

	while (programms != 0)
	{
		tmp = programms->next;
		free_splited_argv(programms->programm_argv);
		free(programms);
		programms = tmp;
	}
	return (1);
}

t_programm	*create_arguments_for_execve(int argc,
	char **paths, char *argv[], char *envp[])
{
	t_programm	*result;
	t_programm	*runner;
	int			start_position;

	start_position = 2 + shell_ft_strncmp(argv[1], "here_doc", 10);
	result = malloc(sizeof(t_programm));
	runner = result;
	while (start_position < argc - 1)
	{
		if (runner == 0 && shell_perror(argv[0])
			&& free_arguments_for_execve(result))
			return (NULL);
		runner->programm_argv = ft_split(argv[start_position], ' ');
		if (runner->programm_argv != 0)
			runner->programm_path = take_path(paths, runner->programm_argv[0]);
		runner->programm_envp = envp;
		if (++start_position < argc - 1)
		{
			runner->next = malloc(sizeof(t_programm));
			runner = runner->next;
		}
		else
			runner->next = 0;
	}
	return (result);
}
