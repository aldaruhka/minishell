#include "minishell.h"

t_command_list	*command_list_init()
{
	t_command_list	*tmp;

	tmp = malloc(sizeof(t_command_list));
	if (!tmp)
		return (NULL);
	tmp->content = NULL;
	tmp->type = 0;
	tmp->next = NULL;
	return (tmp);
}

void	command_list_add(t_command_list **command_list, char **str, int type)
{
	t_command_list	*tmp;

	tmp = *command_list;
	if (tmp->content == NULL && tmp->type == 0 && tmp->next == NULL)
	{
		tmp->content = str;
		tmp->type = type;
		tmp->next = NULL;
		return ;
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = malloc(sizeof(t_command_list));
	if (!tmp->next)
		return ;

	tmp->next->content = str;
	tmp->next->type = type;
	tmp->next->next = NULL;
}

void	command_list_pipe_check(t_command_list *command_list)
{
	if (command_list->type == PIPE)
	{
		printf("ERROR: pipe without command\n");
		exit(1);
	}
	while (command_list)
	{
		if (command_list->type == PIPE)
		{
			if (command_list->next == NULL)
			{
				printf("ERROR: pipe without command\n");
				exit(1);
			}
			if (command_list->next->type != COMMAND)
			{
				printf("ERROR: pipe without command\n");
				exit(1);
			}
		}
		command_list = command_list->next;
	}
}

t_command_list	*command_list_command_check(t_command_list *command_list)
{
	t_command_list	*current_list;
	t_command_list	*previous_list;

	previous_list = command_list;
	current_list = command_list;
	if (current_list->type == COMMAND)
	{
		if (current_list->content[0] == NULL)
		{
			command_list = command_list->next;
			current_list = current_list->next;
			free(previous_list);
			previous_list = current_list;
		}
	}
	current_list = current_list->next;
	while (current_list)
	{
		if (current_list->type == COMMAND)
		{
			if (current_list->content[0] == NULL)
			{
				previous_list->next = current_list->next;
				free(current_list);
				current_list = previous_list;
				current_list = current_list->next;
			}
		}
		if (current_list)
		{
			current_list = current_list->next;
			previous_list = previous_list->next;
		}
	}
	return (command_list);
}

char	*find_value(char *key, char **envp)
{
	int		i;
	int		key_len;
	char	*str;

	str = NULL;
	key_len = ft_strlen(key);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], key, key_len) == 0 && envp[i][key_len] == '=')
		{
			str = ft_substr(envp[i], key_len + 1, ft_strlen(envp[i]) - (key_len + 1));
			free(key);
			return(str);
		}
		i++;
	}
	return(str);
}

void	check_env_var(t_lexer_list **lexer_list, char **envp, char *p_id, char *status)
{
	t_lexer_list	*tmp;
	int				i;
	int				j;
	char			*str;
	char			*tmp_str;

	tmp_str = NULL;
	str = NULL;
	i = 0;
	j = 0;
	tmp = *lexer_list;
	while(tmp->type != END_OF)
	{
		if (tmp->type == WORD || tmp->type == EXP_FIELD)
		{
			while (tmp->content[i] != '\0')
			{
				if (tmp->content[i] == '$' || j > 0)
				{
					if (tmp->content[i] == '$' && ft_isalnum(tmp->content[i + 1]))
					{
						tmp_str = ft_substr(tmp->content, j, i - j);
						str = ft_strjoin(str, tmp_str);
						free(tmp_str);
						i++;
						j = i;
						while (ft_isalnum(tmp->content[i + 1]))
							i++;
						tmp_str = ft_substr(tmp->content, j, i + 1 - j);
						tmp_str = find_value(tmp_str, envp);
						str = ft_strjoin(str, tmp_str);
						free(tmp_str);
						j = i + 1;
					}
					else if (tmp->content[i] == '$' && tmp->content[i + 1] == '$')
					{
						tmp_str = ft_substr(tmp->content, j, i - j);
						str = ft_strjoin(str, tmp_str);
						str = ft_strjoin(str, p_id);
						free(tmp_str);
						i++;
						j = i + 1;
					}
					else if (tmp->content[i] == '$' && tmp->content[i + 1] == '?')
					{
						tmp_str = ft_substr(tmp->content, j, i - j);
						str = ft_strjoin(str, tmp_str);
						str = ft_strjoin(str, status);
						free(tmp_str);
						i++;
						j = i + 1;
					}
					else if (tmp->content[i + 1] == '\0' && j > 0)
					{
						tmp_str = ft_substr(tmp->content, j, i + 1 - j);
						str = ft_strjoin(str, tmp_str);
						free(tmp_str);
					}
				}
				i++;
			}
		}
		if (j > 0)
		{
			free(tmp->content);
			tmp->content = str;
		}
		str = NULL;
		i = 0;
		j = 0;
		tmp = tmp->next;
	}
}

