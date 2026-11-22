/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarguir <kmarguir@learner.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 22:07:48 by kmarguir          #+#    #+#             */
/*   Updated: 2026/11/22 11:59:44 by kmarguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	count;

	if (ptr == NULL)
		return (ft_putstr(PTR_NULL));
	if (ft_putstr("0x") == -1)
		return (-1);
	count = ft_putnbase((unsigned long)ptr, "0123456789abcdef");
	if (count == -1)
		return (-1);
	return (count + 2);
}
