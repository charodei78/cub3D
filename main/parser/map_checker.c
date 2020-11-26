/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheimerd <hheimerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 15:47:20 by hheimerd          #+#    #+#             */
/*   Updated: 2020/09/23 17:06:11 by hheimerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void			check_line(char *line, char *allow)
{
	while (*line)
	{
		if (!ft_strchr(allow, *line))
			exit(ft_put_error("Error\nIncorrect map value", 1));
		line++;
	}
}

static char		**norm_map(t_map *map)
{
	int			tmp_h;
	int			tmp_w;
	char		**res;

	if (!(res = ft_arrinit(map->height, map->len + 1)))
		exit(ft_put_error("Error\nMemory allocation error", 1));
	tmp_h = map->height;
	while (tmp_h--)
	{
		tmp_w = 0;
		while (tmp_w < map->len && map->map[tmp_h][tmp_w])
		{
			res[tmp_h][tmp_w] = is_space(map->map[tmp_h][tmp_w]) ? ' ' :
			map->map[tmp_h][tmp_w];
			tmp_w++;
		}
		free(map->map[tmp_h]);
		while (tmp_w < map->len)
		{
			res[tmp_h][tmp_w] = ' ';
			tmp_w++;
		}
		res[tmp_h][tmp_w] = '\0';
	}
	return (res);
}

static int		check_cross(char **map, int x, int y, t_vars *vars)
{
	if (map[y][x] == ' ' || map[y][x] == '1')
		return (1);
	if (!ft_strchr("023NEWS", map[y][x]))
		return (0);
	if (x <= 0 || x >= vars->map->len - 1 ||
		y <= 0 || y >= vars->map->height - 1)
		return (0);
	if (y + 1 <= vars->map->height - 1)
		if (!ft_strchr("0123NEWS", map[y + 1][x]))
			return (0);
	if (x + 1 <= vars->map->len - 1)
		if (!ft_strchr("0123NEWS", map[y][x + 1]))
			return (0);
	if (y - 1 >= 0)
		if (!ft_strchr("0123NEWS", map[y - 1][x]))
			return (0);
	if (x - 1 >= 0)
		if (!ft_strchr("0123NEWS", map[y][x - 1]))
			return (0);
	return (1);
}

static void		check_map(t_map *map, t_vars *vars)
{
	int			y;
	int			x;

	vars->player->x = 0;
	vars->player->y = 0;
	y = map->height;
	while (--y > -1)
	{
		x = -1;
		while (++x < map->len)
		{
			if (!check_cross(map->map, x, y, vars))
				exit(ft_put_error("Error\nIncorrect map value", 1));
			if (ft_strchr("NEWS", map->map[y][x]))
			{
				if (vars->player->x != 0 || vars->player->y != 0)
					exit(ft_put_error("Error\nIncorrect map player value", 1));
				vars->player->x = x + 0.5;
				vars->player->y = y + 0.5;
				vars->player->direction = map->map[y][x];
				map->map[y][x] = '0';
			}
		}
	}
}

void			map_parse(int fd, char *line, t_vars *vars)
{
	int			ret;
	int			len;

	vars->map->height = 0;
	vars->map->map[vars->map->height++] = ft_strdup(line);
	vars->map->len = ft_strlen(line);
	free(line);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (*line == 0)
			exit(ft_put_error("Error\nIncorrect map value", 1));
		vars->map->map[vars->map->height++] = ft_strdup(line);
		if ((len = ft_strlen(line)) > vars->map->len)
			vars->map->len = len;
		free(line);
	}
	if (ret == 0)
		vars->map->map[vars->map->height++] = ft_strdup(line);
	else
		exit(ft_put_error("Error\nIncorrect map value", 1));
	free(line);
	vars->map->color = rgba(163, 124, 125, 1);
	vars->map->map = norm_map(vars->map);
	check_map(vars->map, vars);
}
