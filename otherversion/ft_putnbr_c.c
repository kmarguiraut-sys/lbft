/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 07:48:47 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/14 17:34:48 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_c(int nb)
{
	int		i;
	char	c;

	i = 0;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		i = 11;
		return (i);
	}
	if (nb < 0)
	{
		nb *= -1;
		i += write (1, "-", 1);
	}
	if (nb > 9)
		i += ft_putnbr_c(nb / 10);
	c = nb % 10 + '0';
	i += write(1, &c, 1);
	return (i);
}

/*#include <stdio.h>

int	main(void)
{
	int nb = 864513;
	printf("%d", ft_putnbr_c(nb));
	return (0);
}*/
