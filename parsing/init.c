/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:55:57 by jobject           #+#    #+#             */
/*   Updated: 2022/01/05 18:38:50 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

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
	return (ptr);
}
