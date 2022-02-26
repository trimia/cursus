/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimia <trimia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:39:29 by mmariani          #+#    #+#             */
/*   Updated: 2022/02/26 15:45:45 by trimia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchrboolean(char s, char c)
{	
	if (s == c)
		return (1);
	return (0);
}

int	ft_count(char *s, char c)
{
	size_t	i;
	char	*a;

	a = s;
	i = 0;
	s--;
	while (*++s)
	{
		if (ft_strchrboolean(*s, c))
			i++;
		while (ft_strchrboolean(*s, c))
			s++;
	}
	return (i);
}

char	**ft_rsplit(char *s, char c, char **str, int x)
{
	size_t		i;
	size_t		flag;
	static char	k = 0;
	char		*a;

	i = 0;
	flag = 0;
	a = (char *)s;
	s--;
	while (*(++s))
	{
		if (ft_strchrboolean(*s, c))
		{
			k++;
			break ;
		}
		i++;
	}
	*str = ft_substr(a, 0, i);
	while (ft_strchrboolean(*s, c))
			s++;
	if (!(k == x) && *s)
		ft_rsplit(s, c, str + 1, k);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	x;
	char	*a;
	char	**str;

	a = ft_strtrim(s, &c);
	if (s == NULL || a == NULL) 
		return (NULL);
	if (ft_strlen(a) == 0)
	{
		str = (char **)ft_calloc(sizeof(char *), 1);
		if (!str)
			return (NULL);
		free(a);
		return (str);
	}
	x = ft_count(a, c) + 1;
	str = (char **)malloc(sizeof(char *) * (x + 1));
	if (!str)
		return (NULL);
	str[x] = 0;
	while (*s == c)
		s++;
	str = ft_rsplit(a, c, str, (x));
	free(a);
	return (str);
}
