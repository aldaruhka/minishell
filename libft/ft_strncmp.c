/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:09:03 by dwren             #+#    #+#             */
/*   Updated: 2021/10/09 15:31:52 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_tmp;
	unsigned char	*s2_tmp;

	if (n == 0)
		return (0);
	i = 0;
	s1_tmp = (unsigned char *)s1;
	s2_tmp = (unsigned char *)s2;
	while (s1_tmp[i] && s2_tmp[i] && s1_tmp[i] == s2_tmp[i] && i + 1 < n)
		i++;
	return (s1_tmp[i] - s2_tmp[i]);
}
