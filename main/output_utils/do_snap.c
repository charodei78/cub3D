/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_snap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheimerd <hheimerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:08:37 by hheimerd          #+#    #+#             */
/*   Updated: 2020/09/26 17:06:48 by hheimerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void						set_int_in_char(unsigned char *start, int value)
{
	start[0] = (value);
	start[1] = (value >> 8);
	start[2] = (value >> 16);
	start[3] = (value >> 24);
}

static int						write_header(int fd, int fsize, t_vars *vars)
{
	static unsigned char		header[54] = {66, 77, 0, 0, 0, 0, 0, 0, 0, 0,
		54, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24};

	set_int_in_char(header + 2, fsize);
	set_int_in_char(header + 18, vars->x);
	set_int_in_char(header + 22, vars->y);
	return (!(write(fd, header, 54) < 0));
}

static int						write_data(int fd, t_vars *vars)
{
	int							i;
	int							j;
	int							color;

	i = vars->y;
	while (i--)
	{
		j = 0;
		while (j < vars->x)
		{
			color = get_pixel(vars->img, j, i);
			if (write(fd, &color, 3) < 0)
				return (0);
			j++;
		}
	}
	return (1);
}

void							do_snap(t_vars *vars)
{
	int							fsize;
	int							fd;

	vars->x -= vars->x % 4;
	vars->y -= vars->y % 4;
	fsize = 54 + (3 * vars->x) * vars->y;
	if ((fd = open("screen.bmp", O_WRONLY | O_CREAT, S_IRWXU, S_IRWXG)) < 0)
		exit(ft_put_error("Error\nScreenshot create faled", 1));
	if (!write_header(fd, fsize, vars))
		exit(ft_put_error("Error\nScreenshot faled", 1));
	if (!write_data(fd, vars))
		exit(ft_put_error("Error\nScreenshot faled", 1));
	close(fd);
	exit(0);
}
