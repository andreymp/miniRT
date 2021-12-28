/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:40:19 by jobject           #+#    #+#             */
/*   Updated: 2021/12/28 16:57:51 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
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
	t_coo	coo;
	float	diameter;
	t_rgb	rgb;
}				t_sphere;

typedef struct s_plane
{
	t_coo	coo;
	t_coo	vector;
	t_rgb	rgb;
}				t_plane;

typedef struct	s_cylinder
{
	t_coo	coo;
	t_coo	vector;
	float	diameter;
	float	height;
	t_rgb	rgb;
}				t_cylinder;

typedef struct s_minirt
{
	void		*mlx;
	void		*win;
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}				t_minirt;


#endif