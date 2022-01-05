/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:19:33 by jobject           #+#    #+#             */
/*   Updated: 2022/01/05 18:46:52 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	make_ambient(t_minirt	**minirt, char	*str)
{
	int	i;
	
	(*minirt)->ambient = (t_ambient *) malloc(sizeof(t_ambient));
	if (!(*minirt)->ambient)
		exit_fatal(*minirt, "Allocation failed");
	i = skip_spaces(str, 0);
	if (!*(str + i))
		exit_fatal(*minirt, "Error");
	if (!check_float(str + i))
		exit_fatal(*minirt, "Error");
	(*minirt)->ambient->ratio = ft_atof(str + i);
	while (*(str + i) != ' ')
		i++;
	i = skip_spaces(str, i);
	if (!*(str + i))
		exit_fatal(*minirt, "Error");
	if (!init_rgb(str + i, &(*minirt)->ambient->rgb))
		exit_fatal(*minirt, "Error");
}

void	make_camera(t_minirt	**minirt, char	*str)
{
	int i;
	
	(*minirt)->camera = (t_camera *) malloc(sizeof(t_camera));
	if (!(*minirt)->camera)
		exit_fatal(*minirt, "Allocation failed");
	i = skip_spaces(str, 0);
	if (!*(str + i))
		exit_fatal(*minirt, "Error");
	if (!init_coo(str, &(*minirt)->camera->coo))
		exit_fatal(*minirt, "Error");
	while (*(str + i) != ' ')
		i++;
	i = skip_spaces(str, i);
	if (!*(str + i))
		exit_fatal(*minirt, "Error");
	if (!init_coo(str + i, &(*minirt)->camera->vector))
		exit_fatal(*minirt, "Error");
	while (*(str + i) != ' ')
		i++;
	i = skip_spaces(str, i);
	if (!*(str + i))
		exit_fatal(*minirt, "Error");
	(*minirt)->camera->fov = ft_atoi(str + i);
	while (*(str + i) && ft_isdigit(*(str + i)))
		i++;
}

void	make_light(t_minirt	**minirt, char	*str)
{
	int	i;

	i = 0;
	(*minirt)->light = (t_light *) malloc(sizeof(t_light));
	if (!(*minirt)->light)
		exit_fatal(*minirt, "Allocation failed");
	i = skip_spaces(str, 0);
	if (!*(str + i))
		exit_fatal(*minirt, "Error");
	if (!init_coo(str, &(*minirt)->light->coo))
		exit_fatal(*minirt, "Error");
	while (*(str + i) != ' ')
		i++;
	i = skip_spaces(str, i);
	if (!*(str + i))
		exit_fatal(*minirt, "Error");
	(*minirt)->light->bright = ft_atof(str + i);
	while (*(str + i) && ft_isdigit(*(str + i)))
		i++;
	if (*(str + i) && *(str + i) != '.')
		exit_fatal(*minirt, "Error");
	i++;
	while (*(str + i) && ft_isdigit(*(str + i)))
		i++;	
}
