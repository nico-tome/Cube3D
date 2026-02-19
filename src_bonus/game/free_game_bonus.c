/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:31:19 by ntome             #+#    #+#             */
/*   Updated: 2026/02/19 15:23:22 by ntome            ###   ########.fr       */
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

void	free_game_infos(t_mlx *mlx)
{
	if (mlx->game_infos.ceiling)
		free(mlx->game_infos.ceiling);
	if (mlx->game_infos.floor)
		free(mlx->game_infos.floor);
	if (mlx->game_infos.no)
		free(mlx->game_infos.no);
	if (mlx->game_infos.so)
		free(mlx->game_infos.so);
	if (mlx->game_infos.we)
		free(mlx->game_infos.we);
	if (mlx->game_infos.ea)
		free(mlx->game_infos.ea);
}

void	free_mlx(t_mlx *mlx)
{
	free_game(mlx);
	free(mlx->editor.part);
	free_game_infos(mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_context(mlx->mlx);
}
