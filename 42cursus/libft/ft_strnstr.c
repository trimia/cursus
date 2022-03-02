/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:29:50 by mmariani          #+#    #+#             */
/*   Updated: 2022/03/02 10:57:25 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	size_t	n;
// 	int		i;
// 	char	*str;

// 	i = -1;
// 	str=(char	*)haystack;
// 	n = ft_strlen(needle);
// 	int a =len-n;
// 	if (*needle == '\0' || haystack == needle)
// 		return ((char *)haystack);
// 	while (a-- && haystack[++i] && *needle)
// 		if (haystack[i] == needle[0])
// 			if (!(ft_strncmp(haystack + i, needle, n)))
// 				return ((char *)(haystack + i));
// 	return (NULL);
// }

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;

	i = -1;
	if (*needle == '\0' || needle == NULL)
		return ((char*)haystack);
	if ((int)len == -1)
		len = ft_strlen(haystack);
	while (haystack[++i] != '\0' && i < (int)len)
	{
		j=-1;
		while (i + (++j) < (int)len && needle[j] == haystack[i + j])
			if (needle[j + 1] == '\0')
				return ((char*)haystack + i);
	}
	return (NULL);
}

// int main()
// {
// 	char haystack[30] = "aaabcabcd";
// 	printf("4\n%s\n",ft_strnstr(haystack, "c", -1));
// 	printf("10\n%s",ft_strnstr(haystack, "abcd", 9));
// 	// printf("%s\n", ft_strnstr(haystack, "a", 1));

// }