/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:33:41 by dwren             #+#    #+#             */
/*   Updated: 2021/10/06 16:40:26 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t			i;
	unsigned char	*s;

	s = dest;
	i = 0;
	while (i < len)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return ((void *)s);
}
