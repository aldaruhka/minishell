/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:56:02 by dwren             #+#    #+#             */
/*   Updated: 2022/08/02 14:09:07 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prog_part(t_programm *programms, char *argv, int pid)
{
	if (!pid)
	{
		execve(programms->programm_path, programms->programm_argv,
			programms->programm_envp);
		ft_putstr_fd(argv, 2);
		if (programms && programms->programm_argv)
		{
			ft_putstr_fd(": command not found: ", 2);
			ft_putendl_fd(programms->programm_argv[0], 2);
		}
		else
			ft_putendl_fd(": allocated memory error", 2);
		exit(0);
	}
	else if (!programms->programm_path)
		wait(0);
}

void	first_prog(char *argv[], t_programm *programms)
{
	int	pid;
	int	fd;
	int	first_pipe[2];

	open_fd_for_read(argv, &fd);
	shell_pipe(first_pipe, argv[0]);
	if (fd == -1)
	{
		shell_perror(argv[1]);
		close(first_pipe[1]);
		shell_dup2(first_pipe[0], 0, argv[0]);
		return ;
	}
	shell_dup2(fd, 0, argv[0]);
	shell_dup2(first_pipe[1], 1, argv[0]);
	pid = shell_fork(argv[0]);
	prog_part(programms, argv[0], pid);
	close(first_pipe[1]);
	shell_dup2(first_pipe[0], 0, argv[0]);
}

int	middle_progs(t_programm *programms, char *prog_name)
{
	int	pid;
	int	tmp_pipe[2];

	pid = 0;
	while (programms->next)
	{
		shell_pipe(tmp_pipe, prog_name);
		pid = shell_fork(prog_name);
		if (!pid)
		{
			shell_dup2(tmp_pipe[1], 1, prog_name);
			close(tmp_pipe[0]);
		}
		prog_part(programms, prog_name, pid);
		close(tmp_pipe[1]);
		shell_dup2(tmp_pipe[0], 0, prog_name);
		programms = programms->next;
	}
	return (pid);
}

void	last_prog(int argc, char *argv[], t_programm *programms)
{
	int	pid;
	int	fd;

	open_fd_for_write(argc, argv, &fd);
	if (fd == -1)
	{
		close(1);
		return ;
	}
	shell_dup2(fd, 1, argv[0]);
	while (programms->next)
		programms = programms->next;
	pid = shell_fork(argv[0]);
	if (pid == 0)
		shell_dup2(fd, 1, argv[0]);
	prog_part(programms, argv[0], pid);
}

/*int	main(int argc, char *argv[], char *envp[])
{
	char		**paths;
	t_programm	*programms;

	if (argc < 5 || (argc < 6 && !ft_strncmp(argv[1], "here_doc", 10)))
	{
		ft_putstr_fd(argv[0], 2);
		ft_putendl_fd(": Invalid number of arguments", 2);
		return (0);
	}
	paths = ft_split(envp[found_in_envp_path(envp)] + 5, ':');
	programms = create_arguments_for_execve(argc, paths, argv, envp);
	free_splited_argv(paths);
	first_prog(argv, programms);
	middle_progs(programms->next, argv[0]);
	last_prog(argc, argv, programms);
	wait_for_all_execve(programms);
	free_arguments_for_execve(programms);
	if (!ft_strncmp(argv[1], "here_doc", 10))
		unlink("Temporary_file");
	exit(0);
}*/
