/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:34:43 by mdoll             #+#    #+#             */
/*   Updated: 2022/12/30 15:01:12 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"


static int	call_functions(const char c, va_list ap)
{
	int	chars_printed;

	if (c == 'c')
		chars_printed = pchar(va_arg(ap, int));
	if (c == 's')
		chars_printed = pstr(va_arg(ap, char *));
	// if (c == 'p')
	// 	chars_printed = pvoidp(va_arg(ap, void *));
	if (c == 'd' || c == 'i')
		chars_printed = pdecint(va_arg(ap, int));
	// if (c == 'u')
	// 	chars_printed = pudec(va_arg(ap, unsigned float));
	// if (c == 'x')
	// 	chars_printed = phex_l(va_arg(ap, int)); // wich datatype??
	// if (c == 'X')
	// 	chars_printed = phex_u(va_arg(ap, int)); // wich datatype??
	if (c == '%')
		chars_printed = pperc();
	return (chars_printed);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		chars_printed;

	i = 0;
	chars_printed = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			i++;
			chars_printed += call_functions(str[i], ap);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			chars_printed++;
		}
		i++;
	}
	return (chars_printed);
}
