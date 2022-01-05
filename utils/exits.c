/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:03:09 by jobject           #+#    #+#             */
/*   Updated: 2022/01/05 17:05:02 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	plane_exit(t_plane	*plane, t_minirt	*minirt, char	*message)
{
	free(plane);
	exit_fatal(minirt, message);
}

void	sphere_exit(t_sphere	*sphere, t_minirt	*minirt, char	*message)
{
	free(sphere);
	exit_fatal(minirt, message);
}

void	cylinder_exit(t_cylinder	*cylinder, t_minirt	*minirt, char	*message)
{
	free(cylinder);
	exit_fatal(minirt, message);
}
