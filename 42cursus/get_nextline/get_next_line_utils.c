/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:45:58 by mmariani          #+#    #+#             */
/*   Updated: 2022/03/25 21:50:02 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	ft_find(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}



int	ft_strlen(const char *str)
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
	// char	*temp;

	str = (char *)malloc (sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1));
	*(str + ft_strlen(s1)) = '\0';
	return (str);
}

char	*ft_strjoin(char *str, char const *buffer)
{
	char	*dest;
	int	size;
	int	len1;
	int	len2;
	int		i;
	int		j;

	i = -1;


	
	len1 = ft_strlen(str);
	len2 = ft_strlen(buffer);
	size = ft_strlen(str) + ft_strlen(buffer);
	if (!str)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
	}
	dest = (char *) malloc (sizeof(char) * (size + 1));//sensei dixit "nondeveallocare!!!"
	if (!dest)
		return (NULL);
	if (str)
		while (++i < len1)
			dest[i] = str[i];
	j = -1;
	while (++j < len2)
		dest[i++] = buffer[j];
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlcpy(char *str, const char *src, size_t size)
{
	size_t	i;

	i = ft_strlen(src);
	if (size != 0)
	{
		while (*src && --size)
			*str++ = *src++;
		*(str) = '\0';
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*str;

	if (!s || len == 0 || start >= (size_t)ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy((char *)str, (const char *)(s + start), len +1);
	return (str);
}