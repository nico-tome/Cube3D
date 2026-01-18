/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <nicolas@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:35:48 by ntome             #+#    #+#             */
/*   Updated: 2026/01/18 20:36:12 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "texture.h"
#include "cube3d.h"

int	check_texture(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n %s can't be open.\n", path);
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
	if (!is_correct_color(parsing_i->ceiling_color))
	{
		printf("Error\n %s is not a valid color !\n", parsing_i->ceiling_color);
		return (0);
	}
	if (!is_correct_color(parsing_i->floor_color))
	{
		printf("Error\n %s is not a valid color !\n", parsing_i->floor_color);
		return (0);
	}
	return (1);
}

int	check_map(t_parsing_infos *parsing_i)
{
	t_vec2	reader;

	reader.y = 0;
	while (parsing_i->map.map[reader.y])
	{
		reader.x = 0;
		if (parsing_i->map.map[reader.y][reader.x] == '\n')
		{
			printf("Error\n Empty line in the map !\n");
			return (0);
		}
		while (parsing_i->map.map[reader.y][reader.x])
		{
			if (!ft_strchr(TILES, parsing_i->map.map[reader.y][reader.x]))
			{
				printf("Error\n'%c' not in the tileset !\n", parsing_i->map.map[reader.y][reader.x]);
				return (0);
			}
			reader.x++;
		}
		reader.y++;
	}
	return (check_close(parsing_i));
}

int	check_datas(t_game_infos *game_i, t_parsing_infos *parsing_i)
{
	if (!check_textures(parsing_i))
		return (0);
	if (!check_map(parsing_i))
		return (0);
	return (1);
}
