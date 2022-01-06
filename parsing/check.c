/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:49:37 by jobject           #+#    #+#             */
/*   Updated: 2022/01/06 13:55:12 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	check_rgb(t_rgb	rgb)
{
	if (rgb.r < 0 || rgb.r > 255
		|| rgb.g < 0 || rgb.g > 255
		|| rgb.b < 0 || rgb.b > 255)
		return (false);
	return (true);
}

bool	check_vector(t_coo	vector)
{
	if (fabsf(vector.x) > 1.0
		|| fabsf(vector.y) > 1.0
		|| fabsf(vector.x) > 1.0)
		return (false);
	return (true);
}

bool	check_ambient(t_ambient	*ambient)
{
	if (!ambient)
		return (false);
	if (ambient->ratio < 0.0 || ambient->ratio > 1.0)
		return (false);
	return (check_rgb(ambient->rgb));
}

bool	check_camera(t_camera	*camera)
{
	if (!camera)
		return (false);
	if (camera->fov < 0 || camera->fov > 180)
		return (false);
	return (check_vector(camera->vector));
}

bool	check_light(t_light	*light)
{
	if (!light)
		return (false);
	if (light->bright < 0.0 || light->bright > 1.0)
		return (false);
	return (true);
}
