/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:22:41 by ntome             #+#    #+#             */
/*   Updated: 2026/02/07 14:59:43 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include "../lib/MacroLibX/includes/mlx.h"
# include "../lib/MacroLibX/includes/mlx_extended.h"
# include "../lib/libft/libft.h"
# include "parsing.h"
# include "texture.h"
# include "vector2.h"
# include "parsing.h"

# define SPEED 0.2
# define ROT_SPEED 0.05

typedef struct s_game_infos
{
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	mlx_color	*floor;
	mlx_color	*ceiling;
}				t_game_infos;

typedef struct s_player
{
	t_dvec2	pos;
	t_dvec2	rot;
	t_dvec2	plane;
	int		vel;
}				t_player;

typedef struct s_mlx
{
	mlx_context		mlx;
	mlx_window		win;
	t_vec2			window_size;
	t_game_infos	game_infos;
	t_player		player;
	t_texture		no_wall;
	t_texture		so_wall;
	t_texture		ea_wall;
	t_texture		we_wall;
	t_map			map;
	mlx_color		floor;
	mlx_color		ceiling;
	mlx_color		*draw_line;
	double			time;
	double			old_time;
	int				keys[256];
}				t_mlx;

void	init_player(t_mlx *mlx, t_parsing_infos *parsing);
void	init_map(t_mlx *mlx, t_parsing_infos *parsing);
void	key_hook(int key, void *param);
void	key_up_hook(int key, void *param);
void	mouse_hook(int button, void *param);
void	window_hook(int event, void *param);
void	free_game(t_mlx *mlx);
void	raycasting(t_mlx *mlx);
void	move_player(t_mlx *mlx);
int		init_textures(t_mlx *mlx, t_parsing_infos *parsing);
void	free_mlx(t_mlx *mlx);

#endif
