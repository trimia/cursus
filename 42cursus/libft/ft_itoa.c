/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimia <trimia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:58:57 by trimia            #+#    #+#             */
/*   Updated: 2022/02/26 02:59:18 by trimia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_recursive_power(int nb, int power)
{
	int x;

	x = nb;
	if (power == 0)
		return (1);

	while (power--)
		nb *= x;
	return (nb);
}

char *ft_itoa(int n)
{
	char	*str;
	int		x,j;
	size_t	i;
	
	i = -1;
	x = n;
	n = n * 10;
	while (n)
	{
		n = n / 10;
		i++;
	}
	str = (char *)malloc(sizeof(char) * i +1);
	if (!str)
		return (NULL);
	if (x < 0)
	{
		x = x * - 1;
		*str = '-';
	}
	str--;
	i=i+1;
	while (--i)
	{	
		if(x<10)
			j = (x%ft_recursive_power(10,i));
		j = (x/ft_recursive_power(10,i));
		*++str = j + '0';
		x = x - j * ft_recursive_power(10,i);
	}
	// *str = '\0';
	return (str - ft_strlen(str));
}

int main ()
{
	char	*a;
	
	a = ft_itoa(234);
	printf("%s",a);
}