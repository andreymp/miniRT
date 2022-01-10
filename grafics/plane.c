/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:21:40 by jobject           #+#    #+#             */
/*   Updated: 2022/01/10 16:49:33 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	plane_intersection(t_minirt	*minirt, t_coo	vec, int *color)
{
	float	denom;
	float	t;
	t_coo	cam_pl;

	vec_sub(minirt->camera->coo, minirt->plane->coo, &cam_pl);
	denom = vec_dot_product(cam_pl, vec);
	if (fabsf(denom) > 1e-6)
	{
		vec_sub(minirt->plane->coo, minirt->ray, &vec);
		t = vec_dot_product(vec, cam_pl);
		if (t > 0)
			make_color(minirt->plane->rgb, color);
		return (t > 0);
	}
	return (false);
}
