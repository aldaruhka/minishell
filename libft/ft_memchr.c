/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:35:23 by dwren             #+#    #+#             */
/*   Updated: 2021/10/12 06:10:14 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (*tmp != (unsigned char)c && n > 0)
	{
		n--;
		if (!*tmp)
			break ;
		tmp++;
	}
	if (*tmp == (unsigned char)c && n != 0)
		return (tmp);
	return (NULL);
}
