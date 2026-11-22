/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarguir <kmarguir@learner.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 14:36:27 by kmarguir          #+#    #+#             */
/*   Updated: 2026/11/22 12:15:24 by kmarguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(char c, va_list *ap)
{
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	if (c == 'u')
		return (ft_unsigned_putnbr(va_arg(*ap, unsigned int)));
	if (c == 'x')
		return (ft_putnbase(va_arg(*ap, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbase(va_arg(*ap, unsigned int), "0123456789ABCDEF"));
	if (c == 'p')
		return (ft_putptr(va_arg(*ap, void *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		ret;
	int		i;
	va_list	ap;

	if (str == NULL)
		return (-1);
	count = 0;
	i = 0;
	va_start(ap, str);
	while (str[i] != '\0' && count != -1)
	{
		ret = 0;
		if (str[i] == '%' && str[i + 1] != '\0')
			ret = ft_conversion(str[++i], &ap);
		else if (str[i] != '%')
			ret = ft_putchar(str[i]);
		if (ret == -1)
			count = -1;
		else
			count += ret;
		i++;
	}
	va_end(ap);
	return (count);
}
