/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheimerd <hheimerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:45:56 by hheimerd          #+#    #+#             */
/*   Updated: 2020/09/25 13:24:42 by hheimerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void			draw_sprite(t_vars *vars, t_shape *params)
{
	int			tmp_x;
	int			tmp_y;
	float		k;

	k = (float)params->img->height / (float)params->size_y;
	tmp_y = params->size_y + 1;
	while (--tmp_y > 0)
	{
		if (tmp_y + params->y < 0 || tmp_y + params->y > vars->y || tmp_y * k
			> params->img->height - 1)
			continue ;
		tmp_x = params->size_x + 1;
		while (--tmp_x > 0)
		{
			if (tmp_x + params->x < 0 || tmp_x + params->x > vars->x ||
				(params->offset - tmp_x) * k > params->img->width / 2 ||
				(params->offset - tmp_x) * k < -params->img->width / 2)
				continue ;
			params->color = get_pixel(params->img,
			(params->offset - tmp_x) * k + params->img->width / 2, tmp_y * k);
			if (get_t(params->color) != (0xFF << 24))
				pixel_put(vars->img, tmp_x
				+ params->x, tmp_y + params->y, params->color);
		}
	}
}

void			put_rect_text(t_vars *vars, t_shape *params)
{
	int			tmp_x;
	int			tmp_y;
	float		kxy[2];

	kxy[0] = (float)params->img->width / (float)params->size_y;
	kxy[1] = (float)params->img->height / (float)params->size_y;
	tmp_y = params->size_y + 1;
	while (--tmp_y > 0)
	{
		if (tmp_y + params->y < 0 || tmp_y + params->y >= vars->y)
			continue ;
		tmp_x = params->size_x + 1;
		while (--tmp_x > 0)
		{
			if (tmp_x + params->x < 0 || tmp_x + params->x >= vars->x)
				continue ;
			if (params->offset < 0 || params->offset > 1)
				continue ;
			params->color = get_pixel(params->img,
				params->img->width * params->offset, (tmp_y) * kxy[1] - 1);
			if (get_t(params->color) != (0xFF << 24))
				pixel_put(vars->img, tmp_x
				+ params->x, tmp_y + params->y, params->color);
		}
	}
}

int				put_rect(t_vars *vars, t_shape *params)
{
	int			tmp_x;
	int			tmp_y;

	tmp_y = params->size_y + 1;
	while (--tmp_y > 0)
	{
		if (tmp_y + params->y < 0 || tmp_y + params->y > vars->y)
			continue ;
		tmp_x = params->size_x + 1;
		while (--tmp_x > 0)
		{
			if (tmp_x + params->x < 0 || tmp_x + params->x > vars->x)
				continue ;
			pixel_put(vars->img, tmp_x
				+ params->x, tmp_y + params->y, params->color);
		}
	}
	return (0);
}

int				clear_world(t_vars *vars)
{
	t_shape		plane;
	unsigned	tmp;

	if (vars->mouse_y > vars->y)
		tmp = vars->y / 2;
	else
		tmp = vars->y / 2 - vars->mouse_y % vars->y;
	if (tmp < 0)
		tmp = 0;
	plane.size_y = tmp;
	plane.size_x = vars->x;
	plane.x = 0;
	plane.y = 0;
	plane.color = vars->roof;
	put_rect(vars, &plane);
	plane.y = tmp;
	plane.size_y = vars->y - tmp - 2;
	plane.color = vars->floor;
	put_rect(vars, &plane);
	return (0);
}
