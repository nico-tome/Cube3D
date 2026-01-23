/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:23:48 by ntome             #+#    #+#             */
/*   Updated: 2026/01/23 13:41:50 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "parsing.h"
#include "vector2.h"

t_vec2	get_spawn(char **map)
{
	t_vec2	reader;

	reader.y = 0;
	while (map[reader.y])
	{
		reader.x = 0;
		while (map[reader.y][reader.x])
		{
			if (ft_strchr(SPAWNS, map[reader.y][reader.x]))
				return (reader);
			reader.x++;
		}
		reader.y++;
	}
	return (reader);
}

void	init_player(t_mlx *mlx, t_parsing_infos *parsing)
{
	mlx->player.pos = vec2_to_dvec2(get_spawn(parsing->map.map));
	mlx->player.vel = 0;
	set_dvec2(&mlx->player.rot, -1, 0);
	set_dvec2(&mlx->player.plane, 0, 0.66);
}
