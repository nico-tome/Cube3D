/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:22:41 by ntome             #+#    #+#             */
/*   Updated: 2026/02/10 00:32:27 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_BONUS_H
# define CUBE3D_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include "../lib/MacroLibX/includes/mlx.h"
# include "../lib/MacroLibX/includes/mlx_extended.h"
# include "../lib/libft/libft.h"
# include "parsing_bonus.h"
# include "texture_bonus.h"
# include "vector2_bonus.h"
# include "parsing_bonus.h"

# define COLOR_BLACK	0x000000FF
# define COLOR_RED		0xFF0000FF
# define COLOR_GREEN	0x00FF00FF
# define SPEED 0.2
# define ROT_SPEED 0.05
# define MAX_DOORS 64

typedef struct s_door
{
	int	x;
	int	y;
	int	open;
}	t_door;

typedef struct s_game_infos
{
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
}				t_game_infos;

typedef struct s_player
{
	t_dvec2	pos;
	t_dvec2	rot;
	t_dvec2	plane;
	int		vel;
}				t_player;

typedef struct s_textures_set
{
	t_texture		no_wall;
	t_texture		so_wall;
	t_texture		ea_wall;
	t_texture		we_wall;
	t_texture		floor;
	t_texture		ceiling;
}				t_textures_set;

typedef struct s_mlx
{
	mlx_context		mlx;
	mlx_window		win;
	t_vec2			window_size;
	t_game_infos	game_infos;
	t_player		player;
	t_textures_set	textures;
	t_map			map;
	mlx_color		floor_color;
	mlx_color		ceiling_color;
	mlx_color		*draw_line;
	double			time;
	double			old_time;
	int				keys[256];
	t_door			doors[MAX_DOORS];
	int				door_count;
}				t_mlx;

void	init_map(t_mlx *mlx, t_parsing_infos *parsing);
void	key_hook(int key, void *param);
void	key_up_hook(int key, void *param);
void	mouse_hook(int button, void *param);
void	window_hook(int event, void *param);
void	free_game(t_mlx *mlx);
void	raycasting(t_mlx *mlx);
void	move_player(t_mlx *mlx);
int		init_textures(t_mlx *mlx, t_parsing_infos *parsing);
void	init_doors(t_mlx *mlx);
void	toggle_door(t_mlx *mlx);
void	init_player(t_mlx *mlx, t_parsing_infos *parsing);
void	draw_minimap(t_mlx *mlx, t_game_infos *game, t_player *player);
void	free_mlx(t_mlx *mlx);

#endif
