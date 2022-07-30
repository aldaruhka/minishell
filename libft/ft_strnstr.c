/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 21:19:25 by dwren             #+#    #+#             */
/*   Updated: 2021/10/08 22:35:18 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	cnt;
	char	*tmp;

	if (needle[0] == 0)
		return ((char *)haystack);
	tmp = (char *)haystack;
	cnt = 0;
	while (*tmp && cnt < len)
	{
		if (*tmp == *needle)
		{
			i = 0;
			while (tmp[i] == needle[i] && needle[i] && tmp[i] && cnt + i < len)
				i++;
			if (!needle[i])
				return (tmp);
		}
		tmp++;
		cnt++;
	}
	return (NULL);
}
