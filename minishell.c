/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:41:22 by dwren             #+#    #+#             */
/*   Updated: 2022/07/27 17:25:35 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*s;

	(void)argc;
	(void)argv;
	(void)envp;
	(void)s;
	rl_clear_history();
	s = readline("what is there?");
	printf("%s\n", s);
	return (0);
}
