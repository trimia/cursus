/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:45:58 by mmariani          #+#    #+#             */
/*   Updated: 2022/03/16 20:35:57 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_find(char *str, int c)
{
	unsigned char k;
	int i;
	
	k = c;
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

void ft_memcpy(char *line_n, char *temp)
{
	while (*line_n  != '\n')
		*temp++ = *line_n++;
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
	dest = (char *) malloc (sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	if (str)
	{
		while (len1--)
			*dest++ = *str++;
		free (str);
	}
	while (len2--)
		*dest++ = *buffer++;
	*dest = '\0';
	return (dest - size);
}