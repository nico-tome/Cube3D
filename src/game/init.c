/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:23:48 by ntome             #+#    #+#             */
/*   Updated: 2026/01/31 10:09:57 by ntome            ###   ########.fr       */
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
	set_dvec2(&mlx->player.plane, -mlx->player.rot.y * 0.66, mlx->player.rot.x * 0.66);
}

void	init_map(t_mlx *mlx, t_parsing_infos *parsing)
{
	int	i;
	int	j;

	mlx->map.map = malloc(sizeof(char *) * (parsing->map.size + 1));
	if (!mlx->map.map)
		return ;
	i = 0;
	while (i < parsing->map.size)
	{
		mlx->map.map[i] = malloc(sizeof(char) * (ft_strlen(parsing->map.map[i]) + 1));
		if (!mlx->map.map[i])
			return ;
		j = 0;
		while (parsing->map.map[i][j])
		{
			mlx->map.map[i][j] = parsing->map.map[i][j];
			j++;
		}
		mlx->map.map[i][j] = '\0';
		i++;
	}
	mlx->map.map[i] = NULL;
}
