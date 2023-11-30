/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:02:29 by mawad             #+#    #+#             */
/*   Updated: 2023/11/15 20:37:46 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*buffer;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	buffer = (char *)malloc((i + 1) * sizeof(*buffer));
	i = 0;
	while (s[i])
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && src[i] != '\n' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	j = 0;
	if (s1 == NULL)
		s1 = ft_strdup("");
	if (s2 == NULL)
		return (NULL);
	buffer = (char *)malloc(1 * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (buffer == NULL)
		return (free(s1), free(s2), NULL);
	while (s1[i])
	{
		buffer[i] = s1[i];
		i++;
	}
	while (s2[j])
		buffer[i++] = s2[j++];
	buffer[i] = '\0';
	free(s1);
	free(s2);
	return (buffer);
}
