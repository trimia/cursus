/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:29:50 by mmariani          #+#    #+#             */
/*   Updated: 2022/03/01 13:46:35 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	char	*str;

	str=(char	*)haystack;
	n = ft_strlen(needle);
	if (*needle == '\0' || haystack == needle)
		return ((char *)haystack);
	// haystack--;
	while (len-- && *haystack && *needle)
	{
		if (*haystack == *needle && len >= n)
			if (!(ft_strncmp(haystack, needle,n)))
				return ((char *)(haystack));
		haystack++;
	}
	return (NULL);
}

// int main()
// {
// 	char haystack[30] = "aaabcabcd";
// 	printf("%s\n",ft_strnstr(haystack, "cd", 8));
// 	// printf("%s\n",ft_strnstr(haystack, "a", -1));
// 	// printf("%s\n", ft_strnstr(haystack, "a", 1));

// }