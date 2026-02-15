/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:19:31 by ntome             #+#    #+#             */
/*   Updated: 2026/02/10 00:32:48 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"
#include "parsing_bonus.h"
#include "vector2_bonus.h"
#include "texture_bonus.h"
#include <stdlib.h>
#include <unistd.h>

long long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec / 1000 + time.tv_sec * 1000);
}

void	init_event(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 255)
	{
		mlx->keys[i] = 0;
		i++;
	}
	mlx_on_event(mlx->mlx, mlx->win, MLX_WINDOW_EVENT, window_hook, mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_KEYDOWN, key_hook, mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_KEYUP, key_up_hook, mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_MOUSEDOWN, mouse_hook, mlx);
}

void	loop(void *params)
{
	char	*fps;
	t_mlx	*mlx;

	mlx = params;
	mlx->old_time = mlx->time;
	mlx->time = ft_get_time();
	fps = ft_itoa(1 / ((mlx->time - mlx->old_time) / 1000));
	move_player(mlx);
	mlx_clear_window(mlx->mlx, mlx->win, (mlx_color){.rgba = 0x00FF00FF});
	raycasting(mlx);
	draw_minimap(mlx, &mlx->game_infos, &mlx->player);
	mlx_string_put(mlx->mlx, mlx->win, mlx->window_size.x - 100, 50,
		(mlx_color){.rgba = COLOR_RED}, fps);
	free(fps);
}

void	init_app(t_parsing_infos *parsing_i)
{
	t_mlx					mlx;
	mlx_window_create_info	infos;

	mlx.mlx = mlx_init();
	infos = (mlx_window_create_info){.width = 1280, .height = 720};
	infos.title = "Cube3D";
	mlx.win = mlx_new_window(mlx.mlx, &infos);
	mlx.map = parsing_i->map;
	mlx.keys[255] = 1;
	mlx.time = ft_get_time();
	set_vec2(&mlx.window_size, 1280, 720);
	init_map(&mlx, parsing_i);
	if (!init_textures(&mlx, parsing_i))
	{
		printf("Error\nA texture path do not link a texture file.\n");
		free_mlx(&mlx);
		free_parsing(parsing_i);
		return ;
	}
	init_player(&mlx, parsing_i);
	init_event(&mlx);
	mlx_add_loop_hook(mlx.mlx, loop, &mlx);
	mlx_loop(mlx.mlx);
	free_parsing(parsing_i);
	free_mlx(&mlx);
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
		exit(EXIT_FAILURE);
	}
	init_app(&parsing_i);
}
