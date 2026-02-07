/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:01:08 by ntome             #+#    #+#             */
/*   Updated: 2026/02/07 14:43:29 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "parsing.h"

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
	mlx->floor = get_color(parsing->floor_color);
	mlx->ceiling = get_color(parsing->ceiling_color);
	init_color_list(mlx->window_size.y * mlx->window_size.x,
		&(mlx->draw_line), "0,0,0");
	mlx->no_wall.texture = mlx_new_image_from_file(mlx->mlx,
			parsing->no_path, &mlx->no_wall.texture_width,
			&mlx->no_wall.texture_height);
	mlx->so_wall.texture = mlx_new_image_from_file(mlx->mlx,
			parsing->so_path, &mlx->so_wall.texture_width,
			&mlx->so_wall.texture_height);
	mlx->ea_wall.texture = mlx_new_image_from_file(mlx->mlx,
			parsing->ea_path, &mlx->ea_wall.texture_width,
			&mlx->ea_wall.texture_height);
	mlx->we_wall.texture = mlx_new_image_from_file(mlx->mlx,
			parsing->we_path, &mlx->we_wall.texture_width,
			&mlx->we_wall.texture_height);
	if (!mlx->ea_wall.texture || !mlx->no_wall.texture || !mlx->so_wall.texture
		|| !mlx->we_wall.texture)
		return (0);
	return (1);
}
