/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:51:44 by dwren             #+#    #+#             */
/*   Updated: 2022/08/02 20:58:51 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <sys/types.h>
# include <sys/errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>

# define SEP 1
# define WORD 2
# define FIELD 3
# define EXP_FIELD 4
# define REDIR_FROM 5
# define REDIR_IN 6
# define REDIR_APPEND 7
# define HEREDOC 8
# define PIPE 9
# define IF_AND 10
# define IF_OR 11
# define PROGRAMM 100
# define ECHO 101

typedef struct s_programm
{
	char				*programm_path;
	char				**programm_argv;
	char				**programm_envp;
	struct s_programm	*next;
}t_programm;

typedef struct s_lexer_list
{
	char				**content;
	char				type;
	struct s_lexer_list	*next;
}t_lexer_list;

//ниже наши функции из subject

void			echo(char **argv);

//ниже функции из старого проекта pipex Эльдара. У Эльдара на доработке

void			open_fd_for_read(char *argv[], int *fd);
void			open_fd_for_write(int argc, char *argv[], int *fd);

int				found_in_envp_path(char *envp[]);
char			*take_path(char **path, char *prog_name);

void			wait_for_all_execve(t_programm *programms);
void			free_splited_argv(char **s);
int				free_arguments_for_execve(t_programm *programms);
t_programm		*create_arguments_for_execve(int argc,
					char **paths, char *argv[], char *envp[]);

void			do_one_prog(int one_pipe[2], char *path,
					char **prog, char *envp[]);

int				shell_ft_strncmp(const char *s1, const char *s2, size_t n);
int				shell_perror(const char *s);
void			shell_dup2(int fd_old, int fd_new, char *message_if_error);
void			shell_pipe(int one_pipe[2], char *message_if_error);
int				shell_fork(char *message_if_error);

#endif