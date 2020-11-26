/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheimerd <hheimerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:31:21 by hheimerd          #+#    #+#             */
/*   Updated: 2020/09/23 17:06:25 by hheimerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "stdio.h"
# include "libft.h"

# define WALL_HEIGHT 	2.5

typedef struct	s_data
{
	int			width;
	int			height;
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
	int			snap;
}				t_data;

typedef struct	s_color
{
	t_data		*img;
	int			x;
	int			y;
	int			color;
}				t_color;

typedef struct	s_shape
{
	int			x;
	int			y;
	int			size_x;
	int			size_y;
	int			color;
	float		offset;
	t_data		*img;
}				t_shape;

typedef struct	s_map
{
	char		**map;
	int			len;
	int			height;
	int			color;
}				t_map;

typedef struct	s_player
{
	float		x;
	float		y;
	char		direction;
	float		pow_x;
	float		pow_y;
	float		pow_fov;
}				t_player;

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	t_data		*img;
	t_map		*map;
	t_data		*north;
	t_data		*south;
	t_data		*west;
	t_data		*east;
	t_data		*sprite;
	int			floor;
	int			roof;
	t_player	*player;
	int			mouse_x;
	int			mouse_y;
}				t_vars;

typedef struct	s_pip
{
	t_vars		*vars;
	t_data		*img;
	int			x;
	int			y;
}				t_pip;

int				get_next_line(int fd, char **line);
int				pixel_put_s(t_color *pix);
int				put_rect(t_vars *vars, t_shape *params);
int				rgba(int r, int g, int b, float t);
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);
int				get_opposite(int trgb);
int				add_shade(int trgb);
void			img_init(void *mlx_ptr, t_data *dest, int width, int height);
void			pixel_put(t_data *data, int x, int y, int color);
int				k_hook_parse(int keycode, t_vars *vars);
int				m_hook_parse(int coord, t_vars *vars);
int				resize_hook(int node, t_vars *vars);
int				mk_hook_parse(int coord, t_vars *vars);
int				mpitw(t_vars *vars);
void			check_line(char *line, char *allow);
void			move_img(t_vars *vars, int x, int y, int h, int w);
void			draw_map(t_vars *vars);
void			draw_sprite(t_vars *vars, t_shape *params);
void			put_rect_text(t_vars *vars, t_shape *params);
void			find_range(t_player *player, int i, t_vars *vars);
int				clear_world(t_vars *vars);
int				rotate_view(int x, int y, t_vars *vars);
int				ft_put_error(char *message, int code);
int				prse_file(char *ptf, t_vars *vars);
unsigned int	get_pixel(t_data *img, int x, int y);
void			do_snap(t_vars *vars);
void			map_parse(int fd, char *line, t_vars *vars);

#endif
