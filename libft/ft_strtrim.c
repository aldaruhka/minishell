/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:30:18 by dwren             #+#    #+#             */
/*   Updated: 2021/10/12 01:07:56 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_presence(char c, const char *s)
{
	while (*s && *s != c)
		s++;
	if (*s == c)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	finish;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_check_presence(s1[start], set))
		start++;
	finish = ft_strlen(s1);
	while (finish > start && ft_check_presence(s1[finish], set))
		finish--;
	result = ft_substr(s1, start, finish - start + 1);
	if (!result)
		return (NULL);
	return (result);
}
