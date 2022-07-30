/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 22:37:07 by dwren             #+#    #+#             */
/*   Updated: 2021/11/10 17:46:23 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_check_contr_symb(char c)
{
	if (c == '\t' || c == '\v' || c == '\f'
		|| c == '\r' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned long	number;

	sign = 1;
	while (ft_check_contr_symb(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	number = 0;
	while ((unsigned char)*str >= '0' && (unsigned char)*str <= '9')
	{
		number = number * 10 + ((unsigned char)*str - '0');
		str++;
		if (sign == 1 && number > 2147483647)
			return (-1);
		if (sign == -1 && number > 2147483648)
			return (0);
	}
	return (number * sign);
}
