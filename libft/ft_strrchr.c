/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:55:57 by dwren             #+#    #+#             */
/*   Updated: 2021/10/08 19:05:06 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *)s;
	while (*tmp)
		tmp++;
	while (tmp != s && *tmp != (char)c)
		tmp--;
	if (*tmp == (char)c)
		return (tmp);
	return (NULL);
}
