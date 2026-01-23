/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:19:31 by ntome             #+#    #+#             */
/*   Updated: 2026/01/23 14:53:46 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "parsing.h"
#include "vector2.h"
#include "texture.h"

void	init_event(t_mlx *mlx)
{
	mlx_on_event(mlx->mlx, mlx->win, MLX_WINDOW_EVENT, window_hook, mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_KEYDOWN, key_hook, mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_MOUSEDOWN, mouse_hook, mlx);
}

void	loop(void *params)
{
	t_mlx	*mlx;

	mlx = params;
	render_floor_ceiling(mlx, mlx->window_size.x, mlx->window_size.y / 2);
}

void	init_app(t_parsing_infos parsing_i)
{
	t_mlx					mlx;
	mlx_window_create_info	infos;

	mlx.mlx = mlx_init();
	infos = (mlx_window_create_info){0};
	infos.title = "Cube3D";
	infos.width = 1280;
	infos.height = 720;
	mlx.win = mlx_new_window(mlx.mlx, &infos);
	set_vec2(&mlx.window_size, 1280, 720);
	init_textures(&mlx, &parsing_i);
	init_player(&mlx, &parsing_i);
	init_event(&mlx);
	free_parsing(&parsing_i);
	mlx_add_loop_hook(mlx.mlx, loop, &mlx);
	mlx_loop(mlx.mlx);
	free_game(&mlx);
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_context(mlx.mlx);
}

int	main(int ac, char **av)
{
	t_parsing_infos	parsing_i;

	if (ac != 2)
	{
		printf("ARGS ERROR !\n");
		exit(EXIT_FAILURE);
	}
	parsing(&parsing_i, av[1]);
	if (!parsing_i.result)
	{
		free_parsing(&parsing_i);
		printf("PARSING ERROR !\n");
		exit(EXIT_FAILURE);
	}
	init_app(parsing_i);
}
