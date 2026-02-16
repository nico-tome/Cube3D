/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 00:00:00 by ccouton           #+#    #+#             */
/*   Updated: 2026/02/16 12:22:11 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"
#include "parsing_bonus.h"
#include "vector2_bonus.h"

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
	char	spawn;

	mlx->player.pos = vec2_to_dvec2(get_spawn(parsing->map.map));
	mlx->player.pos = dvec2_add(mlx->player.pos, (t_dvec2){.x = 0.5, .y = 0.5});
	mlx->player.vel = 0;
	spawn = parsing->map.map[(int)mlx->player.pos.y][(int)mlx->player.pos.x];
	if (spawn == 'N')
		set_dvec2(&mlx->player.rot, 0, -1);
	else if (spawn == 'S')
		set_dvec2(&mlx->player.rot, 0, 1);
	else if (spawn == 'E')
		set_dvec2(&mlx->player.rot, 1, 0);
	else
		set_dvec2(&mlx->player.rot, -1, 0);
	set_dvec2(&mlx->player.plane, -mlx->player.rot.y * 0.66,
		mlx->player.rot.x * 0.66);
}
