/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:46:17 by mmariani          #+#    #+#             */
/*   Updated: 2022/05/10 18:49:31 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"
typedef struct s_print
{
	va_list	args;	// arg to print out
	int		wdt;	// width
	int		prc;	// precision
	int		zero;	// zero padding
	int		pnt;	// .
	int		dash;	// -
	int		t_l;	// total_length (return value)
	int		sign;	// pos or neg number
	int		is_zero;// is number zero
	int		perc;	// %
	int		sp;		// space flag ' '
}	t_print;

typedef struct s_type
{
	char	c;
	char	s;
	char	p;
	char	d;
	char	i;
	char	u;
	char	x;
	char	X;
}	t_type;

t_print	ft_initialize(t_print *tab);
int	ft_printf(char * format, ...);
int	ft_choose(t_print *tab, char x, char *format);

#endif