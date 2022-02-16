/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:02:21 by mmariani          #+#    #+#             */
/*   Updated: 2022/02/16 11:07:00 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char *set)
{
	set--;
	while (*(++set))
		if (c == *set)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		c;
	int		k;

	if (!s1)
		return (NULL);
	c = 0;
	while (check_set(s1[c], (char *)set))
		c++;
	k = ft_strlen(s1);
	while (check_set(s1[k - 1], (char *)set) && k > c)
		k--;
	return (ft_substr((char *)s1, c, k - c));
}
