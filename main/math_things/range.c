/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheimerd <hheimerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 22:31:08 by hheimerd          #+#    #+#             */
/*   Updated: 2020/09/25 14:41:40 by hheimerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void					find_sprite(float xy_dx_dy[], t_player *player,
														t_vars *vars, int i)
{
	float				params[5];
	static float		prev_res;
	t_shape				wall;

	params[0] = player->x - (int)xy_dx_dy[0] - 0.5;
	params[1] = player->y - (int)xy_dx_dy[1] - 0.5;
	params[4] = sqrt((pow(params[0], 2) + pow(params[1], 2)));
	params[2] = atan2(params[1], params[0]) + M_PI;
	params[3] = tan(params[2] - player->pow_fov) * params[4];
	if (prev_res != params[3])
	{
		prev_res = params[3];
		wall.img = vars->sprite;
		wall.offset = params[3] * (vars->x / 2) /
		(params[4] * cos(vars->player->pow_x - vars->player->pow_fov));
		wall.size_x = 1;
		wall.size_y = (vars->x / 2) / (params[4] * cos(vars->player->pow_x -
			vars->player->pow_fov)) * wall.img->height / 2000;
		wall.y = (float)(vars->y - wall.size_y) / 2 - vars->mouse_y;
		wall.x = abs(vars->x - i);
		draw_sprite(vars, &wall);
	}
}

static void				set_wall_params(t_shape *wall, t_vars *vars, int i,
															float xy_dx_dy[])
{
	wall->size_x = 1;
	wall->x = abs(vars->x - i);
	wall->y = (float)(vars->y - wall->size_y) / 2 - vars->mouse_y;
	if (xy_dx_dy[3] == 1 && xy_dx_dy[2] == 0)
		wall->img = vars->north;
	else if (xy_dx_dy[3] == 0 && xy_dx_dy[2] == 1)
		wall->img = vars->west;
	else if (xy_dx_dy[3] == -1 && xy_dx_dy[2] == 0)
		wall->img = vars->south;
	else if (xy_dx_dy[3] == 0 && xy_dx_dy[2] == -1)
		wall->img = vars->east;
}

static t_shape			*write_wall(float range, float xy_dx_dy[], int i,
	t_vars *vars)
{
	static t_shape		*wall;
	int					x;
	int					y;
	static float		offset;

	if (!wall)
		if (!(wall = (t_shape*)malloc(sizeof(t_shape))))
			exit(ft_put_error("Error\nMemory allocation error", 1));
	x = xy_dx_dy[2];
	y = xy_dx_dy[3];
	range = (vars->x / 2) / (range * cos((vars->player->pow_x - 0.005236) -
		vars->player->pow_fov));
	if (x == 1 || x == -1)
		offset = fmod(xy_dx_dy[1], 1);
	else
		offset = fmod(xy_dx_dy[0], 1);
	wall->size_y = range;
	wall->offset = offset;
	set_wall_params(wall, vars, i, xy_dx_dy);
	return (wall);
}

static	void			ray_back(float c, float xyd[], t_vars *vars, int i)
{
	while (c > 0)
	{
		xyd[0] = vars->player->x + c * cos(vars->player->pow_fov);
		xyd[1] = vars->player->y + c * sin(vars->player->pow_fov);
		if (vars->map->map[(int)xyd[1]][(int)xyd[0]] == '2')
			find_sprite(xyd, vars->player, vars, i);
		c -= 0.1;
	}
}

void					find_range(t_player *player, int i, t_vars *vars)
{
	float				xyd[5];
	float				c;
	float				prev_xy[2];

	c = -0.003;
	prev_xy[0] = 0;
	prev_xy[1] = 0;
	while ((c += 0.003) < 40)
	{
		xyd[0] = player->x + c * cos(player->pow_fov);
		xyd[1] = player->y + c * sin(player->pow_fov);
		xyd[4] = vars->map->map[(int)xyd[1]][(int)xyd[0]] == '2' ? 1 : xyd[4];
		if (!ft_strchr("02",
			vars->map->map[(int)xyd[1]][(int)xyd[0]]))
		{
			xyd[2] = (int)prev_xy[0] - (int)xyd[0];
			xyd[3] = (int)prev_xy[1] - (int)xyd[1];
			put_rect_text(vars, write_wall(c, xyd, i, vars));
			break ;
		}
		prev_xy[0] = xyd[0];
		prev_xy[1] = xyd[1];
	}
	if (xyd[4] == 1)
		ray_back(c, xyd, vars, i);
}
