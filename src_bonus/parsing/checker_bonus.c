/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:35:48 by ntome             #+#    #+#             */
/*   Updated: 2026/02/09 16:20:25 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"
#include "texture_bonus.h"
#include "cube3d_bonus.h"

int	check_texture(char *path)
{
	int	fd;

	if (!path || !path[0])
	{
		printf("Error\nA file can't be open\n");
		return (0);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n'%s' can't be open.\n", path);
		return (0);
	}
	close(fd);
	return (1);
}

int	check_textures(t_parsing_infos *parsing_i)
{
	if (!check_texture(parsing_i->no_path))
		return (0);
	if (!check_texture(parsing_i->so_path))
		return (0);
	if (!check_texture(parsing_i->we_path))
		return (0);
	if (!check_texture(parsing_i->ea_path))
		return (0);
	if (!check_texture(parsing_i->floor_color))
		return (0);
	if (!check_texture(parsing_i->ceiling_color))
		return (0);
	return (1);
}

int	check_line(char *line, int *has_spawn, int j)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(TILES, line[i]) && !ft_strchr(SPAWNS, line[i]))
		{
			printf("Error\n");
			printf("Invalid tile at line: %d column: %d (%c)\n", j, i, line[i]);
			return (0);
		}
		if (ft_strchr(SPAWNS, line[i]) && *has_spawn == 1)
		{
			printf("Error\n Multiple spawns !\n");
			return (0);
		}
		if (ft_strchr(SPAWNS, line[i]) && *has_spawn == 0)
			*has_spawn = 1;
		i++;
	}
	return (1);
}

int	check_map(char **map)
{
	int		line;
	int		has_spawn;

	has_spawn = 0;
	line = 0;
	while (map[line])
	{
		if (map[line][0] == '\n')
		{
			printf("Error\n Empty line in the map at line %d !\n", line);
			return (0);
		}
		if (!check_line(map[line], &has_spawn, line))
			return (0);
		line++;
	}
	if (!has_spawn)
	{
		printf("Error\nNo spawn in the map.\n");
		return (0);
	}
	return (check_close(map));
}

int	check_datas(t_parsing_infos *parsing_i)
{
	int	extension_len;

	extension_len = ft_strlen(parsing_i->file_extension);
	if (!parsing_i->file_extension
		|| ft_strncmp(parsing_i->file_extension, ".cub", extension_len))
	{
		printf("Error\n");
		printf("'%s' is not a valid file", parsing_i->file_extension);
		printf(" extension '.cub'\n");
		return (0);
	}
	if (!check_textures(parsing_i))
		return (0);
	if (!check_map(parsing_i->map.map))
		return (0);
	return (1);
}
