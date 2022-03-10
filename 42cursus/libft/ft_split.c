/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:39:29 by mmariani          #+#    #+#             */
/*   Updated: 2022/03/10 20:21:28 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_stilltoomanylines(char **str, char *a)
{
	str = malloc(sizeof(char *) * 2);
	if (!str)
		return (NULL);
	str[0] = NULL;
	str[1] = NULL;
	free(a);
	return (str);
}

static int	ft_count(char *s, char c)
{
	size_t	i;
	char	*a;

	a = s;
	i = 0;
	s--;
	while (*++s)
	{
		if (*s == c)
			i++;
		while (*s == c)
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
		if (*s == c)
		{
			k++;
			break ;
		}
		i++;
	}
	*str = ft_substr(a, 0, i);
	while (*s == c)
			s++;
	if (!(k == x) && *s)
		ft_rsplit(s, c, str + 1, k);
	return (str);
}

char	**ft_toomanylines(char **str, char *a, char const *s)
{
	str = malloc(sizeof(char *) * 2);
	if (!str)
		return (NULL);
	str[0] = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str[0])
		return (NULL);
	str[1] = NULL;
	ft_strlcpy(str[0], s, ft_strlen(s) + 1);
	free(a);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	x;
	char	*a;
	char	**str;
	char	sensei[2];

	str = NULL;
	sensei[0] = c;
	sensei[1] = 0;
	a = ft_strtrim(s, (const char *)sensei);
	if (s == NULL || a == NULL || ft_strlen(a) == 0)
		return (ft_stilltoomanylines(str, a));
	if (ft_strlen(a) == 0 || c == 0)
		return (ft_toomanylines(str, a, s));
	x = ft_count(a, c) + 1;
	str = (char **)malloc(sizeof(char *) * (x + 1));
	if (!str)
		return (NULL);
	str[x] = 0;
	while (*s == c)
		s++;
	str = ft_rsplit(a, c, str, (x + 1));
	free(a);
	return (str);
}
