/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:22:11 by dwren             #+#    #+#             */
/*   Updated: 2021/10/10 22:50:58 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copy_str(char *result, const char *s1, size_t *i)
{
	while (s1 && *s1)
	{
		result[*i] = *s1;
		(*i)++;
		s1++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*result;
	size_t	size;

	size = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1)
		size += ft_strlen(s1);
	if (s2)
		size += ft_strlen(s2);
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	i = 0;
	ft_copy_str(result, s1, &i);
	ft_copy_str(result, s2, &i);
	result[i] = 0;
	return (result);
}
