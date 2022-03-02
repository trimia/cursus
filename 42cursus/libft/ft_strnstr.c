/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimia <trimia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:29:50 by mmariani          #+#    #+#             */
/*   Updated: 2022/03/01 22:05:08 by trimia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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
char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len=ft_strlen(needle);    
	int		i;             
	
	if (*needle == '\0')   // needle가 NULL이라면 바로 haystack문자열 반환
		  return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < (int)(len - needle_len))  // 널을 만나기 전까지 루프, 그리고 정해진 len안에서 루프를 반복하는 것이므로 i < len인데 여기서 같은 문자가 마지막에 있으면 문제가 생긴다.
	{
		if (haystack[i] == needle[0]) // 만약 빅을 돌때 needle과 같다면
			if (!ft_strncmp(haystack + i, needle, needle_len)) //strncmp를 사용해서 0을 반환할지 아닐지 정함
				return ((char *)(haystack + i)); //같다면 같은 문자열부터 반환
		i++;
	}
	return (NULL); //아니라면 NULL
}

// int main()
// {
// 	char haystack[30] = "aaabcabcd";
// 	printf("%s\n",ft_strnstr(haystack, "cd", 8));
// 	// printf("%s\n",ft_strnstr(haystack, "a", -1));
// 	// printf("%s\n", ft_strnstr(haystack, "a", 1));

// }