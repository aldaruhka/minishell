/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 03:10:12 by dwren             #+#    #+#             */
/*   Updated: 2021/10/09 21:12:09 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_len_of_array(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static void	ft_free_alloc_mem(char **result, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (result[i])
			free(result[i]);
		i++;
	}
	if (result)
		free(result);
}

static char	**ft_create_array(char **result, const char *s, char c, size_t k)
{
	size_t	start_new_line;
	size_t	len;

	start_new_line = 0;
	k = 0;
	while (s[start_new_line])
	{
		while (s[start_new_line] && s[start_new_line] == c)
			start_new_line++;
		len = 0;
		while (s[start_new_line + len] && s[start_new_line + len] != c)
			len++;
		if (s[start_new_line])
		{
			result[k] = ft_substr(s, start_new_line, len);
			if (!result[k++])
			{
				ft_free_alloc_mem(result, k - 1);
				return (NULL);
			}
		}
		start_new_line += len;
	}
	result[k] = NULL;
	return (result);
}

char	**ft_split(const char *s, char c)
{
	size_t	arr_size;
	char	**result;

	if (!s)
		return (NULL);
	arr_size = ft_len_of_array(s, c);
	result = malloc(sizeof(char *) * (arr_size + 1));
	if (!result)
		return (NULL);
	return (ft_create_array(result, s, c, 0));
}
