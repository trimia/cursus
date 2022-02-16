/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:39:29 by mmariani          #+#    #+#             */
/*   Updated: 2022/02/16 13:24:13 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static int	ft_strchrboolean( char s, char c)
{
		if (s == c)
			return (0);
	return (1);
}


char	**ft_split(char const *s, char c)
{
	size_t	i,j;
	size_t	start;
	char	**str;
	char	*a;

	a=s;
	i = 0;
	j = 0;
	start = 0;
	while (*s++)
	{
		if (ft_strchrboolean(*s,c)==0)
			break;
		i++;	
	}
	str[j] = ft_substr(a,start,i);
	j++;
	ft_split(*s,c);
	start += i;
	if (s[i]=='\0')
		return (str);
	
}

#include<stdio.h>

int main ()
{
	char **prova;
	int i =0;
	prova = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	while (i<=12){
	printf("%s",prova[i]);
	i++;
	}

	// printf("%d",ft_strchrboolean("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' '));
	
}