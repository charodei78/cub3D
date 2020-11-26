/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheimerd <hheimerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 20:10:57 by hheimerd          #+#    #+#             */
/*   Updated: 2020/09/26 19:10:26 by hheimerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static	int		write_res(char *src, t_vars *vars)
{
	if (vars->x != 0 || vars->y != 0)
		exit(ft_put_error("Error\nDuplicate map parameters", 23));
	check_line(src, "1234567890 \t");
	while (is_space(*src) && *src)
		src++;
	vars->x = ft_atoi(src);
	while (ft_isdigit(*src))
		src++;
	while (is_space(*src) && *src)
		src++;
	vars->y = ft_atoi(src);
	while (ft_isdigit(*src))
		src++;
	while (*src)
		if (ft_isdigit(*(src++)))
			exit(ft_put_error("Error\nToo many resolution arguments", 500));
	if (vars->x > 2560)
		vars->x = 2560;
	if (vars->y > 1310)
		vars->y = 1310;
	if (vars->x < 100 || vars->y < 100)
		exit(ft_put_error("Error\nIncorrect_resolution_size", 500));
	return (1);
}

static	void	write_color(char *src, int *dest)
{
	int			res[3];
	int			counter[2];

	res[0] = 300;
	res[1] = 300;
	res[2] = 300;
	check_line(src, "1234567890, \t");
	counter[0] = 0;
	counter[1] = 0;
	while (*src)
	{
		if (ft_isdigit(*src))
		{
			res[counter[0] < 3 ? counter[0] : 0] = ft_atoi(src);
			counter[1]++;
			while (ft_isdigit(*src) && *src)
				src++;
		}
		if (*(src++) == ',')
			counter[0]++;
	}
	if (*src || counter[0] != 2 || counter[1] != 3 || res[0] > 255
		|| res[1] > 255 || res[2] > 255 || *dest != 0)
		exit(ft_put_error("Error\nIncorrect color value or number", 100));
	*dest = rgba(res[0], res[1], res[2], 0.99);
}

static	void	write_img(char *src, t_data **dest, t_vars *vars)
{
	int			width;
	int			height;

	if (*dest)
		exit(ft_put_error("Error\nDuplicate map parameters", 23));
	if (!(*dest = (t_data*)malloc(sizeof(t_data))))
		exit(ft_put_error("Error\nMemory allocation error", 123));
	while (is_space(*src))
		src++;
	(*dest)->img = mlx_xpm_file_to_image(vars->mlx, src, &width, &height);
	if (!(*dest)->img)
	{
		write(2, "Error\nIncorrect_image_path: '", 30);
		ft_putstr_fd(src, 2);
		write(2, "'", 1);
		exit(1);
	}
	(*dest)->width = width;
	(*dest)->height = height;
	(*dest)->addr = mlx_get_data_addr((*dest)->img, &((*dest)->bpp),
		&((*dest)->len), &((*dest)->endian));
}

static int		check_set(char *line, t_vars *vars)
{
	if (!*line)
		return (1);
	if (*line == 'R' && is_space(*(line + 1)))
		write_res(line + 1, vars);
	else if (*line == 'N' && *(line + 1) == 'O' && is_space(*(line + 2)))
		write_img(line + 2, &vars->north, vars);
	else if (*line == 'S' && *(line + 1) == 'O' && is_space(*(line + 2)))
		write_img(line + 2, &vars->south, vars);
	else if (*line == 'W' && *(line + 1) == 'E' && is_space(*(line + 2)))
		write_img(line + 2, &vars->west, vars);
	else if (*line == 'E' && *(line + 1) == 'A' && is_space(*(line + 2)))
		write_img(line + 2, &vars->east, vars);
	else if (*line == 'S' && is_space(*(line + 1)))
		write_img(line + 2, &vars->sprite, vars);
	else if (*line == 'F' && is_space(*(line + 1)))
		write_color(line + 1, &vars->floor);
	else if (*line == 'C' && is_space(*(line + 1)))
		write_color(line + 1, &vars->roof);
	else
		return (0);
	return (1);
}

int				prse_file(char *ptf, t_vars *vars)
{
	int			fd;
	int			ret;
	char		*line;

	if ((fd = open(ptf, O_RDONLY)) == -1)
		exit(ft_put_error("Error\nIncorrect file path", 1));
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (check_set(line, vars) == 0)
			break ;
		free(line);
	}
	if (!vars->north || !vars->south || !vars->west || !vars->east ||
		!vars->sprite || !vars->floor || !vars->roof || !vars->x || !vars->y)
		exit(ft_put_error("Error\nIncorrect parameters\n", 10));
	if (ret == -1)
		exit(ft_put_error("Error\nMemory allocation error", 123));
	if (ret == 0)
		exit(ft_put_error("Error\nIncorrect map value", 51));
	map_parse(fd, line, vars);
	return (0);
}
