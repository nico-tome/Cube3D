/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:31:19 by ntome             #+#    #+#             */
/*   Updated: 2026/02/06 19:47:20 by ntome            ###   ########.fr       */
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
	mlx_destroy_image(mlx->mlx, mlx->no_wall.texture);
	mlx_destroy_image(mlx->mlx, mlx->so_wall.texture);
	mlx_destroy_image(mlx->mlx, mlx->ea_wall.texture);
	mlx_destroy_image(mlx->mlx, mlx->we_wall.texture);
	free(mlx->map.map);
	free(mlx->drawing_line);
}
