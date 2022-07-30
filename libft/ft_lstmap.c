/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:34:35 by dwren             #+#    #+#             */
/*   Updated: 2021/10/12 06:10:01 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_check_for_f(t_list *lst, void *(*f)(void *))
{
	if (f)
		return (ft_lstnew(f(lst->content)));
	return (ft_lstnew(lst->content));
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*new;
	t_list	*prev;

	if (!lst)
		return (NULL);
	start = NULL;
	prev = NULL;
	while (lst)
	{
		new = ft_check_for_f(lst, f);
		if (!start)
			start = new;
		if (!new)
		{
			if (del)
				ft_lstclear(&start, del);
			return (NULL);
		}
		if (prev)
			prev->next = new;
		prev = new;
		lst = lst->next;
	}
	return (start);
}
