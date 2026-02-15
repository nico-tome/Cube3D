/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 10:29:14 by ntome             #+#    #+#             */
/*   Updated: 2026/02/09 12:35:59 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d_bonus.h>
#include <keys_bonus.h>

static void	try_move(t_mlx *mlx, double dx, double dy)
{
	double	new_x;
	double	new_y;
	int		i;
	int		is_door_blocked;

	new_x = mlx->player.pos.x + dx;
	new_y = mlx->player.pos.y + dy;
	is_door_blocked = 0;
	i = 0;
	while (i < mlx->door_count)
	{
		if (mlx->doors[i].x == (int)new_x && mlx->doors[i].y == (int)new_y
			&& mlx->doors[i].open == 0)
			is_door_blocked = 1;
		i++;
	}
	if (mlx->map.map[(int)new_y][(int)new_x] != '1' && !is_door_blocked)
	{
		mlx->player.pos.x = new_x;
		mlx->player.pos.y = new_y;
	}
}

static	void	update_plane(t_mlx *mlx)
{
	t_dvec2	old_d;
	t_dvec2	old_p;
	t_dvec2	plane;
	t_dvec2	rot;
	double	rot_s;

	rot = mlx->player.rot;
	plane = mlx->player.plane;
	old_d = mlx->player.rot;
	old_p = mlx->player.plane;
	rot_s = ROT_SPEED * (mlx->keys[KEY_RIGHT] - mlx->keys[KEY_LEFT]);
	mlx->player.rot.x = rot.x * cos(rot_s) - rot.y * sin(rot_s);
	mlx->player.rot.y = old_d.x * sin(rot_s) + rot.y * cos(rot_s);
	mlx->player.plane.x = plane.x * cos(rot_s) - plane.y * sin(rot_s);
	mlx->player.plane.y = old_p.x * sin(rot_s) + plane.y * cos(rot_s);
}

void	move_player(t_mlx *mlx)
{
	if (mlx->keys[KEY_W])
		try_move(mlx, mlx->player.rot.x * SPEED,
			mlx->player.rot.y * SPEED);
	if (mlx->keys[KEY_S])
		try_move(mlx, -mlx->player.rot.x * SPEED,
			-mlx->player.rot.y * SPEED);
	if (mlx->keys[KEY_A])
		try_move(mlx, -mlx->player.plane.x * SPEED,
			-mlx->player.plane.y * SPEED);
	if (mlx->keys[KEY_D])
		try_move(mlx, mlx->player.plane.x * SPEED,
			mlx->player.plane.y * SPEED);
	update_plane(mlx);
}
