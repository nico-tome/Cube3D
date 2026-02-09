/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:31:19 by ntome             #+#    #+#             */
/*   Updated: 2026/02/10 00:21:07 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

void	free_game(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->map.map[i])
	{
		free(mlx->map.map[i]);
		i++;
	}
	if (mlx->textures.we_wall.texture)
		mlx_destroy_image(mlx->mlx, mlx->textures.we_wall.texture);
	if (mlx->textures.so_wall.texture)
		mlx_destroy_image(mlx->mlx, mlx->textures.so_wall.texture);
	if (mlx->textures.no_wall.texture)
		mlx_destroy_image(mlx->mlx, mlx->textures.no_wall.texture);
	if (mlx->textures.ea_wall.texture)
		mlx_destroy_image(mlx->mlx, mlx->textures.ea_wall.texture);
	if (mlx->textures.ceiling.texture)
		mlx_destroy_image(mlx->mlx, mlx->textures.ceiling.texture);
	if (mlx->textures.floor.texture)
		mlx_destroy_image(mlx->mlx, mlx->textures.floor.texture);
	free(mlx->map.map);
	free(mlx->draw_line);
}

void	free_mlx(t_mlx *mlx)
{
	free_game(mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_context(mlx->mlx);
}
