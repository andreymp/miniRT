/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:19:15 by jobject           #+#    #+#             */
/*   Updated: 2022/01/10 15:31:10 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_scene	*init_scene(t_minirt	*minirt) 
{
	t_scene	*new;
	
	new = (t_scene *) malloc(sizeof(t_scene));
	if (!new)
		return (NULL);
	new->width = WIDTH;
	new->height = HEIGHT;
	new->cam = minirt->camera;
	new->light = minirt->light;
	new->plane = minirt->plane;
	new->sphere = minirt->sphere;
	new->cylinder = minirt->cylinder;
	new->color = 0;
	return (new);
}

