/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 03:57:55 by dwren             #+#    #+#             */
/*   Updated: 2022/09/13 21:24:24 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_in_envp(char ***envp, char *new)
{
	int		i;
	char	**result;

	i = 0;
	if (!new)
		return ;
	while (envp && *envp && (*envp)[i])
		i++;
	result = malloc(sizeof(char *) * (i + 2));
	if (!result)
		return ;
	i = 0;
	while (envp && *envp && (*envp)[i])
	{
		result[i] = (*envp)[i];
		i++;
	}
	result[i] = ft_strdup(new);
	result[i + 1] = NULL;
	free(*envp);
	*envp = result;
}

char	*get_from_envp(char **envp, char *name)
{
	int		i;
	int		len;
	char	*result;

	result = NULL;
	i = 0;
	if (envp && name)
	{
		while (envp[i] && ft_strncmp(envp[i], name, -1) != '=')
			i++;
		if (!envp[i])
			return (NULL);
		len = 0;
		while (envp[i] && envp[i][len] != '=')
			len++;
		result = &envp[i][len + 1];
	}
	return (result);
}

void	del_from_envp(char **envp, char *del)
{
	int		i;

	i = 0;
	if (!del || !envp)
		return ;
	if (!ft_strncmp(del, "PATH", -1) || !ft_strncmp(del, "PS1", -1)
		|| !ft_strncmp(del, "PS2", -1) || !ft_strncmp(del, "MAILCHECK", -1)
		|| !ft_strncmp(del, "IF", -1) || !ft_strncmp(del, "PPID", -1))
		return ;
	if (envp && del)
	{
		while (envp[i] && ft_strncmp(envp[i], del, -1) != '=')
			i++;
		if (envp[i])
		{
			while (envp[i])
			{
				envp[i] = envp[i + 1];
				i++;
			}
		}
	}
}

void	change_in_envp(char **envp, char *change)
{
	int		i;
	int		len;

	if (envp && change)
	{
		len = 0;
		while (change[len] && change[len] != '=')
			len++;
		i = 0;
		while (envp[i] && ft_strncmp(envp[i], change, len + 1))
			i++;
		if (envp[i])
		{
			free(envp[i]);
			envp[i] = ft_strdup(change);
		}
		else
			add_in_envp(&envp, change);
	}
}
