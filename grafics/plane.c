/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:21:40 by jobject           #+#    #+#             */
/*   Updated: 2022/01/12 15:29:40 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	plane_intersection(t_minirt	*minirt, t_plane	*pl, t_coo	vec, int *color)
{
	float	denom;
	float	t;
	t_coo	cam_pl;
	t_coo	tmp;

	vec_sub(minirt->camera->coo, pl->coo, &cam_pl);
	denom = vec_dot_product(cam_pl, vec);
	if (fabsf(denom) > 1e-6)
	{
		vec_sub(pl->coo, minirt->ray, &tmp);
		t = vec_dot_product(tmp, cam_pl);
		if (t >= 0)
			make_color(pl->rgb, color);
		return (t >= 0);
	}
	return (false);
}
