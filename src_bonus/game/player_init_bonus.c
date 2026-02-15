/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouton <ccouton@42angouleme.fr>          +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 00:00:00 by ccouton         #+#    #+#               */
/*   Updated: 2026/02/15 00:00:00 by ccouton        ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"
#include "parsing_bonus.h"
#include "vector2_bonus.h"

static void	set_player_rotation(t_mlx *mlx, char spawn)
{
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

static void	find_spawn(t_mlx *mlx, t_parsing_infos *parsing)
{
	t_vec2	pos;

	pos.y = 0;
	while (parsing->map.map[pos.y])
	{
		pos.x = 0;
		while (parsing->map.map[pos.y][pos.x])
		{
			if (ft_strchr(SPAWNS, parsing->map.map[pos.y][pos.x]))
			{
				mlx->player.pos = vec2_to_dvec2(pos);
				mlx->player.pos = dvec2_add
					(mlx->player.pos, (t_dvec2){0.5, 0.5});
				set_player_rotation
						(mlx, parsing->map.map[pos.y][pos.x]);
				return ;
			}
			pos.x++;
		}
		pos.y++;
	}
}

void	init_player(t_mlx *mlx, t_parsing_infos *parsing)
{
	mlx->player.vel = 0;
	find_spawn(mlx, parsing);
}
