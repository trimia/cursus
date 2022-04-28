/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:49:43 by mmariani          #+#    #+#             */
/*   Updated: 2022/04/28 20:49:47 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

int	ft_find(char *str)
{
	int	i;

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

char	*ft_strjoin(char *str, char *buffer)
{
	char	*dest;
	int		size;
	int		i;
	int		j;

	i = -1;
	size = ft_strlen(str) + ft_strlen(buffer);
	if (!str)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
	}
	dest = (char *) malloc (sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	if (str)
		while (++i < ft_strlen(str))
			dest[i] = str[i];
	j = -1;
	while (++j < ft_strlen(buffer))
		dest[i++] = buffer[j];
	dest[i] = '\0';
	free(str);
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

char	*ft_substr(char *s, unsigned int start, int len)
{
	char	*str;

	if (!s || len == 0 || start >= (size_t)ft_strlen(s))
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy((char *)str, (const char *)(s + start), len +1);
	free(s);
	return (str);
}
