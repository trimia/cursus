/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:39:29 by mmariani          #+#    #+#             */
/*   Updated: 2022/02/25 13:27:10 by mmariani         ###   ########.fr       */
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

// int main ()
// {
// 	char **prova;
// 	int i=0;
// 	prova = ft_split("     ",' ');
// 	// while (i<11){
// 	// printf("%s",prova[i]);
// 	// i++;
// 	// int size = sizeof prova / sizeof *prova;
// 	// printf("len is %d",size);	
// 	for(i = 0; i <= 4; i++)
// 	while(prova[i]!=NULL){
//     // printf("%s\n", prova);
// 	i++;
// 	}
// 	// printf("%d",ft_strchrboolean("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' '));	
// }