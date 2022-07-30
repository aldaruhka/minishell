/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:15:12 by dwren             #+#    #+#             */
/*   Updated: 2021/10/09 04:47:13 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst_tmp;
	const char	*src_tmp;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dst_tmp = dst;
	src_tmp = src;
	while (i < n)
	{
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	return (dst);
}
