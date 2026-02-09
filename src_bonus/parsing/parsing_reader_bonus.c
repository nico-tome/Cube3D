/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_reader_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:26:55 by ntome             #+#    #+#             */
/*   Updated: 2026/02/09 15:00:58 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

int	skip_ws(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] <= ' ')
		i++;
	return (i);
}

char	*extract_value(char *str, const char *key)
{
	int		i;
	char	*value;

	i = skip_ws(str);
	i += ft_strlen(key);
	i += skip_ws(str + i);
	value = ft_substr(str, i, (ft_strlen(str) - 1) - i);
	return (value);
}

void	update_infos(t_parsing_infos *parsing_i, const char *key, char *line)
{
	if (!key[0])
		return ;
	if (!ft_strncmp(key, "NO", 2))
		parsing_i->no_path = extract_value(line, key);
	else if (!ft_strncmp(key, "SO", 2))
		parsing_i->so_path = extract_value(line, key);
	else if (!ft_strncmp(key, "EA", 2))
		parsing_i->ea_path = extract_value(line, key);
	else if (!ft_strncmp(key, "WE", 2))
		parsing_i->we_path = extract_value(line, key);
	else if (!ft_strncmp(key, "C", 1))
		parsing_i->ceiling_color = extract_value(line, key);
	else if (!ft_strncmp(key, "F", 1))
		parsing_i->floor_color = extract_value(line, key);
}

void	load_map(t_parsing_infos *parsing_i, int line)
{
	int	i;
	int	line_len;

	i = 0;
	while (parsing_i->raw_datas[line + i])
		i++;
	parsing_i->map.size = i;
	if (i == 0)
		return ;
	parsing_i->map.map = malloc(sizeof(char *) * (i + 1));
	if (!parsing_i->map.map)
	{
		printf("Malloc error in parsing_reader.c at line 25.\n");
		return ;
	}
	i = 0;
	while (parsing_i->raw_datas[line + i])
	{
		line_len = ft_strlen(parsing_i->raw_datas[line + i]) - 1;
		parsing_i->map.map[i] = ft_substr(parsing_i->raw_datas[line + i],
				0, line_len);
		i++;
	}
	parsing_i->map.map[i] = NULL;
}
