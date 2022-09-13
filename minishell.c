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

char	*ft_readline(char *str)
{
	str = readline("minishell:");
	if (str != NULL)
		add_history(str);
	return(str);
}

void	preparser(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			flag++;
			while (str[i] != '\'' && str[i])
				i++;
			if (str[i] == '\'')
					flag++;
		}
		if (str[i] == '\"')
		{
			i++;
			flag++;
			while (str[i] != '\"' && str[i])
				i++;
			if (str[i] == '\"')
					flag++;
		}
		i++;
	}
	if (flag % 2 == 1)
	{
		printf("ERROR : Unclosed quotes\n");
		exit(1);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data_shell		*data_list;

	(void)argc;
	(void)argv;
	data_list = initialization(envp);
	(void)envp;
	printf("\n\n\n");
	change_in_envp(data_list->envp, "_=zhopa");
	change_in_envp(data_list->envp, "_=kek");
	change_in_envp(0, 0);
	for (int i=0;data_list->envp[i];i++)
		printf("%s\n", data_list->envp[i]);
	/*while (1)
	{
		t_command_list *lst = data_list->command_list;
		while (lst)
		{
			for(int i=0;lst->content && lst->content[i];i++)
				printf("%s ", lst->content[i]);
			printf("\n");
			lst = lst->next;
		}
		data_list->str = ft_readline(data_list->str);
		preparser(data_list->str);
		data_list->lexer_list = lexer(data_list->str, data_list->lexer_list);
		data_list->command_list = parser(data_list->lexer_list, data_list->command_list, data_list->envp, data_list->p_id, data_list->status);
		if (data_list != NULL)
			programm_part(data_list);
	}*/
	return (0);
}
