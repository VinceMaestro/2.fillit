/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:35:09 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/04 00:53:20 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*first;

	first = NULL;
	if (lst && f)
	{
		new = f(lst);
		while (lst->next)
		{
			if (first == NULL)
				first = new;
			new->next = f(lst->next);
			new = new->next;
			lst = lst->next;
		}
	}
	return (first);
}
