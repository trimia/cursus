/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimia <trimia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:19:32 by mmariani          #+#    #+#             */
/*   Updated: 2022/02/25 23:45:21 by trimia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (s == NULL)
		if (*(char *)s++)
			;
	--s;
	while (--n && ++s)
		if (*(unsigned char *)(s) == (unsigned char)c)
			return ((void *)(s));
	return (NULL);
}
