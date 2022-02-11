/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:45:18 by mmariani          #+#    #+#             */
/*   Updated: 2022/01/20 12:53:25 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cazzo;

	cazzo = (char *)s;
	s += ft_strlen(s);
	if (c == 0)
		return ((char *)s);
	while (--s >= cazzo)
	{
		if (*s == (char)c)
			return ((char *)s);
	}
	return (NULL);
}
