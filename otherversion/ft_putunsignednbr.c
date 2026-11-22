/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 09:32:48 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/14 17:28:25 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsignednbr(unsigned int nb)
{
	int		i;
	char	c;

	i = 0;
	if (nb > 9)
		i += ft_putunsignednbr(nb / 10);
	c = nb % 10 + '0';
	i += write(1, &c, 1);
	return (i);
}
