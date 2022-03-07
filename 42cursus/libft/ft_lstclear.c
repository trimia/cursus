/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:12:00 by mmariani          #+#    #+#             */
/*   Updated: 2022/03/07 19:55:11 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *dripa;
	if(lst)
	{
		while (lst != NULL)
		{	
			dripa = (*lst)->next;
			ft_lstdelone(*lst,del);
			*lst = dripa;
		}
	}
}
