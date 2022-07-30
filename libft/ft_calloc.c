/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 23:50:02 by dwren             #+#    #+#             */
/*   Updated: 2021/10/09 17:29:22 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;
	size_t	i;

	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < count * size)
		tmp[i++] = 0;
	return (tmp);
}
