#include "minishell.h"

char	*ft_getpid()
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		exit(1);
	}
	if (!pid)
	{
		exit(1);
	}
	waitpid(pid, NULL, 0);
	pid = pid - 1;
	return (ft_itoa(pid));
}

t_data_shell	*initialization(t_data_shell *data_list, char **envp)
{
	data_list = malloc(sizeof(t_data_shell) * 1);
	if(!data_list)
		return (NULL);
	data_list->lexer_list = NULL;
	data_list->command_list = NULL;
	data_list->envp = envp;
	data_list->status =	"0";
	data_list->str = NULL;
	data_list->p_id = ft_getpid();
	return(data_list);
}
