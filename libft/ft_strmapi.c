/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:54:26 by dwren             #+#    #+#             */
/*   Updated: 2021/10/10 20:30:13 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	tmp = malloc(len + 1);
	if (!tmp)
		return (NULL);
	tmp[len] = 0;
	i = 0;
	while (i < len)
	{
		tmp[i] = f(i, s[i]);
		i++;
	}
	return (tmp);
}
