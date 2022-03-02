/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:19:46 by mmariani          #+#    #+#             */
/*   Updated: 2022/03/02 13:22:33 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;
	char	*str;

	i = -1;
	if (!s || !f)
		return (NULL);
	str = malloc(ft_strlen(s) + 1);
	if(!str)
		return (NULL);
	while (s[++i])
		str[i] = f(i,s[i]);
	str[i] = 0;
}