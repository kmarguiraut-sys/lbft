/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 11:40:03 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/14 16:55:12 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putnbrhexa(unsigned long nb)
{
	unsigned int	u;
	int				i;
	char			*base;

	i = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
		i += putnbrhexa(nb / 16);
	u = nb % 16;
	i += write(1, base + u, 1);
	return (i);
}

int	ft_address(void *address)
{
	unsigned long		value;
	int					i;

	i = 0;
	if (!address)
		return (write(1, "(nil)", 5));
	value = (unsigned long)address;
	write(1, "0x", 2);
	i = putnbrhexa(value);
	return (i + 2);
}

/*#include <stdio.h>

int	main(void)
{
	char c = 'a';
	void *p = &c;
	int i = ft_address(p);
	printf("\n");
	printf("%p - %d", p, i);
	return (0);
}*/
