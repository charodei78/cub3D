/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheimerd <hheimerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:32:55 by hheimerd          #+#    #+#             */
/*   Updated: 2020/09/23 16:08:39 by hheimerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void			img_init(void *mlx_ptr, t_data *img, int width, int height)
{
	img->img = mlx_new_image(mlx_ptr, width, height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len,
		&img->endian);
}

void			pixel_put(t_data *img, int x, int y, int color)
{
	char		*dst;

	dst = img->addr + (y * img->len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

unsigned int	get_pixel(t_data *img, int x, int y)
{
	return (*(unsigned int*)(img->addr + (y * img->len + x * (img->bpp / 8))));
}

int				pixel_put_s(t_color *pix)
{
	char		*dst;

	dst = pix->img->addr + (pix->y * pix->img->len + pix->x *
		(pix->img->bpp / 8));
	*(unsigned int*)dst = pix->color;
	return (1);
}

int				mpitw(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img,
		0, 0);
	mlx_string_put(vars->mlx, vars->win, vars->x / 2,
		vars->y / 2, rgba(100, 250, 100, 1), "+");
	return (0);
}
