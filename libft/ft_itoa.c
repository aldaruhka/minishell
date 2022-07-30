/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:52:17 by dwren             #+#    #+#             */
/*   Updated: 2021/10/10 19:06:28 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_change_sign(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	ft_create_arr(char *result, int start, int len, int n)
{
	while (len >= start)
	{
		result[len] = ft_change_sign(n % 10) + '0';
		len--;
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	int		tmp;
	char	*result;

	len = 1;
	if (n < 0)
		len++;
	tmp = n;
	while (tmp / 10 != 0)
	{
		tmp = tmp / 10;
		len++;
	}
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len--] = 0;
	tmp = 0;
	if (n < 0)
		result[tmp++] = '-';
	ft_create_arr(result, tmp, len, n);
	return (result);
}
