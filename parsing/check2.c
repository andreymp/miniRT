/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:05:25 by jobject           #+#    #+#             */
/*   Updated: 2022/01/13 17:09:18 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static bool	check_sphere(t_sphere	*sphere)
{
	return (check_rgb(sphere->rgb));
}

static bool	check_plane(t_plane	*plane)
{
	return (check_rgb(plane->rgb) && check_vector(plane->vector));
}

static bool	check_cylinder(t_cylinder	*cylinder)
{
	return (check_rgb(cylinder->rgb) && check_vector(cylinder->vector));
}

static bool	make_flag_figure(t_plane	*pl, t_sphere	*sp, t_cylinder	*cy)
{
	bool	flag_figure;

	flag_figure = true;
	while (pl)
	{
		flag_figure &= check_plane(pl);
		pl = pl->next;
	}
	while (sp)
	{
		flag_figure &= check_sphere(sp);
		sp = sp->next;
	}
	while (cy)
	{
		flag_figure &= check_cylinder(cy);
		cy = cy->next;
	}
	return (flag_figure);
}

bool	total_check(t_minirt	*minirt)
{
	bool		flag_option;
	bool		flag_figure;
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;

	sp = minirt->sphere;
	pl = minirt->plane;
	cy = minirt->cylinder;
	flag_option = check_ambient(minirt->ambient);
	flag_option &= check_camera(minirt->camera);
	flag_option &= check_light(minirt->light);
	flag_figure = make_flag_figure(pl, sp, cy);
	return (flag_figure && flag_option);
}
