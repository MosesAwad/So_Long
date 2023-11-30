/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:50:46 by mawad             #+#    #+#             */
/*   Updated: 2023/11/15 20:37:26 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_line_length(char *map_row)
{
	int	i;

	i = 0;
	if (!map_row)
		return (0);
	while (map_row[i])
		i++;
	return (i);
}

int	ft_line_count(char **map)
{
	int	i;

	i = 0;
	if (!map || !map[i])
		return (0);
	while (map[i])
		i++;
	return (i);
}

char	*extract_nl(char *line)
{
	int		i;
	char	*buffer;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	buffer = malloc(sizeof(*buffer) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (line[i] != '\n')
	{
		buffer[i] = line[i];
		i++;
	}
	buffer[i] = '\0';
	free(line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	int		nb_read;
	char	*line;
	char	*buffer;
	char	*extraction;

	nb_read = -1;
	line = NULL;
	while (!ft_strchr(line, '\n') && nb_read != 0)
	{
		buffer = malloc(sizeof(*buffer) * (1 + 1));
		if (!buffer)
			return (NULL);
		nb_read = read(fd, buffer, 1);
		buffer[nb_read] = '\0';
		if (nb_read == 0)
			return (free(buffer), line);
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	extraction = extract_nl(line);
	if (extraction)
		return (extraction);
	else
		return (line);
}
