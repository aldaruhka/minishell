/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:48:22 by dwren             #+#    #+#             */
/*   Updated: 2021/10/10 22:36:58 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_change_sign(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	ft_put(int n, int fd)
{
	if (n / 10 == 0)
		ft_putchar_fd(ft_change_sign(n) + '0', fd);
	else
	{
		ft_put(n / 10, fd);
		ft_putchar_fd(ft_change_sign(n % 10) + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_put(n, fd);
}
