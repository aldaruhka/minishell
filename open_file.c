/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 03:59:24 by dwren             #+#    #+#             */
/*   Updated: 2022/08/02 14:00:37 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	open_file(char *argv, int *fd)
{
	*fd = open(argv, O_RDONLY);
	if (shell_perror(argv))
		return ;
	read(*fd, 0, 0);
	if (shell_perror(argv))
	{
		close(*fd);
		*fd = -1;
	}
}

static void	here_doc(char *argv[], int *fd)
{
	char	*buff;

	buff = 0;
	*fd = open("Temporary_file", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (shell_perror(argv[0]))
		return ;
	argv[2] = ft_strjoin(argv[2], "\n");
	if (shell_perror(argv[0]))
		return ;
	while (1)
	{
		free(buff);
		ft_putstr_fd("heredoc> ", 1);
		buff = get_next_line(0);
		if (buff && ft_strncmp(argv[2], buff, -1))
			write(*fd, buff, ft_strlen(buff));
		else
		{
			free(buff);
			free(argv[2]);
			close(*fd);
			*fd = open("Temporary_file", O_RDONLY | O_CREAT, 0644);
			return ;
		}
	}
}

void	open_fd_for_read(char *argv[], int *fd)
{
	if (ft_strncmp(argv[1], "here_doc", 10))
		open_file(argv[1], fd);
	else
		here_doc(argv, fd);
}

void	open_fd_for_write(int argc, char *argv[], int *fd)
{
	if (!ft_strncmp(argv[1], "here_doc", 10))
		*fd = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		*fd = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (shell_perror(argv[argc - 1]))
		return ;
	write(*fd, 0, 0);
	if (shell_perror(argv[argc - 1]))
	{
		close(*fd);
		*fd = -1;
	}
}
