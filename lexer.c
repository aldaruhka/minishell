#include "minishell.h"

int	ft_isspace(int c)
{
	return (c == '\f' || c == '\n' || c == '\r' \
	|| c == '\t' || c == '\v' || c == ' ');
}

t_lexer_list	*lexer_list_init()
{
	t_lexer_list	*tmp;

	tmp = malloc(sizeof(t_lexer_list));
	if (!tmp)
		return (NULL);
	tmp->content = NULL;
	tmp->type = 0;
	tmp->next = NULL;
	return (tmp);
}

void	lexer_list_add(t_lexer_list **lexer_list, char *str, int type)
{
	t_lexer_list	*tmp;

	tmp = *lexer_list;
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
	tmp->next = malloc(sizeof(t_lexer_list));
	if (!tmp->next)
		return ;

	tmp->next->content = str;
	tmp->next->type = type;
	tmp->next->next = NULL;
}

void	word_lexer_evaluation(t_lexer_list **lexer_list, char *str)
{
	t_lexer_list	*tmp_list;
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = 0;
	tmp_list = *lexer_list;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			if (i - j != 0)
			{
				tmp = ft_substr(str, j, i - j);
				lexer_list_add(&tmp_list, tmp, WORD);
				j = i;
			}
			i++;
			while (str[i] != '\'' && str[i])
				i++;
			tmp = ft_substr(str, j + 1, i - j - 1);
			lexer_list_add(&tmp_list, tmp, FIELD);
			j = i + 1;
		}
		else if (str[i] == '\"')
		{
			if (i - j != 0)
			{
				tmp = ft_substr(str, j, i - j);
				lexer_list_add(&tmp_list, tmp, WORD);
				j = i;
			}
			i++;
			while (str[i] != '\"' && str[i])
				i++;
			tmp = ft_substr(str, j + 1, i - j - 1);
			lexer_list_add(&tmp_list, tmp, EXP_FIELD);
			j = i + 1;
		}
		else if (str[i] == '|' || /*(str[i + 1] == '&' && str[i] =='&') ||*/ str[i] == '<' || str[i] == '>')
		{
			if (i - j != 0)
			{
				tmp = ft_substr(str, j, i - j);
				lexer_list_add(&tmp_list, tmp, WORD);
				j = i + 1;
			}
			if (/*(str[i + 1] == '|' && str[i] =='|') ||  (str[i + 1] == '&' && str[i] =='&') ||*/ (str[i + 1] == '<' && str[i] =='<') || (str[i + 1] == '>'&& str[i] =='>'))
			{
				/*if (str[i] == '|' && str[i + 1] == '|')
					lexer_list_add(&tmp_list, "||", IF_OR);
				else if (str[i] == '&' && str[i + 1] == '&')
					lexer_list_add(&tmp_list, "&&", IF_AND);
				else */if (str[i] == '<' && str[i + 1] == '<')
					lexer_list_add(&tmp_list, "<<", HEREDOC);
				else if (str[i] == '>' && str[i + 1] == '>')
					lexer_list_add(&tmp_list, ">>", REDIR_APPEND);
				i++;
				j = i + 1;
			}
			else
			{
				if (str[i] == '|')
					lexer_list_add(&tmp_list, "|", PIPE);
				else if (str[i] == '>')
					lexer_list_add(&tmp_list, ">", REDIR_IN);
				else if (str[i] == '<')
					lexer_list_add(&tmp_list, "<", REDIR_FROM);
				j = i + 1;
			}
		}
		else if (str[i + 1] == '\0')
		{
			tmp = ft_substr(str, j, i + 1 - j);
			lexer_list_add(&tmp_list, tmp, WORD);
		}
		i++;
	}
}

t_lexer_list	*lexer(char *str, t_lexer_list *lexer_list)
{
	int	i;
	int	j;
	char *tmp;

	if (str == NULL)
		return (NULL);
	i = 0;
	lexer_list = lexer_list_init();
	while (str[i] && str[i] == ' ')
		i++;
	j = i;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'' && str[i])
				i++;
		}
		if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"' && str[i])
				i++;
		}
		if (str[i] == ' ' )
		{
			tmp = ft_substr(str, j, i - j);
			j = i + 1;
			word_lexer_evaluation(&lexer_list, tmp);
			lexer_list_add(&lexer_list, " ", SEP);
		}
		else if (str[i + 1] == '\0' && str[i] != ' ')
		{
			tmp = ft_substr(str, j, i + 1 - j);
			word_lexer_evaluation(&lexer_list, tmp);
		}
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			i++;
			j = i + 1;
		}
		i++;
	}
	lexer_list_add(&lexer_list, "EOF", END_OF);
	// while(lexer_list->content != "EOF")
	// {
	// 	printf("%s %d\n",lexer_list->content, lexer_list->type);
	// 	lexer_list=lexer_list->next;
	// }
	return (lexer_list);
}
