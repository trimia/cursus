/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:39:29 by mmariani          #+#    #+#             */
/*   Updated: 2022/03/10 16:35:52 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
static int	ft_strchrboolean(char s, char c)
{	
	if (s == c)
		return (1);
	return (0);
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

// static char	**ft_toomanylines()
// {
// 	char	**str;
// 	str = (char **)ft_calloc(sizeof(char *), 1);
// 	if (!str)
// 		return (NULL);
// 	return (str);
// }

char	**ft_split(char const *s, char c)
{
	size_t	x;
	char	*a;
	char	**str;
	char	sensei[2];

	sensei[0] = c;
	sensei[1] = 0;
	a = ft_strtrim(s, (const char *)sensei);
	if (a == NULL || !s)
		return (NULL);
	if (ft_strlen(a) == 0 || c == 0 || c == 48)
	{
		str = malloc(sizeof(char *) * 1);
		str[0] = malloc(sizeof(char) * (ft_strlen(s) + 1));
		free(a);
		return (str);
	}
	x = ft_count(a, c) + 1;
	str = (char **)malloc(sizeof(char *) * (x));
	if (!str)
		return (NULL);
	str[x] = 0;
	while (*s == c)
		s++;
	str = ft_rsplit(a, c, str, (x));
	free(a);
	return (str);
}
int main ()
{
	char const *s1 = "HELLO";
	char const *s2 = "YOYOY";
	char *s = "NULLO";
	unsigned int start = 0;
	size_t len = 5;
	int n = 0;
	char c = 0;
	char **test;
	char *yo;
	printf("__SPLIT__\n");
	test = ft_split(s1, c);
	while (test && test[n])
		free(test[n++]);
	free(test);
	// test = ft_split(s1, 0);
	// while (test && test[n])
	// 	free(test[n++]);
	// free(test);
	// test = ft_split("", c);
	// while (test && test[n])
	// 	free(test[n++]);
	// free(test);
	// test = ft_split("tripouille", 0);
	// while (test && test[n])
	// 	free(test[n++]);
	// free(test);
	printf("\033[32mAll good !\n\n\033[37m");
}