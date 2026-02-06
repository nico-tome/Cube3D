/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:57:54 by ntome             #+#    #+#             */
/*   Updated: 2026/01/23 15:11:32 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include <fcntl.h>
# include "vector2.h"
# include "../lib/libft/libft.h"

# define SPAWNS "NSEW"
# define TILES "10 "

typedef struct	s_map
{
	int		size;
	char	**map;
}				t_map;

typedef struct	s_parsing_infos
{
	t_map	map;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*floor_color;
	char	*ceiling_color;
	char	**raw_datas;
	char	*file_extension;
	int		file_size;
	int		fd;
	int		result;
}				t_parsing_infos;

void	parsing(t_parsing_infos *parsing_i, char *path);
int		get_file_size(char *path);
char	*get_extension(char *path);
char	**load_file(int fd, int file_size);
void	try_read_datas(t_parsing_infos *parsing_i);
int		skip_ws(char *str);
void	update_infos(t_parsing_infos *parsing_i, const char *key, char *line);
void	load_map(t_parsing_infos *parsing_i, int line);
int		check_datas(t_parsing_infos *parsing_i);
int		check_close(char **map);
void	free_parsing(t_parsing_infos *parsing_i);

#endif
