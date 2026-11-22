/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhexamin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 09:47:13 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/14 17:07:44 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrhexamin(unsigned int nb)
{
	unsigned int	u;
	int				i;
	char			*base;

	i = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
		i += ft_putnbrhexamin(nb / 16);
	u = nb % 16;
	i += write(1, base + u, 1);
	return (i);
}

/*#include <stdio.h>

int	main(void)
{
	unsigned int nb = 84651;
	int i = putnbrhexamin(nb);
	write(1, "\n", 1);
	printf("%d", i);
	return (0);
}*/
