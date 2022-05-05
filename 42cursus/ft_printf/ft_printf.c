/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:46:12 by mmariani          #+#    #+#             */
/*   Updated: 2022/05/05 19:54:37 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ft_printf.h

// `#'          The value should be converted to an ``alternate form''.
//                       For c, d, i, n, p, s, and u conversions, this option has
//                       no effect.  For o conversions, the precision of the num-
//                       ber is increased to force the first character of the
//                       output string to a zero.  For x and X conversions, a
//                       non-zero result has the string `0x' (or `0X' for X con-
//                       versions) prepended to it.  For a, A, e, E, f, F, g, and
//                       G conversions, the result will always contain a decimal
//                       point, even if no digits follow it (normally, a decimal
//                       point appears in the results of those conversions only
//                       if a digit follows).  For g and G conversions, trailing
//                       zeros are not removed from the result as they would oth-
//                       erwise be.

//          `0' (zero)   Zero padding.  For all conversions except n, the con-
//                       verted value is padded on the left with zeros rather
//                       than blanks.  If a precision is given with a numeric
//                       conversion (d, i, o, u, i, x, and X), the 0 flag is
//                       ignored.

//          `-'          A negative field width flag; the converted value is to
//                       be left adjusted on the field boundary.  Except for n
//                       conversions, the converted value is padded on the right
//                       with blanks, rather than on the left with blanks or
//                       zeros.  A - overrides a 0 if both are given.

//          ` ' (space)  A blank should be left before a positive number produced
//                       by a signed conversion (a, A, d, e, E, f, F, g, G, or
//                       i).

//          `+'          A sign must always be placed before a number produced by
//                       a signed conversion.  A + overrides a space if both are
//                       used.

// You have to implement the following conversions:
// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.

int	ft_printf()
{

}

int	ft_cin(char * format, ...)
{
    //serie if gestire format check % read lettera successiva + gestione flag struttura variatica
}

int	ft_print_char(char x)
{
	write(1, x, 1);
	return (1);
}

int	ft_print_string(char *s)
{
	int sum;

	sum = 0;
	while (*s++ != '\0')
		sum += ft_print_char(*s); //posso stampare carattere per carattere o devo stampare tutta la stringa insieme?
	return (sum);
}

int	ft_print_number(int n)
{
	char i;

	while (n)
	{
		n = n / 10;
		i = n + 48;
		ft_print_char(1, i, 1);
	}
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

conversione dec hex

upper/lover case

