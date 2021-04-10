/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 02:47:00 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/06 23:06:00 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_resolution(t_main *env, char **line)
{
	if (env->res.is_declared)
		exit_error(env, "Resolution must be declared only once.");
	env->res.is_declared = true;
	*line += 1;
	skip_blank(env, line);
	env->res.size_x = parse_integer(env, line);
	skip_blank(env, line);
	env->res.size_y = parse_integer(env, line);
	if ((env->res.size_x < 1) || (env->res.size_y < 1))
		exit_error(env, "Improper Resolution value.");
}

void	parse_ambient(t_main *env, char **line)
{
	if (env->amb.is_declared)
		exit_error(env, "Ambient light must be declared once.");
	env->amb.is_declared = true;
	*line += 1;
	skip_blank(env, line);
	env->amb.ratio = parse_double(env, line);
	if (env->amb.ratio < 0.0 || env->amb.ratio > 1.0)
		exit_error(env, "Ambient light badly formatted.");
	skip_blank(env, line);
	env->amb.color = parse_color(env, line);
}

void	parse_camera(t_main *env, char **line)
{
	t_cam	*new_cam;

	*line += 1;
	skip_blank(env, line);
	new_cam = malloc_cam(env);
	add_cam(&(env->cams), new_cam);
	new_cam->o = parse_v3(env, line);
	skip_blank(env, line);
	new_cam->d = parse_v3(env, line);
	if (is_null_v3(new_cam->d))
		exit_error(env, "Camera cannot have null direction.");
	new_cam->d = v3_norm(new_cam->d);
	skip_blank(env, line);
	new_cam->fov = parse_integer(env, line);
	if ((new_cam->fov < 0.0) || (new_cam->fov > 180.0))
		exit_error(env, "Camera's field of view is off range.");
	env->cam_count += 1;
}

void	parse_light(t_main *env, char **line)
{
	t_light	*new_light;

	*line += 1;
	skip_blank(env, line);
	new_light = malloc_light(env);
	add_light(&(env->lights), new_light);
	new_light->o = parse_v3(env, line);
	skip_blank(env, line);
	new_light->ratio = parse_double(env, line);
	if (new_light->ratio < 0.0 || new_light->ratio > 1.0)
		exit_error(env, "Light ratio is off range [0.0, 1.0].");
	skip_blank(env, line);
	new_light->color = parse_color(env, line);
}
