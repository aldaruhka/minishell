/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 03:46:44 by dwren             #+#    #+#             */
/*   Updated: 2022/08/02 14:00:19 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	found_in_envp_path(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	return (i);
}

char	*take_path(char **path, char *prog_name)
{
	int		i;
	char	*full_path;

	i = 0;
	while (path[i])
	{
		full_path = ft_strjoin(path[i], "/");
		full_path = ft_strjoin(full_path, prog_name);
		if (!access(full_path, F_OK))
		{
			errno = 0;
			return (full_path);
		}
		free(full_path);
		i++;
	}
	errno = 0;
	return (0);
}
