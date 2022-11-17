/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:37:28 by masebast          #+#    #+#             */
/*   Updated: 2022/01/25 13:34:07 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_node;

	if (lst != NULL)
	{
		last_node = lst;
	}
	else
	{
		return (NULL);
	}
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	return (last_node);
}
