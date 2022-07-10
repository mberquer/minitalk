/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:26:23 by mberquer          #+#    #+#             */
/*   Updated: 2021/12/13 14:37:37 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*tmp;

	nlst = NULL;
	if (lst)
	{
		while (lst)
		{
			tmp = ft_lstnew(lst -> content);
			if (!tmp)
			{
				ft_lstclear(&nlst, del);
				return (NULL);
			}
			tmp -> content = f(tmp -> content);
			ft_lstadd_back(&nlst, tmp);
			lst = lst -> next;
		}
		return (nlst);
	}
	return (NULL);
}
