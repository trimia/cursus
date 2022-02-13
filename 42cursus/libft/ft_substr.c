/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimia <trimia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:24:13 by trimia            #+#    #+#             */
/*   Updated: 2022/02/13 16:10:49 by trimia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	//size_t	*a;
	str = ft_strdup(s + start);

	while (len--)
		*str++ = str++;
	*str='\0';
	return (str);
}