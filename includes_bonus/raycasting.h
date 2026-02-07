/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 21:03:39 by ntome             #+#    #+#             */
/*   Updated: 2026/02/07 11:39:43 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "texture.h"
# include "vector2.h"
# include "cube3d.h"
# include "../lib/MacroLibX/includes/mlx.h"
# include "../lib/MacroLibX/includes/mlx_extended.h"

typedef struct s_ray
{
	double	camera_x;
	double	perp_wall_dist;
	t_dvec2	ray_dir;
	t_vec2	map_pos;
	t_dvec2	side_dist;
	t_dvec2	delta_dist;
	t_vec2	step;
	int		hit;
	int		side;
	int		draw;
}				t_ray;

typedef struct s_drawing
{
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		step;
	double		wall_x;
	t_vec2		tex;
	t_texture	texture;
	double		tex_pos;
}				t_drawing;

void		init_side_dist(t_mlx *mlx, t_ray *ray);
int			check_ray_side(t_ray *ray);
double		get_tex_pos(t_mlx *mlx, t_drawing *draw);
mlx_color	get_tex_color(t_mlx *mlx, t_drawing *draw);

#endif
