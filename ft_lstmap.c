/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:13:55 by mde-lang          #+#    #+#             */
/*   Updated: 2022/11/24 20:58:59 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*list;
	t_list	*new_element;

	if (!lst || !f)
		return (0);
	new_element = 0;
	while (lst)
	{
		tmp = (f(lst->content));
		list = ft_lstnew(tmp);
		if (!list)
		{
			free(tmp);
			ft_lstclear(&new_element, del);
			return (0);
		}
		ft_lstadd_back(&new_element, list);
		lst = lst->next;
	}
	return (new_element);
}
