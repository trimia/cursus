/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:31:06 by mmariani          #+#    #+#             */
/*   Updated: 2022/03/21 21:49:39 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

// #ifndef BUUFER_SIZE
// #define BUFFER_SIZE 3
// #endif

char	*ft_find(char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);

#endif
