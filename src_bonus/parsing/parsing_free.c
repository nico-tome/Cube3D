/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <nicolas@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:35:36 by ntome             #+#    #+#             */
/*   Updated: 2026/02/07 15:40:44 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_paths(t_parsing_infos *parsing_i)
{
	if (parsing_i->no_path)
		free(parsing_i->no_path);
	if (parsing_i->so_path)
		free(parsing_i->so_path);
	if (parsing_i->we_path)
		free(parsing_i->we_path);
	if (parsing_i->ea_path)
		free(parsing_i->ea_path);
	if (parsing_i->ceiling_color)
		free(parsing_i->ceiling_color);
	if (parsing_i->floor_color)
		free(parsing_i->floor_color);
	if (parsing_i->file_extension)
		free(parsing_i->file_extension);
}

void	free_raw_datas(t_parsing_infos *parsing_i)
{
	int	i;

	i = 0;
	while (parsing_i->raw_datas && parsing_i->raw_datas[i])
	{
		free(parsing_i->raw_datas[i]);
		i++;
	}
	if (parsing_i->raw_datas)
		free(parsing_i->raw_datas);
}

void	free_map(t_parsing_infos *parsing_i)
{
	int	i;

	i = 0;
	while (parsing_i->map.map && parsing_i->map.map[i])
	{
		free(parsing_i->map.map[i]);
		i++;
	}
	if (parsing_i->map.map)
		free(parsing_i->map.map);
}

void	free_parsing(t_parsing_infos *parsing_i)
{
	free_paths(parsing_i);
	free_raw_datas(parsing_i);
	free_map(parsing_i);
	if (parsing_i->fd > 0)
		close(parsing_i->fd);
}
