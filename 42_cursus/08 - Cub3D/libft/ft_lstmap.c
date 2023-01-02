/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 04:26:29 by ebondi            #+#    #+#             */
/*   Updated: 2022/01/19 15:53:36 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*newlist;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst -> content));
	newlist = new;
	lst = lst -> next;
	while (lst)
	{
		new = ft_lstnew(f(lst -> content));
		if (!new)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&newlist, del);
			return (0);
		}
		lst = lst -> next;
		ft_lstadd_back(&newlist, new);
	}
	return (newlist);
}
