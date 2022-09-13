/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:51:44 by dwren             #+#    #+#             */
/*   Updated: 2022/07/27 13:30:05 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include <signal.h>
# include <sys/types.h>
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
# define END_OF 12

# define COMMAND 20

typedef struct s_lexer_list
{
	char				*content;
	int					type;
	struct s_lexer_list	*next;
}t_lexer_list;

typedef struct s_command_list
{
	char					**content;
	int						type;
	struct s_command_list	*next;
}t_command_list;

typedef struct s_data_shell
{
	char			**envp;
	char			*str;
	char			*status;
	char			*p_id;
	t_lexer_list	*lexer_list;
	t_command_list	*command_list;
}t_data_shell;

t_data_shell	*initialization(char **envp);
t_command_list	*parser(t_lexer_list *lexer_list, t_command_list *command_list, char **envp, char *p_id, char *status);
t_lexer_list	*lexer(char *str, t_lexer_list *lexer_list);

void			add_in_envp(char ***envp, char *new);
//new подавать в виде "NAME=", без символа "$"
char			*get_from_envp(char **envp, char *name);
//name подавать в виде "NAME", без символа "$". Возвращает всё, что после "="
void			del_from_envp(char **envp, char *del);
//del подавать в виде "NAME", без символа "$"
void			change_in_envp(char **envp, char *change);
//change подавать в виде "NAME=", без символа "$"

void			programm_part(t_data_shell *data);

#endif
