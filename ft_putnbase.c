/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarguir <kmarguir@learner.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 21:19:43 by kmarguir          #+#    #+#             */
/*   Updated: 2026/11/22 11:47:07 by kmarguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_base_len(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (ft_isspace(base[i]))
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

static int	ft_putnbase_recursive(unsigned long nbr, char *base,
		unsigned long size)
{
	int	len;

	len = 0;
	if (nbr >= size)
		len = ft_putnbase_recursive(nbr / size, base, size);
	if (len == -1 || ft_putchar(base[nbr % size]) == -1)
		return (-1);
	return (len + 1);
}

int	ft_putnbase(unsigned long nbr, char *base)
{
	int	size;

	size = ft_base_len(base);
	if (size == 0)
		return (0);
	return (ft_putnbase_recursive(nbr, base, size));
}
