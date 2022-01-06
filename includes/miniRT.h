/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:40:19 by jobject           #+#    #+#             */
/*   Updated: 2022/01/06 13:45:42 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define HEIGHT 800
# define WIDTH  1000

# define ESC 53

# include "../libft/libft.h"
# include "get_next_line.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	color;
}				t_rgb;

typedef struct s_coo
{
	float	x;
	float	y;
	float	z;
}				t_coo;

typedef struct t_ambient
{
	float	ratio;
	t_rgb	rgb;
}				t_ambient;

typedef struct s_camera
{
	t_coo	coo;
	t_coo	vector;
	int		fov;
}				t_camera;

typedef struct s_light
{
	t_coo	coo;
	float	bright;	
}				t_light;

typedef struct s_sphere
{
	t_coo			coo;
	float			diameter;
	t_rgb			rgb;
	struct s_sphere	*next;
}				t_sphere;

typedef struct s_plane
{
	t_coo			coo;
	t_coo			vector;
	t_rgb			rgb;
	struct s_plane	*next;
}				t_plane;

typedef struct	s_cylinder
{
	t_coo				coo;
	t_coo				vector;
	float				diameter;
	float				height;
	t_rgb				rgb;
	struct	s_cylinder	*next;
}				t_cylinder;

typedef struct	s_window
{
	void	*mlx;
	void	*win;
	void	*image;
	char	*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}				t_window;

typedef struct	s_vplane
{
	float	width;
	float	height;
	float	x_pixel;
	float	y_pixel;
}				t_vplane;

typedef struct s_minirt
{
	t_window	*window;
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
}				t_minirt;

t_minirt	*minirt_init(void);
void		parse_file(char	*filename, t_minirt	**minirt);
int			skip_spaces(char	*line, int i);
void		exit_fatal(t_minirt	*minirt, char	*message);
void		make_ambient(t_minirt	**minirt, char	*str);
void		make_camera(t_minirt	**minirt, char	*str);
void		make_light(t_minirt	**minirt, char	*str);
void		make_plane(t_minirt	**minirt, char	*str);
void		make_sphere(t_minirt	**minirt, char	*str);
void		make_cylinder(t_minirt	**minirt, char	*str);
bool		check_float(char	*str);
float		ft_atof(char	*str);
bool		init_rgb(char	*str, t_rgb	*rgb);
bool		init_coo(char	*str, t_coo	*coo);
void		push_plane(t_plane	**plane, t_plane	*new);
void		plane_exit(t_plane	*plane, t_minirt	*minirt, char	*message);
void		push_cylinder(t_cylinder	**cylinder, t_cylinder	*new);
void		cylinder_exit(t_cylinder	*cylinder, t_minirt	*minirt, char	*message);
void		push_sphere(t_sphere	**sphere, t_sphere	*new);
void		sphere_exit(t_sphere	*sphere, t_minirt	*minirt, char	*message);
bool		check_rgb(t_rgb	rgb);
bool		check_vector(t_coo	vector);
bool		check_ambient(t_ambient	*ambient);
bool		check_camera(t_camera	*camera);
bool		check_light(t_light	*light);
bool		total_check(t_minirt	*minirt);
t_window	*win_init(void);
void		mini_rt(t_minirt	*minirt);
void		do_init_image(t_window *win);
void		my_mlx_pixel_put(t_window *win, int x, int y, int color);
int			rgb_to_hex(t_rgb	rgb);
t_coo		*new_vector(float x, float y, float z);
t_coo		*vec_sub(t_coo	*vec1, t_coo	*vec2);
float		vec_length(t_coo	*vec);
void		vec_normalized(t_coo	*vec);
float		vec_dot_product(t_coo	*vec1, t_coo	*vec2);
t_vplane	*get_view_plane(float width, float height, float fov);

#endif