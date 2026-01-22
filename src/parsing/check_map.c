/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:42:36 by ntome             #+#    #+#             */
/*   Updated: 2026/01/22 14:02:11 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_close(char **map)
{
	t_vec2	reader;

	reader.y = 0;
	while (map[reader.y])
	{
		reader.x = 0;
		if (map[reader.y][reader.x] == '0')
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
		}
		reader.y++;
	}
	return (1);
}
