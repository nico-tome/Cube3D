/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:42:36 by ntome             #+#    #+#             */
/*   Updated: 2026/02/09 14:58:56 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"
#include "vector2_bonus.h"

int	need_to_check(char c)
{
	if (c == '0')
		return (1);
	else if (c == 'N')
		return (1);
	else if (c == 'S')
		return (1);
	else if (c == 'W')
		return (1);
	else if (c == 'E')
		return (1);
	return (0);
}

int	check(char **map, t_vec2 reader)
{
	if (reader.x == 0 || reader.y == 0)
		return (0);
	if (map[reader.y][reader.x + 1] == ' ')
		return (0);
	if (!map[reader.y + 1] || !map[reader.y][reader.x + 1])
		return (0);
	if (map[reader.y + 1][reader.x] == ' ')
		return (0);
	if (map[reader.y - 1][reader.x] == ' ')
		return (0);
	if (map[reader.y][reader.x - 1] == ' ')
		return (0);
	return (1);
}

int	check_close(char **map)
{
	t_vec2	reader;

	reader.y = 0;
	while (map[reader.y])
	{
		reader.x = 0;
		while (map[reader.y][reader.x])
		{
			if (need_to_check(map[reader.y][reader.x]))
			{
				if (!check(map, reader))
				{
					printf("Error\nMap not close %d;%d\n", reader.y, reader.x);
					return (0);
				}
			}
			reader.x++;
		}
		reader.y++;
	}
	return (1);
}
