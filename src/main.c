/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:34:07 by jobject           #+#    #+#             */
/*   Updated: 2022/01/05 20:19:25 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	check_input(int argc, char	**argv)
{
	int	len;
	
	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments", 2);
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] != 't' || argv[1][len - 2] != 'r'
		|| argv[1][len - 3] != '.')
	{
		ft_putendl_fd("File should have format \'.rt\'", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char	**argv)
{
	t_minirt	*minirt;
	
	check_input(argc, argv);
	minirt = minirt_init();
	parse_file(argv[1], &minirt);
	if (!total_check)
		exit_fatal(minirt, "Error");
	puts("Success");
	// puts("----------------Ambient lightning:--------------");
	// printf("Ratio: %f\nRGB: %d %d %d\n", minirt->ambient->ratio, minirt->ambient->rgb.r, minirt->ambient->rgb.g, minirt->ambient->rgb.b);
	// puts("---------------------Camera---------------------");
	// printf("Coordinates: %f %f %f\n", minirt->camera->coo.x, minirt->camera->coo.y, minirt->camera->coo.z);
	// printf("3d norm vector: %f %f %f\n", minirt->camera->vector.x, minirt->camera->vector.y, minirt->camera->vector.z);
	// printf("Angle of view hor. : %d\n", minirt->camera->fov);
	// puts("----------------------Light---------------------");
	// printf("Coordinates: %f %f %f\n", minirt->light->coo.x, minirt->light->coo.y, minirt->light->coo.z);
	// printf("Brightness ratio: %f\n", minirt->light->bright);
	// puts("----------------------Plane---------------------");
	// printf("Coordinates: %f %f %f\n", minirt->plane->coo.x, minirt->plane->coo.y, minirt->plane->coo.z);
	// printf("3d norm vector: %f %f %f\n", minirt->plane->vector.x, minirt->plane->vector.y, minirt->plane->vector.z);
	// printf("RGB: %d %d %d\n", minirt->plane->rgb.r, minirt->plane->rgb.g, minirt->plane->rgb.b);
	// puts("----------------------Sphere--------------------");
	// printf("Coordinates: %f %f %f\n", minirt->sphere->coo.x, minirt->sphere->coo.y, minirt->sphere->coo.z);
	// printf("Diameter: %f\n", minirt->sphere->diameter);
	// printf("RGB: %d %d %d\n", minirt->sphere->rgb.r, minirt->sphere->rgb.g, minirt->sphere->rgb.b);
	// puts("----------------------Cylinder------------------");
	// printf("Coordinates: %f %f %f\n", minirt->cylinder->coo.x, minirt->cylinder->coo.y, minirt->cylinder->coo.z);
	// printf("3d norm vector: %f %f %f\n", minirt->cylinder->vector.x, minirt->cylinder->vector.y, minirt->cylinder->vector.z);
	// printf("Diameter: %f\n", minirt->cylinder->diameter);
	// printf("Height: %f\n", minirt->cylinder->height);
	// printf("RGB: %d %d %d\n", minirt->cylinder->rgb.r, minirt->cylinder->rgb.g, minirt->cylinder->rgb.b);
	return (0);
}
