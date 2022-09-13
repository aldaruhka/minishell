/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:13:52 by dwren             #+#    #+#             */
/*   Updated: 2022/09/01 23:13:52 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getpid(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		exit(1);
	}
	if (!pid)
	{
		exit(1);
	}
	waitpid(pid, NULL, 0);
	pid = pid - 1;
	return (ft_itoa(pid));
}

char	**envp_initialization(char *envp[])
{
	char	**result;
	int		i;

	if (!envp)
		return (malloc(sizeof(char *)));
	i = 0;
	while (envp[i])
		i++;
	result = malloc(sizeof(char *) * (i + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		result[i] = ft_strdup(envp[i]);
		i++;
	}
	result[i] = NULL;
	return (result);
}

t_data_shell	*initialization(char **envp)
{
	t_data_shell	*data_list;

	data_list = malloc(sizeof(t_data_shell) * 1);
	if (!data_list)
		return (NULL);
	data_list->lexer_list = NULL;
	data_list->command_list = NULL;
	data_list->envp = envp_initialization(envp);
	data_list->status = "0";
	data_list->str = NULL;
	data_list->p_id = ft_getpid();
	return (data_list);
}
