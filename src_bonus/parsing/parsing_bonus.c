/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 12:02:23 by ntome             #+#    #+#             */
/*   Updated: 2026/02/09 14:59:14 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

void	set_parser_infos(t_parsing_infos *parsing_i)
{
	parsing_i->ea_path = NULL;
	parsing_i->no_path = NULL;
	parsing_i->so_path = NULL;
	parsing_i->we_path = NULL;
	parsing_i->ceiling_color = NULL;
	parsing_i->floor_color = NULL;
	parsing_i->raw_datas = NULL;
	parsing_i->file_size = 0;
	parsing_i->file_extension = NULL;
	parsing_i->map.size = 0;
	parsing_i->map.map = NULL;
}

void	load_datas(t_parsing_infos *parsing_i, char *path)
{
	parsing_i->file_extension = get_extension(path);
	parsing_i->file_size = get_file_size(path);
	parsing_i->fd = open(path, O_RDONLY);
	parsing_i->raw_datas = load_file(parsing_i->fd, parsing_i->file_size);
	if (parsing_i->raw_datas != NULL)
		try_read_datas(parsing_i);
}

void	parsing(t_parsing_infos *parsing_i, char *path)
{
	set_parser_infos(parsing_i);
	load_datas(parsing_i, path);
	if (parsing_i->raw_datas != NULL)
		parsing_i->result = check_datas(parsing_i);
	else
	{
		parsing_i->result = 0;
		printf("Error\n'%s' can't be open !\n", path);
	}
}
