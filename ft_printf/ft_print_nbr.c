/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:24:16 by mawad             #+#    #+#             */
/*   Updated: 2023/09/20 19:01:16 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(int nb)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb *= -1;
		flag = 1;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		count++;
	}
	if (flag)
		return (count + 2);
	else
		return (count + 1);
}

static void	put_nbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2");
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb >= 10)
	{
		put_nbr(nb / 10);
		put_nbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + 48);
	}
}

int	ft_print_nbr(int nb)
{
	put_nbr(nb);
	return (num_len(nb));
}

// int main()
// {
// 	printf("\n%d\n", printf("%d", -2147483648));
// 	printf("\n%d\n", ft_print_nbr(-2147483648));
// 	return (0);
// }