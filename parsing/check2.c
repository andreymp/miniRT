/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:05:25 by jobject           #+#    #+#             */
/*   Updated: 2022/01/05 20:18:34 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/miniRT.h"

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

bool	total_check(t_minirt	*minirt)
{
	bool	flag_option;
	bool	flag_figure;

	flag_figure = true;
	flag_option = check_ambient(minirt->ambient) 
		&& check_camera(minirt->camera) && check_light(minirt->light);
	while (minirt->plane)
	{
		flag_figure = flag_figure && check_plane(minirt->plane);
		minirt->plane = minirt->plane->next;
	}
	while (minirt->sphere)
	{
		flag_figure = flag_figure && check_sphere(minirt->sphere);
		minirt->sphere = minirt->sphere->next;
	}
	while (minirt->cylinder)
	{
		flag_figure = flag_figure && check_cylinder(minirt->cylinder);
		minirt->cylinder = minirt->cylinder->next;
	}
	return (flag_figure && flag_option);
}
