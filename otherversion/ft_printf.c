/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 18:04:52 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/15 13:38:05 by kmarguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dispatch(va_list *ap, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr_c(va_arg(*ap, int)));
	if (c == 's')
		return (ft_putstr_c(va_arg(*ap, char *)));
	if (c == 'u')
		return (ft_putunsignednbr(va_arg(*ap, unsigned int)));
	if (c == 'c')
		return (ft_putchar((char)va_arg(*ap, int)));
	if (c == 'x')
		return (ft_putnbrhexamin(va_arg(*ap, unsigned int)));
	if (c == 'X')
		return (ft_putnbrhexacaps(va_arg(*ap, unsigned int)));
	if (c == 'p')
		return (ft_address(va_arg(*ap, void *)));
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'a')
		return (write(1, "my awesome 42", 13));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				break ;
			count += ft_dispatch(&ap, str[i + 1]);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
