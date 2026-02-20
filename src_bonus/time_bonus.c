/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:58:03 by ntome             #+#    #+#             */
/*   Updated: 2026/02/20 09:28:25 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

long long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec / 1000 + time.tv_sec * 1000);
}

void	save_infos(t_mlx *mlx, int fd)
{
	char	*line;

	line = ft_strjoin("NO ", mlx->game_infos.no);
	write(fd, line, ft_strlen(line));
	free(line);
	write(fd, "\n", 1);
	line = ft_strjoin("SO ", mlx->game_infos.so);
	write(fd, line, ft_strlen(line));
	free(line);
	write(fd, "\n", 1);
	line = ft_strjoin("WE ", mlx->game_infos.we);
	write(fd, line, ft_strlen(line));
	free(line);
	write(fd, "\n", 1);
	line = ft_strjoin("EA ", mlx->game_infos.ea);
	write(fd, line, ft_strlen(line));
	free(line);
	write(fd, "\n", 1);
	line = ft_strjoin("F ", mlx->game_infos.floor);
	write(fd, line, ft_strlen(line));
	free(line);
	write(fd, "\n", 1);
	line = ft_strjoin("C ", mlx->game_infos.ceiling);
	write(fd, line, ft_strlen(line));
	free(line);
}

void	save_map(t_mlx *mlx)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(mlx->file_path, O_WRONLY);
	if (fd != -1)
	{
		save_infos(mlx, fd);
		write(fd, "\n", 1);
		write(fd, "\n", 1);
		i = 0;
		while (i < mlx->map.size)
		{
			line = ft_strjoin(mlx->map.map[i], "\n");
			write(fd, line, ft_strlen(line));
			free(line);
			i++;
		}
		close(fd);
		printf("Map saved successfully at %s!\n", mlx->file_path);
	}
}

void	animate_sprite(t_mlx *mlx)
{
	if ((int)(mlx->time / 1000) % 4 == 1)
		mlx_put_transformed_image_to_window(mlx->mlx, mlx->win,
			mlx->textures.no_wall.texture, 15, 15, 2.0f, 2.0f, 0);
	else if ((int)(mlx->time / 1000) % 4 == 2)
		mlx_put_transformed_image_to_window(mlx->mlx, mlx->win,
			mlx->textures.so_wall.texture, 15, 15, 2.0f, 2.0f, 0);
	else if ((int)(mlx->time / 1000) % 4 == 3)
		mlx_put_transformed_image_to_window(mlx->mlx, mlx->win,
			mlx->textures.ea_wall.texture, 15, 15, 2.0f, 2.0f, 0);
	else
		mlx_put_transformed_image_to_window(mlx->mlx, mlx->win,
			mlx->textures.we_wall.texture, 15, 15, 2.0f, 2.0f, 0);
}
