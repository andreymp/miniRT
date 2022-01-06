/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:07:09 by jobject           #+#    #+#             */
/*   Updated: 2022/01/06 16:17:26 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	make_plane(t_minirt	**minirt, char	*str)
{
	t_plane	*new;
	int		i;
	
	new = (t_plane *) malloc(sizeof(t_plane));
	if (!new)
		plane_exit(new, *minirt, "Allocation failed");
	new->next = NULL;
	i = skip_spaces(str, 0);
	if (!*(str + i))
		plane_exit(new, *minirt, "Error");
	if (!init_coo(str + i, &new->coo))
		plane_exit(new, *minirt, "Error");
	while (*(str + i) != ' ')
		i++;
	i = skip_spaces(str, i);
	if (!*(str + i))
		plane_exit(new, *minirt, "Error");
	if (!init_coo(str + i, &new->vector))
		plane_exit(new, *minirt, "Error");
	while (*(str + i) != ' ')
		i++;
	i = skip_spaces(str, i);
	if (!*(str + i))
		plane_exit(new, *minirt, "Error");
	if (!init_rgb(str + i, &new->rgb))
		plane_exit(new, *minirt, "Error");
	push_plane(&(*minirt)->plane, new);
}

void	make_sphere(t_minirt	**minirt, char	*str)
{
	t_sphere	*new;
	int			i;

	new = (t_sphere *) malloc(sizeof(t_sphere));
	if (!new)
		sphere_exit(new, *minirt, "Allocation failed");
	new->next = NULL;
	i = skip_spaces(str, 0);
	if (!*(str + i))
		sphere_exit(new, *minirt, "Error");
	if (!init_coo(str + i, &new->coo))
		sphere_exit(new, *minirt, "Error");
	while (*(str + i) != ' ')
		i++;
	i = skip_spaces(str, i);
	if (!*(str + i))
		sphere_exit(new, *minirt, "Error");
	if (!check_float(str + i))
		sphere_exit(new, *minirt, "Error");
	new->diameter = ft_atof(str + i);
	while (*(str + i) != ' ')
		i++;
	i = skip_spaces(str, i);
	if (!*(str + i))
		sphere_exit(new, *minirt, "Error");
	if (!init_rgb(str + i, &new->rgb))
		sphere_exit(new, *minirt, "Error");
	push_sphere(&(*minirt)->sphere, new);
}

static int	make_float(t_minirt	**minirt, char	*str, int i, t_cylinder	**new)
{
	i = skip_spaces(str, i);
	if (!*(str + i))
		cylinder_exit(*new, *minirt, "Error");
	if (!check_float(str + i))
		cylinder_exit(*new, *minirt, "Error");
	(*new)->diameter = ft_atof(str + i);
	while (*(str + i) != ' ')
		i++;
	i = skip_spaces(str, i);
	if (!*(str + i))
		cylinder_exit(*new, *minirt, "Error");
	if (!check_float(str + i))
		cylinder_exit(*new, *minirt, "Error");
	(*new)->height = ft_atof(str + i);
	while (*(str + i) != ' ')
		i++;
	return (i);
}

void	make_cylinder(t_minirt	**minirt, char	*str)
{
	t_cylinder	*new;
	int			i;
	
	new = (t_cylinder *) malloc(sizeof(t_cylinder));
	if (!new)
		cylinder_exit(new, *minirt, "Allocation failed");
	new->next = NULL;
	i = skip_spaces(str, 0);
	if (!*(str + i))
		cylinder_exit(new, *minirt, "Error");
	if (!init_coo(str + i, &new->coo))
		cylinder_exit(new, *minirt, "Error");
	while (*(str + i) != ' ')
		i++;
	i = skip_spaces(str, i);
	if (!*(str + i))
		cylinder_exit(new, *minirt, "Error");
	if (!init_coo(str + i, &new->vector))
		cylinder_exit(new, *minirt, "Error");
	while (*(str + i) != ' ')
		i++;
	i = make_float(minirt, str, i, &new);
	i = skip_spaces(str, i);
	if (!*(str + i))
		cylinder_exit(new, *minirt, "Error");
	if (!init_rgb(str + i, &new->rgb))
		cylinder_exit(new, *minirt, "Error");
	push_cylinder(&(*minirt)->cylinder, new);
}
