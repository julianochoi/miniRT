/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 22:54:41 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/07 19:28:27 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		check_max_display(t_main *env)
{
	int		max_x;
	int		max_y;

	mlx_get_screen_size(env->mlx_ptr, &max_x, &max_y);
	if (env->res.size_x > max_x)
		env->res.size_x = max_x;
	if (env->res.size_y > max_y)
		env->res.size_y = max_y;
}

static void	check_scene(t_main *env)
{
	if (!env->res.is_declared)
		exit_error(env, "No resolution declared.");
	if (!env->amb.is_declared)
		exit_error(env, "No ambient light declared.");
	if (!env->cams)
		exit_error(env, "No camera declared.");
	if (!env->objs)
		exit_error(env, "No object declared.");
}

static void	parse_line(t_main *env, char *line)
{
	if (line[0] == 'R' && ft_isblank(line[1]))
		parse_resolution(env, &line);
	else if (line[0] == 'A' && ft_isblank(line[1]))
		parse_ambient(env, &line);
	else if (line[0] == 'c' && ft_isblank(line[1]))
		parse_camera(env, &line);
	else if (line[0] == 'l' && ft_isblank(line[1]))
		parse_light(env, &line);
	else if (line[0] == 's' && line[1] == 'p')
		parse_sphere(env, &line);
	else if (line[0] == 'p' && line[1] == 'l')
		parse_plane(env, &line);
	else if (line[0] == 's' && line[1] == 'q')
		parse_square(env, &line);
	else if (line[0] == 'c' && line[1] == 'y')
		parse_cylinder(env, &line);
	else if (line[0] == 't' && line[1] == 'r')
		parse_triangle(env, &line);
	else
		exit_error(env, "Invalid scene: Unknown identifier.");
}

void		parse(t_main *env, const char *filepath)
{
	char	*line;
	int		fd;
	int		flag;

	flag = 1;
	fd = open(filepath, O_RDONLY | O_NOFOLLOW);
	if (!fd)
		exit_error(env, (char *)strerror(errno));
	while (flag)
	{
		flag = get_next_line(fd, &line);
		if (*line)
			parse_line(env, line);
		free_and_null(line);
	}
	close(fd);
	check_scene(env);
	check_max_display(env);
}
