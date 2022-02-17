/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:39:29 by mmariani          #+#    #+#             */
/*   Updated: 2022/02/17 13:02:11 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>



static int	ft_strchrboolean( char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}
static int ft_count(char *s, char c)
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
	char	**str;
	
	i = 0;

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
	str[j] = ft_substr(a, start, i);
	j++;
	start += i;
	// if (k == ft_count(a, c))
	// 	return (str);
	return (ft_rsplit(s, c,j,start));
}

char	**ft_split(char const *s, char c)
{
	char	*a;

	a=(char *)s;
	ft_rsplit(a,c,0,0);

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