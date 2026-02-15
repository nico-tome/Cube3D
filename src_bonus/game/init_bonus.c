/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouton <ccouton@42angouleme.fr>          +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:23:48 by ccouton         #+#    #+#               */
/*   Updated: 2026/02/15 00:00:00 by ccouton        ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"
#include "parsing_bonus.h"
#include "vector2_bonus.h"

void	init_doors(t_mlx *mlx)
{
	int	y;
	int	x;

	mlx->door_count = 0;
	y = 0;
	while (mlx->map.map[y])
	{
		x = 0;
		while (mlx->map.map[y][x])
		{
			if (mlx->map.map[y][x] == 'D')
			{
				mlx->doors[mlx->door_count].x = x;
				mlx->doors[mlx->door_count].y = y;
				mlx->doors[mlx->door_count].open = 0;
				mlx->door_count++;
			}
			x++;
		}
		y++;
	}
}

static double	get_door_distance(t_mlx *mlx, int door_idx)
{
	double	door_x;
	double	door_y;

	door_x = mlx->doors[door_idx].x + 0.5;
	door_y = mlx->doors[door_idx].y + 0.5;
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