void	command_list_first(t_command_list **command_list, t_lexer_list *lexer_list)
{
	t_lexer_list	*tmp_lexer_list;
	t_command_list	*tmp_command_list;

	tmp_command_list = *command_list;
	tmp_lexer_list = lexer_list;
	command_list_add(&tmp_command_list, NULL, COMMAND);
	while (tmp_lexer_list->type != END_OF)
	{
		if (tmp_lexer_list->type == REDIR_APPEND || tmp_lexer_list->type == REDIR_FROM || tmp_lexer_list->type == REDIR_IN || tmp_lexer_list->type == HEREDOC)
		{
			int		redir_var;
			int		i;
			char	**tmp;
			char	*tmp_str;

			tmp_str = NULL;
			i = 0;
			redir_var = tmp_lexer_list->type;
			if (tmp_lexer_list->next->type == SEP)
				tmp_lexer_list = tmp_lexer_list->next;
			tmp_lexer_list = tmp_lexer_list->next;
			if (tmp_lexer_list->type != WORD && tmp_lexer_list->type != FIELD && tmp_lexer_list->type !=EXP_FIELD)
			{
				printf("ERROR : no words after redir\n");
				exit(1);
			}
			tmp = malloc(sizeof(char *) * 2);
			while (tmp_lexer_list->type == WORD || tmp_lexer_list->type == FIELD || tmp_lexer_list->type ==EXP_FIELD)
			{
				i += ft_strlen(tmp_lexer_list->content);
				tmp_str = ft_strjoin(tmp_str, tmp_lexer_list->content);
				tmp_lexer_list = tmp_lexer_list->next;
			}
			tmp[0] = malloc(sizeof(char) * i);
			tmp[0] = tmp_str;
			tmp[1] = NULL;
			command_list_add(&tmp_command_list, tmp, redir_var);
		}
		if (tmp_lexer_list->type == PIPE)
		{
			command_list_add(&tmp_command_list, NULL, PIPE);
			command_list_add(&tmp_command_list, NULL, COMMAND);
		}
		if (tmp_lexer_list->type != END_OF && tmp_lexer_list->type != REDIR_APPEND && tmp_lexer_list->type != REDIR_FROM && tmp_lexer_list->type != REDIR_IN && tmp_lexer_list->type != HEREDOC)
			tmp_lexer_list=tmp_lexer_list->next;
	}
}

void	command_list_second(t_command_list **command_list, t_lexer_list *lexer_list)
{
	t_lexer_list	*tmp_lexer_list;
	t_command_list	*tmp_command_list;
	int				i;
	int				j;
	char			**tmp;

	tmp_command_list = *command_list;
	tmp_lexer_list = lexer_list;
	i = 0;
	j = 0;

	while (tmp_command_list)
	{
		if (tmp_command_list->type == COMMAND)
		{
			while (tmp_lexer_list->type != PIPE && tmp_lexer_list->type != END_OF)
			{
				if (tmp_lexer_list->type == SEP)
				{
					i--;
					tmp_lexer_list = tmp_lexer_list->next;
				}
				else if (tmp_lexer_list->type == REDIR_APPEND || tmp_lexer_list->type == REDIR_FROM || tmp_lexer_list->type == REDIR_IN || tmp_lexer_list->type == HEREDOC)
				{
					i = i - 2;
					tmp_lexer_list = tmp_lexer_list->next;
				}
				else if (tmp_lexer_list->type == WORD || tmp_lexer_list->type == FIELD || tmp_lexer_list->type ==EXP_FIELD)
				{
					while (tmp_lexer_list->type == WORD || tmp_lexer_list->type == FIELD || tmp_lexer_list->type ==EXP_FIELD)
						tmp_lexer_list = tmp_lexer_list->next;
				}
				i++;
			}
			tmp = malloc(sizeof(char *) * (i + 1));
			while (j != i)
			{
				char	*tmp_str;
				int		i1;

				tmp_str = NULL;
				i1 = 0;
				if (lexer_list->type == WORD || lexer_list->type == FIELD || lexer_list->type ==EXP_FIELD)
				{
					while (lexer_list->type == WORD || lexer_list->type == FIELD || lexer_list->type ==EXP_FIELD)
					{
						i1 += ft_strlen(lexer_list->content);
						tmp_str = ft_strjoin(tmp_str, lexer_list->content);
						lexer_list = lexer_list->next;
					}
					tmp[j] = malloc(sizeof(char) * i1);
					tmp[j] = tmp_str;
					j++;
				}
				if (lexer_list->type == SEP)
					lexer_list = lexer_list->next;
				if (lexer_list->type == REDIR_APPEND || lexer_list->type == REDIR_FROM || lexer_list->type == REDIR_IN || lexer_list->type == HEREDOC)
				{
					if (lexer_list->next->type == SEP)
						lexer_list = lexer_list->next;
					lexer_list = lexer_list->next;
					while (lexer_list->type == WORD || lexer_list->type == FIELD || lexer_list->type ==EXP_FIELD)
							lexer_list = lexer_list->next;
				}
				if (lexer_list->type == SEP)
					lexer_list = lexer_list->next;
			}
			tmp[j] = NULL;
			tmp_command_list->content = tmp;
			i = 0;
			j = 0;
			lexer_list = tmp_lexer_list;
			if (tmp_lexer_list->type != END_OF)
			{
				tmp_lexer_list = tmp_lexer_list->next;
				lexer_list = lexer_list->next;
			}
		}
		tmp_command_list = tmp_command_list->next;
	}
}

t_command_list	*parser(t_lexer_list *lexer_list, t_command_list *command_list, char **envp, char *p_id, char *status)
{
	if (lexer_list->next == NULL)
		return (NULL);
	command_list = command_list_init();
	check_env_var(&lexer_list, envp, p_id, status);
	command_list_first(&command_list, lexer_list);
	command_list_second(&command_list, lexer_list);
	command_list = command_list_command_check(command_list);
	command_list_pipe_check(command_list);


	//ЦИКЛ ДЛЯ ВЫВЕДЕНИЯ КОММАНД 

	// int iter = 0;
	// while(command_list)
	// {
	// 	while(command_list->content && command_list->content[iter])
	// 	{
	// 		printf("%s, ",command_list->content[iter]);
	// 		iter++;
	// 	}
	// 	printf("NULL  ");
	// 	printf("%d\n", command_list->type);
	// 	iter = 0;
	// 	command_list = command_list->next;
	// }

	return (command_list);
	// СДЕЛАТЬ FREE FUNC
}
