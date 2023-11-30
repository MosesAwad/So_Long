/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 22:03:13 by mawad             #+#    #+#             */
/*   Updated: 2023/11/14 22:47:55 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	digit_counter(unsigned int n)
{
	int	i;

	i = 0;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

static void	num_copy(char *buffer, unsigned int n, int digits)
{
	int		i;

	i = 0;
	buffer[digits] = '\0';
	i++;
	while (n >= 10)
	{
		buffer[digits - i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	buffer[digits - i] = n + 48;
}

char	*ft_itoa(unsigned int n)
{
	char	*buffer;
	int		digits;

	digits = digit_counter(n);
	buffer = (char *)malloc((digits + 1) * sizeof(*buffer));
	if (buffer == NULL)
		return (NULL);
	num_copy(buffer, n, digits);
	return (buffer);
}
