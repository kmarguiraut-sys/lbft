/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhexacaps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 11:38:26 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/14 17:07:36 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrhexacaps(unsigned int nb)
{
	unsigned int	u;
	int				i;
	char			*base;

	i = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
		i += ft_putnbrhexacaps(nb / 16);
	u = nb % 16;
	i += write(1, base + u, 1);
	return (i);
}

/*#include <stdio.h>

int	main(void)
{
	unsigned int nb = 84651;
	int i = putnbrhexacaps(nb);
	write(1, "\n", 1);
	printf("%d", i);
	return (0);
}*/
