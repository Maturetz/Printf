/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maturetz <maturetz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:43:14 by maturetz          #+#    #+#             */
/*   Updated: 2024/12/14 03:28:59 by maturetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(const char **format, va_list list)
{
	int	byte;

	byte = 0;
	if (**format == 'd' || **format == 'i')
		byte += ft_putnbr(va_arg(list, int));
	else if (**format == 's')
		byte += ft_putstr(va_arg(list, char *));
	else if (**format == 'c')
		byte += ft_putchar(va_arg(list, int));
	else if (**format == 'x')
		byte += ft_puthex(va_arg(list, unsigned int), "0123456789abcdef");
	else if (**format == 'X')
		byte += ft_puthex(va_arg(list, unsigned int), "0123456789ABCDEF");
	else if (**format == 'p')
		byte += ft_putptr(va_arg(list, void *));
	else if (**format == '%')
		byte += ft_putchar('%');
	else if (**format == 'u')
		byte += ft_putunbr(va_arg(list, unsigned int));
	return (byte);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int	byte;

	byte = 0;
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			byte += handle_format(&format, list);
		}
		else
			byte += ft_putchar(*format);
		format++;
	}
	va_end(list);
	return (byte);
}