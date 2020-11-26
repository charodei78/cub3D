/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheimerd <hheimerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:29:15 by hheimerd          #+#    #+#             */
/*   Updated: 2020/09/20 17:37:01 by hheimerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void		clear_vars(t_vars *vars)
{
	vars->x = 0;
	vars->y = 0;
	vars->north = 0;
	vars->south = 0;
	vars->west = 0;
	vars->east = 0;
	vars->sprite = 0;
	vars->floor = 0;
	vars->roof = 0;
}

static int		close_window(int keycode, t_vars *vars)
{
	if (vars && keycode)
		;
	exit(0);
}

static void		hook_set(t_vars *vars)
{
	mlx_hook(vars->win, 6, 0, rotate_view, vars);
	mlx_hook(vars->win, 2, 0, k_hook_parse, vars);
	mlx_hook(vars->win, 17, 0, close_window, vars);
}

static int		check_params(int argc, const char **argv)
{
	if (argc < 2 || argc > 3)
		exit(ft_put_error(
			"Error\nIncorrect params value. Expected 2 or 3 params\n", 300));
	if (argc > 1)
		if (!ft_match((char*)argv[1], "*.cub"))
			exit(ft_put_error("Error\nIncorrect file format\n", 1));
	if (argc == 3)
	{
		if (ft_strcmp((char*)argv[2], (char*)"--save") == 0)
			return (1);
		else
			exit(ft_put_error("Error\nIncorrect params value\n", 300));
	}
	return (0);
}

int				main(int argc, const char **argv)
{
	t_vars		vars;
	t_data		img;
	t_player	player;

	clear_vars(&vars);
	img.snap = check_params(argc, argv);
	check_params(argc, argv);
	vars.player = &player;
	vars.mlx = mlx_init();
	prse_file((char*)argv[1], &vars);
	if (!vars.sprite || vars.sprite->width > 2000 || vars.sprite->height > 2000)
		exit(ft_put_error("Error\nMax sprite resolution: 2000x2000!\n", 1000));
	vars.win = mlx_new_window(vars.mlx, vars.x, vars.y, "test");
	img_init(vars.mlx, &img, vars.x, vars.y);
	vars.img = &img;
	if (!ft_strchr("NEWS", player.direction))
		exit(ft_put_error("Error\nIncorrect map player direction", 1));
	if (player.direction == 'W' || player.direction == 'E')
		player.direction = player.direction == 'W' ? 2 : 0;
	else
		player.direction = player.direction == 'N' ? 3 : 1;
	rotate_view(vars.x / 4 * player.direction, 0, &vars);
	hook_set(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
