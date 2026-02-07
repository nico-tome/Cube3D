/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:31:19 by ntome             #+#    #+#             */
/*   Updated: 2026/02/07 15:12:26 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_game(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->map.map[i])
	{
		free(mlx->map.map[i]);
		i++;
	}
	if (mlx->we_wall.texture)
		mlx_destroy_image(mlx->mlx, mlx->we_wall.texture);
	if (mlx->so_wall.texture)
		mlx_destroy_image(mlx->mlx, mlx->so_wall.texture);
	if (mlx->no_wall.texture)
		mlx_destroy_image(mlx->mlx, mlx->no_wall.texture);
	if (mlx->ea_wall.texture)
		mlx_destroy_image(mlx->mlx, mlx->ea_wall.texture);
	free(mlx->map.map);
	free(mlx->draw_line);
}

void	free_mlx(t_mlx *mlx)
{
	free_game(mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_context(mlx->mlx);
}
