/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 00:44:41 by dwren             #+#    #+#             */
/*   Updated: 2021/10/09 17:47:19 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (start > i)
	{
		tmp = malloc(1);
		tmp[0] = 0;
		return (tmp);
	}
	if (len > i - start)
		len = i - start;
	tmp = malloc(len + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}
