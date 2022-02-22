/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:39:29 by mmariani          #+#    #+#             */
/*   Updated: 2022/02/22 13:37:19 by mmariani         ###   ########.fr       */
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

 int	ft_count(char *s, char c)
{
	size_t	i;
	
	i = 0;
	s--;
	while (*++s==c)
		;
	while(*++s)
		if (ft_strchrboolean(*s,c))
			i++;
	return (i);
}

char	**ft_rsplit(char *s, char c, char **str, int x)
{
	size_t	i;
	static char	k = 0;
	char *a;

	i =0;
	a = (char *)s;	
	s--;
	while (*(++s))
	{
		if (ft_strchrboolean(*s,c))
		{
			k++;
			break ;
		}
		i++;
	}
	*str = ft_substr(a, 0, i);
	if (!(k == x))
		ft_rsplit(++s, c, str + 1, k);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	x;
	char	*a;
	char	**str;

	a=(char *)s;	
	x = ft_count((char *)s,c) + 1;
	printf("%zu",x);
	str = (char **)malloc(sizeof(char *) * (x + 1));
	if (!str)
		return (NULL);
	while (*s==c)
		s++;
	a=(char *)s;
	str = ft_rsplit(a,c,str,x);
	return (str);

}

// int main ()
// {
// 	char **prova;
// 	int i;
// 	prova = ft_split("lorem+ipsum+dolor+sit+amet,+consectetur++adipiscing+elit.+Sed+non+risus.+Suspendisse++", '+');
// 	// while (i<11){
// 	// printf("%s",prova[i]);
// 	// i++;
// 	for(i = 0; i <= 11; i++)
//     printf("\n Element is: %s \n", prova[i]);

// 	// printf("%d",ft_strchrboolean("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' '));
	
// }