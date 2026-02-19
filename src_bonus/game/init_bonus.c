/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:23:48 by ccouton           #+#    #+#             */
/*   Updated: 2026/02/19 15:17:00 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"
#include "parsing_bonus.h"
#include "vector2_bonus.h"

void	init_doors(t_mlx *mlx)
{
	t_vec2	i;

	mlx->door_count = 0;
	i.y = -1;
	while (mlx->map.map[++i.y])
	{
		i.x = -1;
		while (mlx->map.map[i.y][++i.x])
		{
			if (mlx->map.map[i.y][i.x] == 'D')
			{
				mlx->doors[mlx->door_count].pos = i;
				mlx->doors[mlx->door_count].open = 0;
				mlx->doors[mlx->door_count].disabled = 0;
				mlx->door_count++;
			}
		}
	}
}

static double	get_door_distance(t_mlx *mlx, int door_idx)
{
	double	door_x;
	double	door_y;

	door_x = mlx->doors[door_idx].pos.x + 0.5;
	door_y = mlx->doors[door_idx].pos.y + 0.5;
	return (sqrt(pow(mlx->player.pos.x - door_x, 2)
			+ pow(mlx->player.pos.y - door_y, 2)));
}

void	toggle_door(t_mlx *mlx)
{
	int		i;
	double	closest_distance;
	int		closest_door;
	double	distance;

	closest_distance = 2.0;
	closest_door = -1;
	i = 0;
	while (i < mlx->door_count)
	{
		distance = get_door_distance(mlx, i);
		if (distance < closest_distance)
		{
			closest_distance = distance;
			closest_door = i;
		}
		i++;
	}
	if (closest_door != -1)
		mlx->doors[closest_door].open = !mlx->doors[closest_door].open;
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
		mlx->map.map[i] = malloc(ft_strlen(parsing->map.map[i]) + 1);
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
	init_doors(mlx);
	if (!mlx->map.map)
		return ;
}

void	init_datas(t_mlx *mlx, t_parsing_infos *parsing_i)
{
	mlx->window_draw_size = mlx->window_size;
	init_map(mlx, parsing_i);
	init_player(mlx, parsing_i);
	init_editor(mlx);
	mlx->game_infos.no = ft_strdup(parsing_i->no_path);
	mlx->game_infos.so = ft_strdup(parsing_i->so_path);
	mlx->game_infos.ea = ft_strdup(parsing_i->ea_path);
	mlx->game_infos.we = ft_strdup(parsing_i->we_path);
	mlx->game_infos.ceiling = ft_strdup(parsing_i->ceiling_color);
	mlx->game_infos.floor = ft_strdup(parsing_i->floor_color);
	mlx->keys[255] = 1;
}
