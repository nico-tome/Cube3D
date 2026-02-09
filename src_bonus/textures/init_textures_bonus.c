/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:01:08 by ntome             #+#    #+#             */
/*   Updated: 2026/02/10 00:15:20 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"
#include "parsing_bonus.h"

void	init_color_list(int size, mlx_color **list, char *color)
{
	int	i;

	*list = malloc(sizeof(mlx_color) * size);
	if (!*list)
	{
		printf("Malloc Error in init_textures.c at line 20.\n");
		return ;
	}
	i = 0;
	while (i < size)
	{
		(*list)[i] = get_color(color);
		i++;
	}
}

int	init_textures(t_mlx *mlx, t_parsing_infos *parsing)
{
	mlx->textures.ceiling.texture = mlx_new_image_from_file(mlx->mlx,
			parsing->ceiling_color, &mlx->textures.ceiling.texture_width,
			&mlx->textures.ceiling.texture_height);
	mlx->textures.floor.texture = mlx_new_image_from_file(mlx->mlx,
			parsing->floor_color, &mlx->textures.floor.texture_width,
			&mlx->textures.floor.texture_height);
	init_color_list(mlx->window_size.y * mlx->window_size.x,
		&(mlx->draw_line), "0,0,0");
	mlx->textures.no_wall.texture = mlx_new_image_from_file(mlx->mlx,
			parsing->no_path, &mlx->textures.no_wall.texture_width,
			&mlx->textures.no_wall.texture_height);
	mlx->textures.so_wall.texture = mlx_new_image_from_file(mlx->mlx,
			parsing->so_path, &mlx->textures.so_wall.texture_width,
			&mlx->textures.so_wall.texture_height);
	mlx->textures.ea_wall.texture = mlx_new_image_from_file(mlx->mlx,
			parsing->ea_path, &mlx->textures.ea_wall.texture_width,
			&mlx->textures.ea_wall.texture_height);
	mlx->textures.we_wall.texture = mlx_new_image_from_file(mlx->mlx,
			parsing->we_path, &mlx->textures.we_wall.texture_width,
			&mlx->textures.we_wall.texture_height);
	if (!mlx->textures.ea_wall.texture || !mlx->textures.no_wall.texture
		|| !mlx->textures.so_wall.texture || !mlx->textures.we_wall.texture)
		return (0);
	return (1);
}
