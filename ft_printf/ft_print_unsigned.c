/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:24:16 by mawad             #+#    #+#             */
/*   Updated: 2023/09/20 19:01:37 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	unsigned_len(unsigned int nb)
{
	int	count;

	count = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		count++;
	}
	return (count + 1);
}

static void	put_unsigned(unsigned int nb)
{
	if (nb >= 10)
	{
		put_unsigned(nb / 10);
		put_unsigned(nb % 10);
	}
	else
	{
		ft_putchar(nb + 48);
	}
}

int	ft_print_unsigned(unsigned int nb)
{
	put_unsigned(nb);
	return (unsigned_len(nb));
}
