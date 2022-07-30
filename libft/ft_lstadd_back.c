/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:33:20 by dwren             #+#    #+#             */
/*   Updated: 2021/10/12 06:09:45 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)

{
	t_list	*runner;

	if (!new)
		return ;
	runner = ft_lstlast(*lst);
	if (runner)
		runner->next = new;
	else
		*lst = new;
}
