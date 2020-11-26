/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheimerd <hheimerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 18:36:35 by hheimerd          #+#    #+#             */
/*   Updated: 2020/09/20 15:10:22 by hheimerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int				map_color(int x, int y, t_vars *vars)
{
	if ((int)vars->player->x == x && (int)vars->player->y == y)
		return (rgba(240, 240, 240, 1));
	if (ft_strchr("13", vars->map->map[y][x]))
		return (vars->map->color);
	else if (vars->map->map[y][x] == '2')
		return (rgba(100, 10, 10, 1));
	else
		return (rgba(0, 0, 0, 1));
	return (0);
}

void			draw_map(t_vars *vars)
{
	int			hw[2];
	t_shape		params;
	int			yx[2];

	params.size_x = 10;
	params.size_y = 10;
	hw[0] = 0;
	while (++hw[0] < 20)
	{
		yx[0] = (int)vars->player->y - hw[0] + 10;
		if (yx[0] >= vars->map->height || yx[0] < 0)
			continue ;
		hw[1] = 0;
		while (++hw[1] < 20)
		{
			yx[1] = (int)vars->player->x - hw[1] + 10;
			if (yx[1] < 0 || yx[1] >= vars->map->len)
				continue ;
			params.x = (20 - hw[1]) * params.size_x;
			params.y = (20 - hw[0]) * params.size_y;
			params.color = map_color(yx[1], yx[0], vars);
			if (vars->map->map[yx[0]][yx[1]] != ' ')
				put_rect(vars, &params);
		}
	}
}
