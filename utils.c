/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:54:34 by dwren             #+#    #+#             */
/*   Updated: 2022/08/02 14:00:17 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	shell_ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!ft_strncmp(s1, s2, n))
		return (1);
	return (0);
}

int	shell_perror(const char *s)
{
	int	check;

	check = errno;
	if (errno)
	{
		perror(s);
		errno = 0;
	}
	return (check);
}

void	shell_dup2(int fd_old, int fd_new, char *message_if_error)
{
	if (dup2(fd_old, fd_new) == -1)
		exit(shell_perror(message_if_error));
}

void	shell_pipe(int one_pipe[2], char *message_if_error)
{
	if (pipe(one_pipe) == -1)
		exit(shell_perror(message_if_error));
}

int	shell_fork(char *message_if_error)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		exit(shell_perror(message_if_error));
	return (pid);
}
