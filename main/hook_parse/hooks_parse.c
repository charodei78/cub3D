/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheimerd <hheimerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:56:40 by hheimerd          #+#    #+#             */
/*   Updated: 2020/09/25 14:39:38 by hheimerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void					moove_to(t_map *map, t_player *player, float x,
	float y)
{
	if (!ft_strchr("03",
		map->map[(int)(player->y + y * 3)][(int)(player->x + x * 3)]) ||
		!ft_strchr("03", map->map[(int)(player->y + y)][(int)(player->x + x)]))
		return ;
	player->y += y;
	player->x += x;
}

int							rotate_view(int x, int y, t_vars *vars)
{
	int						i;

	if (y > vars->y - 1 || y < -vars->y - 1)
		return (0);
	vars->mouse_x = x;
	vars->mouse_y = y;
	x = vars->x - x;
	x = x < 0 ? abs(vars->x + x % vars->x) : x;
	i = 0;
	clear_world(vars);
	vars->player->pow_x = 2 * M_PI - fabs((fmod(x, vars->x) / vars->x)
		* 2 * M_PI);
	while (i <= vars->x)
	{
		vars->player->pow_fov = vars->player->pow_x -
		(M_PI / 3) / 2 + (M_PI / 3) * i / (float)(vars->x);
		find_range(vars->player, vars->x - i++, vars);
	}
	if (vars->x >= 500 && vars->y >= 500)
		draw_map(vars);
	if (vars->img->snap)
		do_snap(vars);
	mpitw(vars);
	return (0);
}

int							k_hook_parse(int keycode, t_vars *vars)
{
	float					x;
	float					y;
	static float			c;
	float					pow_tmp;

	if (!c)
		c = 0.04;
	if (keycode == 257)
		c = c < 0.1 ? 0.1 : 0.04;
	if (keycode == 53)
		exit(0);
	pow_tmp = keycode == 13 || keycode == 1 ?
		vars->player->pow_x : vars->player->pow_x - 6.28 / 4;
	x = vars->player->x + c * cos(pow_tmp) - vars->player->x;
	y = vars->player->y + c * sin(pow_tmp) - vars->player->y;
	if (keycode == 13 || keycode == 0)
		moove_to(vars->map, vars->player, x, y);
	if (keycode == 2 || keycode == 1)
		moove_to(vars->map, vars->player, -x, -y);
	if (keycode == 123 || keycode == 124)
		vars->mouse_x = vars->mouse_x + (keycode == 123 ? -20 : 20);
	rotate_view(vars->mouse_x, vars->mouse_y, vars);
	return (0);
}
