/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:41:39 by jobject           #+#    #+#             */
/*   Updated: 2022/01/06 12:21:15 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	skip_spaces(char	*str, int i)
{
	while (*(str + i) && *(str + i) == ' ')
		i++;
	return (i);
}

static void	delete_sphere(t_sphere	**sphere)
{
	t_sphere	*tmp;

	while (*sphere)
	{
		tmp = (*sphere)->next;
		free(*sphere);
		*sphere = tmp;
	}
}

static void	delete_plane(t_plane	**plane)
{
	t_plane	*tmp;

	while (*plane)
	{
		tmp = (*plane)->next;
		free(*plane);
		*plane = tmp;
	}
}

static void	delete_cylinder(t_cylinder	**cylinder)
{
	t_cylinder	*tmp;

	while (*cylinder)
	{
		tmp = (*cylinder)->next;
		free(*cylinder);
		*cylinder = tmp;
	}
}

void	exit_fatal(t_minirt	*minirt, char	*message)
{
	if (minirt->ambient)
		free(minirt->ambient);
	if (minirt->camera)
		free(minirt->camera);
	if (minirt->light)
		free(minirt->light);
	if (minirt->cylinder)
		delete_cylinder(&minirt->cylinder);
	if (minirt->sphere)
		delete_sphere(&minirt->sphere);
	if (minirt->plane)
		delete_plane(&minirt->plane);
	if (minirt->window)
		free (minirt->window);
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}
