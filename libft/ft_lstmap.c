/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:23:40 by dtelega           #+#    #+#             */
/*   Updated: 2016/12/06 20:06:39 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*res;

	if (!lst || !f || !(tmp = (t_list *)malloc(sizeof(*tmp))))
		return (NULL);
	tmp = f(lst);
	free(lst);
	res = tmp;
	while (lst->next)
	{
		if (!(tmp->next = (t_list *)malloc(sizeof(*tmp))))
			return (NULL);
		tmp->next = f(lst->next);
		tmp = tmp->next;
		free(lst);
		lst = lst->next;
	}
	tmp->next = NULL;
	return (res);
}
