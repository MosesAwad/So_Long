/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:23:31 by mawad             #+#    #+#             */
/*   Updated: 2023/11/24 23:50:40 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	address_len(unsigned long long int c)
{
	int	len;

	len = 0;
	if (c == 0)
		return (ft_strlen("0x0"));
	while (c >= 16)
	{
		c = c / 16;
		len++;
	}
	return (len + 1);
}

static void	put_address(unsigned long long int c)
{
	const char	*set;

	set = "0123456789abcdef";
	if (c >= 16)
	{
		put_address(c / 16);
		put_address(c % 16);
	}
	else
	{
		ft_putchar(set[c % 16]);
	}
}

int	ft_print_address(unsigned long long int c)
{
	if (c == 0)
	{
		ft_putstr("0x0");
		return (ft_strlen("0x0"));
	}
	ft_putstr("0x");
	put_address(c);
	return (ft_strlen("0x") + address_len(c));
}
