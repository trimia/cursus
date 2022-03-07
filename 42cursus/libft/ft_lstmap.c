/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:33:33 by mmariani          #+#    #+#             */
/*   Updated: 2022/03/07 19:43:02 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*newlst;

	newlst = ft_lstnew(f(lst->content));
	lst = lst->next;
	if (!(newlst))
	{
		ft_lstclear(&lst, del);
		return (0);
	}
	while (lst != NULL)
	{	
		temp = ft_lstnew(f(lst->content));
		if (!(temp))
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&newlst, del);
			return (0);
		}
		ft_lstadd_back(&newlst,temp);
		lst = lst->next;
	}
	return (newlst);
}
