/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:29:50 by mmariani          #+#    #+#             */
/*   Updated: 2022/01/26 23:30:15 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;

	n = ft_strlen(needle);
	if (*needle == '\0' || haystack == needle)
		return ((char *)haystack);
	haystack--;
	while (len-- && *(++haystack) && *needle)
		if (*haystack == *needle && len > n)
			if (!(ft_strncmp(haystack, needle, n)))
				return ((char *)(haystack));
	return (NULL);
}
