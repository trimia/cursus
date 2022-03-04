/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:29:50 by mmariani          #+#    #+#             */
/*   Updated: 2022/03/04 11:06:39 by mmariani         ###   ########.fr       */
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
// 	int a =len-n + 1;
// 	if (haystack == NULL)
// 		return ((char *)needle);
// 	if (needle == NULL || n == 0)
// 		return ((char *)haystack);
// 	while (--a && haystack[++i] && *needle)
// 		if (haystack[i] == needle[0])
// 			if (!(ft_strncmp(haystack + i, needle, n)))
// 				return ((char *)(haystack + i));
// 	return (NULL);
// }

// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	int		i;
// 	int		j;

// 	i = -1;
// 	if (*needle == '\0' || needle == NULL)
// 		return ((char*)haystack);
// 	if ((int)len == -1)
// 		len = ft_strlen(haystack);
// 	while (haystack[++i] != '\0' && i < (int)len)
// 	{
// 		j=-1;
// 		while (i + (++j) < (int)len && needle[j] == haystack[i + j])
// 			if (needle[j + 1] == '\0')
// 				return ((char*)haystack + i);
// 	}
// 	return (NULL);
// }

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t  little_len;    
    size_t	i;             

	little_len = ft_strlen(little);
    if (*little == '\0')   // little가 NULL이라면 바로 big문자열 반환
        return ((char *)big);
    i = 0;                
    while (big[i] != '\0' && i < len)  // 널을 만나기 전까지 루프, 그리고 정해진 len안에서 루프를 반복하는 것이므로 i < len인데 여기서 같은 문자가 마지막에 있으면 문제가 생긴다.
    {
        if (big[i] == little[0]) // 만약 빅을 돌때 little과 같다면
            if (!ft_strncmp(big + i, little, little_len)) //strncmp를 사용해서 0을 반환할지 아닐지 정함
                return ((char *)(big + i)); //같다면 같은 문자열부터 반환
        i++;
    }
    return (NULL); //아니라면 NULL
}

// int main()
// {
// 	char haystack[30] = "aaabcabcd";
// 	// printf("8\n%s\n",ft_strnstr(haystack, "aaabc", 5));
// 	// printf("10\n%s",ft_strnstr(haystack, "abcd", 9));
// 	printf("2\n%s",ft_strnstr(haystack, "cd", 8));
// 	// printf("3\n%s",ft_strnstr(haystack, "c", -1));
// 	// printf("4\n%s",ft_strnstr(empty, "", -1); 
// 	// printf("%s\n", ft_strnstr(haystack, "a", 1));

// }