/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:58:57 by trimia            #+#    #+#             */
/*   Updated: 2022/02/26 21:41:13 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	ft_power(int nb, int power)
{
	int x;

	x = nb;
	if (power == 0)
		return (1);
	while (--power)
		nb *= x;
	return (nb);
}
static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
char	*ft_itoa(int n)
{
	char	*str;
	char	*temp;
	int		j;
	int		i;
			
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		if (!str)
			return (NULL);
		return(str);
	}
	i = ft_count(n);

	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
		temp = str;
	if (n < 0)
	{
		n = n * - 1;
		*str = 45;
	}
	else
		str--;
	while (i--)
	{	
		if(n < 10)
			j = n;
		else
			j = (n/ft_power(10,i));
		*++str = j + '0';
		n = n - j * ft_power(10,i);
	}
	
	*++str = '\0';
	return (temp);
}

// int main ()
// {
// 	char	*a;
// 	char	*c;

// 	// printf("%d", INT_MIN);
// 	a= ft_itoa(-2147483648);
// 	// c = itoa(-2147483647);
// 	// int b=-2147483647;
//     // char buffer[20];
//    // c = itoa(b,buffer,2);
// 	printf("%s\n",a);
// 	return (0);
// }