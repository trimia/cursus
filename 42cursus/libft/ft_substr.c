/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:24:13 by trimia            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/02/13 19:54:16 by mmariani         ###   ########.fr       */
=======
/*   Updated: 2022/02/13 16:10:49 by trimia           ###   ########.fr       */
>>>>>>> d90d81ab5879730e366c73f9da249f6fdd0061ce
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	ft_strlcpy((char *restrict)str, (const char *restrict)(s + start), len + 1);
	return (str);
}
