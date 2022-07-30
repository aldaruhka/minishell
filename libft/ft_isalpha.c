/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:31:25 by dwren             #+#    #+#             */
/*   Updated: 2021/10/26 13:04:49 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isupper(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	return (0);
}

static int	ft_islower(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	return (ft_isupper(c) + ft_islower(c));
}
