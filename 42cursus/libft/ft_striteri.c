/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:19:46 by mmariani          #+#    #+#             */
/*   Updated: 2022/03/03 11:31:54 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;
	// char	*str;

	i = -1;

	// str = malloc(ft_strlen(s) + 1);
	// if(!str)
	// 	return (NULL);
	while (s[++i] && f != 0)
		(*f)(i,&s[i]);
	// 	str[i] = f(i,s[i]);
	// str[i] = 0;
}