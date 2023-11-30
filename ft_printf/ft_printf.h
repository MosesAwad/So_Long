/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:06:31 by mawad             #+#    #+#             */
/*   Updated: 2023/11/14 22:53:40 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// # include "../so_long.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_print_hex(unsigned int c, char frmt);
int		ft_print_nbr(int nb);
int		ft_print_address(unsigned long long int c);
int		ft_print_unsigned(unsigned int nb);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_printf(const char *placeholders, ...);

#endif