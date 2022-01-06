/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:55:57 by jobject           #+#    #+#             */
/*   Updated: 2022/01/06 19:43:36 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_vplane	*get_view_plane(float width, float height, int fov)
{
    t_vplane	*vplane;
    float		aspect_ratio;

    vplane = (t_vplane *) malloc(sizeof(t_vplane));
    if (!vplane)
        return(NULL);
    aspect_ratio = width / height;
    vplane->width = tanf(fov / 2 * (M_PI / 180)) * 2;
    vplane->height = vplane->width / aspect_ratio;
    vplane->x_pixel = vplane->width / width;
    vplane->y_pixel = vplane->height / height;
    return (vplane);
}

bool	init_coo(char	*str, t_coo	*coo)
{
	int	i;
	
	i = 0;
	if (!check_float(str))
		return (false);
	coo->x = ft_atof(str);
	while (*(str + i) != ',')
		i++;
	if (!check_float(str + ++i))
		return (false);
	coo->y = ft_atof(str + i);
	while (*(str + i) != ',')
		i++;
	if (!check_float(str + ++i))
		return (false);
	coo->z = ft_atof(str + i);
	return (true);
}

bool	init_rgb(char	*str, t_rgb	*rgb)
{
	int	i;
	int	j;

	i = 0;
	while (*(str + i) && ft_isdigit(*(str + i)))
		i++;
	if (!*(str + i) || *(str + i) != ',')
		return (false);
	rgb->r = ft_atoi(str);
	j = ++i;
	while (*(str + i) && ft_isdigit(*(str + i)))
		i++;
	if (!*(str + i) || *(str + i) != ',')
		return (false);
	rgb->g = ft_atoi(str + j);
	j = ++i;
	while (*(str + i) && ft_isdigit(*(str + i)))
		i++;
	if (*(str + i))
		return (false);
	rgb->b = ft_atoi(str + j);
	return (true);
}

t_minirt	*minirt_init(void)
{
	t_minirt	*ptr;

	ptr = (t_minirt *) malloc(sizeof(t_minirt));
	if (!ptr)
		return (NULL);
	ptr->ambient = NULL;
	ptr->camera = NULL;
	ptr->light = NULL;
	ptr->sphere = NULL;
	ptr->cylinder = NULL;
	ptr->plane = NULL;
	ptr->window = NULL;
	return (ptr);
}
