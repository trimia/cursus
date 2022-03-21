/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:45:58 by mmariani          #+#    #+#             */
/*   Updated: 2022/03/21 21:27:29 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_find(char *str)
{
	unsigned char k;
	int i;
	
	k = '\n';
	i = 0;
	while (str[i] != k)
		if (!str[i++])
			return (NULL);
	return ((char *)&str[i]);
	// while(*str++ != k);
	// 	if  (!*str)
	// 		return (NULL);
	// return (str);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

// void ft_memcpy(char *s1, char *s2)
// {
// 	while (*s1  != '\n')
// 		*s2++ = *s1++;
// }



void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str_dst;
	unsigned char	*str_src;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	str_dst = (unsigned char *)dst;
	str_src = (unsigned char *)src;
	while (n--)
		*str_dst++ = *str_src++;
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = (char *)malloc (sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1));
	*(str + ft_strlen(s1)) = '\0';
	return (str);
}
char	*ft_strjoin(char *str, char const *buffer)
{
	char	*dest;
	size_t	size;
	size_t	len1;
	size_t	len2;

	
	len1 = ft_strlen(str);
	len2 = ft_strlen(buffer);
	size = ft_strlen(str) + ft_strlen(buffer);
	dest = ft_strdup("");
	// dest = (char *) malloc (sizeof(char) * (size + 1));//sensei dixit "nondeveallocare!!!"
	// if (!dest)
	// 	return (NULL);
	if (str)
	{
		while (len1--)
			*dest++ = *str++;
		//free (str);
	}
	while (len2--)
		*dest++ = *buffer++;
	*dest = '\0';
	return (dest - size);
}
