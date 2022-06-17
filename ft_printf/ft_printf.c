/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:06:33 by mberquer          #+#    #+#             */
/*   Updated: 2022/01/07 14:12:02 by mberquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_print(char format, va_list args)
{
	if (format == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (format == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long int)));
	else if (format == 'd' || format == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_hexa(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_print_char(format));
	else
		return (ft_print_char(format));
}

int	ft_printf(const char *format, ...)
{
	int		size;
	int		i;
	va_list	args;

	size = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			size += ft_format_print(format[i + 1], args);
			i++;
		}
		else
			size += ft_print_char(format[i]);
		i++;
	}
	return (size);
}
