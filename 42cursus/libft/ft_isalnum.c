/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:38:49 by mmariani          #+#    #+#             */
/*   Updated: 2022/01/15 02:16:13 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isalnum( int n)
{
	if (((n > 64 && n < 91) || (n > 96 && n < 123)) || (n >= 48 && n <= 57))
		return (1);
	return (0);
}
