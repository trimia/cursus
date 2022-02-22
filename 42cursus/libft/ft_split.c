/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimia <trimia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:39:29 by mmariani          #+#    #+#             */
/*   Updated: 2022/02/18 12:57:33 by trimia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>



 int	ft_strchrboolean( char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}
 int ft_count(char *s, char c)
{
	size_t	i;
	while(*s++)
		if (ft_strchrboolean(*s,c))
			i++;
	return (i);
}


char	**ft_rsplit(char const *s, char c, size_t j, size_t start)
{
	size_t	i;
	size_t	x;
	char	**str;
	char	*a;

	a=(char *)s;	
	i = 0;
	x = ft_count((char *)s,c);
	str = (char **)malloc(sizeof(char *) * (x + 1));
	if (!str)
		return (NULL);

	// k = 0;
	s--;
	while (*(++s))
	{
		if (ft_strchrboolean(*s,c))
		{
			// k++;
			break;
		}
		i++;	
	}
	*str++ = ft_substr(a, start, i);
	str++;
	start += i;
	// if (k == ft_count(a, c))
	// 	return (str);
	return (ft_rsplit(s+1, c,j,start));
}

char	**ft_split(char const *s, char c)
{
	size_t j,start;
	j=0;
	start=0;
	char	*a;

	a=(char *)s;
	(ft_rsplit(a,c,j,start));

}

int main ()
{
	char **prova;
	int i =0;
	prova = ft_split("lorem+ipsum+dolor+sit+amet,+consectetur+adipiscing+elit.+Sed+non+risus.+Suspendisse", '+');
	while (i<11){
	printf("%s",prova[i]);
	i++;
	}

	// printf("%d",ft_strchrboolean("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' '));
	
}