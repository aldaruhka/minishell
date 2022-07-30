/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:29:34 by dwren             #+#    #+#             */
/*   Updated: 2021/10/09 04:35:16 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_tmp;
	const char	*src_tmp;

	if (dst > src)
	{
		dst_tmp = dst;
		src_tmp = src;
		while (len-- > 0)
			dst_tmp[len] = src_tmp[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
