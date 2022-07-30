/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:12:23 by dwren             #+#    #+#             */
/*   Updated: 2021/10/10 22:38:15 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	len;

	if (!s || fd < 0)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
		ft_putchar_fd (s[i++], fd);
}
