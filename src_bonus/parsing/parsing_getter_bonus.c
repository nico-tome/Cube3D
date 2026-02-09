/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_getter_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:09:33 by ntome             #+#    #+#             */
/*   Updated: 2026/02/09 15:00:52 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"
#include "vector2_bonus.h"

char	*get_extension(char *path)
{
	char	*extension;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(path);
	while (path[i] && path[i] != '.')
		i++;
	if (!path[i])
		return (NULL);
	extension = ft_substr(path, i, size - i);
	return (extension);
}

int	get_file_size(char *path)
{
	int		fd;
	int		size;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	size = 0;
	line = get_next_line(fd);
	while (line)
	{
		size++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (size);
}

char	**load_file(int fd, int file_size)
{
	char	**datas;
	char	*line;
	int		i;

	if (fd == -1)
		return (NULL);
	datas = malloc(sizeof(char *) * (file_size + 1));
	if (!datas)
	{
		printf("Malloc error in parsing_getter.c at line 64\n");
		return (NULL);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		datas[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	datas[i] = NULL;
	return (datas);
}

const char	*get_key(char *line)
{
	const char	*keys[] = {"NO", "SO", "WE", "EA", "F", "C", ""};
	t_vec2		reader;
	int			start;

	reader.x = 0;
	start = skip_ws(line);
	while (keys[reader.x][0])
	{
		reader.y = 0;
		while (keys[reader.x][reader.y])
		{
			if (keys[reader.x][reader.y] != line[start + reader.y])
				break ;
			reader.y++;
		}
		if (!keys[reader.x][reader.y])
			return (keys[reader.x]);
		reader.x++;
	}
	return (keys[reader.x]);
}

void	try_read_datas(t_parsing_infos *parsing_i)
{
	int			line;
	int			count;
	const char	*key;

	line = 0;
	count = 6;
	key = NULL;
	while (parsing_i->raw_datas[line] && count > 0)
	{
		if (parsing_i->raw_datas[line][0] != '\n')
		{
			key = get_key(parsing_i->raw_datas[line]);
			if (key)
			{
				count--;
				update_infos(parsing_i, key, parsing_i->raw_datas[line]);
			}
		}
		line++;
	}
	while (parsing_i->raw_datas[line] && parsing_i->raw_datas[line][0] == '\n')
		line++;
	load_map(parsing_i, line);
}
