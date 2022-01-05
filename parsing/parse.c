/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:42:05 by jobject           #+#    #+#             */
/*   Updated: 2022/01/05 18:22:48 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static void	indentifier(t_minirt	**minirt, char	*str)
{
	if (!ft_strncmp(str, "A ", 2) && !(*minirt)->ambient)
		make_ambient(minirt, str + 1);
	else if (!ft_strncmp(str, "C ", 2) && !(*minirt)->camera)
		make_camera(minirt, str + 1);
	else if (!ft_strncmp(str, "L ", 2) && !(*minirt)->light)
		make_light(minirt, str + 1);
	else if (!ft_strncmp(str, "pl ", 3))
		make_plane(minirt, str + 2);
	else if (!ft_strncmp(str, "sp ", 3))
		make_sphere(minirt, str + 2);
	else if (!ft_strncmp(str, "cy ", 3))
		make_cylinder(minirt, str + 2);
	else
		exit_fatal(*minirt, "Error");
}

static void	parse_line(char	*line, t_minirt	**minirt)
{
	int		i;
	char	*trimmed_copy;

	trimmed_copy = ft_strtrim(line, "\n");
	puts(trimmed_copy);
	free(line);
	i = skip_spaces(trimmed_copy, 0);
	if (!*(trimmed_copy + i))
		return ;
	indentifier(minirt, trimmed_copy + i);
	free(trimmed_copy);
}

void	parse_file(char	*filename, t_minirt	**minirt)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY, 0664);
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (*line == '\n')
		{
			free(line);
			continue ;
		}
		parse_line(line, minirt);
	}
	close(fd);
}
