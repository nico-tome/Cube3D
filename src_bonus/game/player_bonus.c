/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 10:29:14 by ntome             #+#    #+#             */
/*   Updated: 2026/02/27 14:59:25 by ntome            ###   ########.fr       */
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
		if (mlx->doors[i].pos.x == (int)new_x
			&& mlx->doors[i].pos.y == (int)new_y
			&& mlx->doors[i].open == 0 && !mlx->doors[i].disabled)
			is_door_blocked = 1;
		i++;
	}
	if ((int)ft_strlen(mlx->map.map[(int)new_y]) < (int)new_x)
		return ;
	if (!ft_strchr("1 \0", mlx->map.map[(int)new_y][(int)new_x])
		&& !is_door_blocked)
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
	if ((rot_s == 0 && mlx->page == GAME)
		|| (mlx->page == EDITOR && mlx->mouse.y < mlx->window_size.y / 2
			&& rot_s == 0))
	{
		mlx_mouse_get_pos(mlx->mlx, &mlx->mouse.x, &mlx->mouse.y);
		rot_s = ROT_SPEED * ((mlx->mouse.x - mlx->old_mouse.x) * 0.07);
		mlx_mouse_move(mlx->mlx, mlx->win,
			mlx->window_size.x / 2, mlx->mouse.y);
		mlx_mouse_get_pos(mlx->mlx, &mlx->old_mouse.x, &mlx->old_mouse.y);
	}
	mlx->player.rot.x = rot.x * cos(rot_s) - rot.y * sin(rot_s);
	mlx->player.rot.y = old_d.x * sin(rot_s) + rot.y * cos(rot_s);
	mlx->player.plane.x = plane.x * cos(rot_s) - plane.y * sin(rot_s);
	mlx->player.plane.y = old_p.x * sin(rot_s) + plane.y * cos(rot_s);
}

void	move_player(t_mlx *mlx)
{
	if (mlx->editor.broken > 0)
		return;
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
