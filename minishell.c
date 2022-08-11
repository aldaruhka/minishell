/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:41:22 by dwren             #+#    #+#             */
/*   Updated: 2022/08/02 22:55:27 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

void	main_work(t_lexer_list *s)
{
	while (s != NULL)
	{
		if (s->type == ECHO)
			echo(s->content);
		if (s->type == PIPE)
			(void);
		if (s->type == REDIR_IN)
			(void)s;
		if (s->type == PROGRAMM)
			(void)s;
		s = s->next;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_lexer_list	*s;

	(void)argc;
	(void)argv;
	(void)envp;
	s = malloc(sizeof(t_lexer_list));
	s->content = (char *[]){"echo", "-n", "My job is epic!", NULL};
	s->type = ECHO;
	s->next = malloc(sizeof(t_lexer_list));

	s->next->content = (char *[]){NULL};
	s->next->type = PIPE;
	s->next->next = malloc(sizeof(t_lexer_list));

	s->next->next->content = (char *[]){"grep", "job", NULL};
	s->next->next->type = PROGRAMM;
	s->next->next->next = malloc(sizeof(t_lexer_list));

	/*s->next->next->next->content = (char *[]){"my_file"};
	s->next->next->next->type = WRITE_IN_FILE;
	s->next->next->next->next = NULL;*/

	SIGWINCH
	main_work(s);
	return (0);
	//
}
