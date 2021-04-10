/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 23:37:30 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/06 22:56:00 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(t_main *env, char **line)
{
	t_sph	*sph;

	sph = malloc(sizeof(t_sph));
	if (!sph)
		exit_error(env, (char *)strerror(errno));
	*line += 2;
	skip_blank(env, line);
	sph->c = parse_v3(env, line);
	skip_blank(env, line);
	sph->r = parse_double(env, line) / 2;
	if (sph->r < 0 || fp_is_equal(sph->r, 0.0))
		exit_error(env, "Sphere's diameter is invalid.");
	skip_blank(env, line);
	sph->color = parse_color(env, line);
	add_obj_to_render(env, sph, SPHERE);
}

void	parse_plane(t_main *env, char **line)
{
	t_pl		*pl;

	pl = malloc(sizeof(t_pl));
	if (!pl)
		exit_error(env, (char *)strerror(errno));
	*line += 2;
	skip_blank(env, line);
	pl->c = parse_v3(env, line);
	skip_blank(env, line);
	pl->n = parse_v3(env, line);
	if (!is_in_range_v3(pl->n, -1.0, 1.0))
		exit_error(env, "Plane vector out of range [-1,1].");
	if (is_null_v3(pl->n))
		exit_error(env, "Plane vector cannot be null");
	pl->n = v3_norm(pl->n);
	skip_blank(env, line);
	pl->color = parse_color(env, line);
	add_obj_to_render(env, pl, PLANE);
}

void	parse_square(t_main *env, char **line)
{
	t_sq	*sq;

	sq = malloc(sizeof(t_sq));
	if (!sq)
		exit_error(env, (char *)strerror(errno));
	*line += 2;
	skip_blank(env, line);
	sq->c = parse_v3(env, line);
	skip_blank(env, line);
	sq->n = parse_v3(env, line);
	if (!is_in_range_v3(sq->n, -1.0, 1.0))
		exit_error(env, "Invalid scene: Square badly formatted.");
	if (is_null_v3(sq->n))
		exit_error(env, "Square's orientation vector cannot be null.");
	sq->n = v3_norm(sq->n);
	skip_blank(env, line);
	sq->side = parse_double(env, line);
	skip_blank(env, line);
	sq->color = parse_color(env, line);
	add_obj_to_render(env, sq, SQUARE);
}

void	parse_cylinder(t_main *env, char **line)
{
	t_cy		*cy;

	cy = malloc(sizeof(t_cy));
	if (!cy)
		exit_error(env, (char *)strerror(errno));
	*line += 2;
	skip_blank(env, line);
	cy->b1 = parse_v3(env, line);
	skip_blank(env, line);
	cy->d = parse_v3(env, line);
	if (!is_in_range_v3(cy->d, -1.0, 1.0))
		exit_error(env, "Cylinder's direction vector is off range [-1,1].");
	if (is_null_v3(cy->d))
		exit_error(env, "Cylinder's direction vector cannot be null.");
	cy->d = v3_norm(cy->d);
	skip_blank(env, line);
	cy->r = parse_double(env, line) / 2;
	skip_blank(env, line);
	cy->h = parse_double(env, line);
	skip_blank(env, line);
	cy->color = parse_color(env, line);
	cy->b2 = v3_add(cy->b1, v3_scalar(cy->h, cy->d));
	add_obj_to_render(env, cy, CYLINDER);
}

void	parse_triangle(t_main *env, char **line)
{
	t_tr		*tr;

	tr = malloc(sizeof(t_tr));
	if (!tr)
		exit_error(env, (char *)strerror(errno));
	*line += 2;
	skip_blank(env, line);
	tr->p1 = parse_v3(env, line);
	skip_blank(env, line);
	tr->p2 = parse_v3(env, line);
	skip_blank(env, line);
	tr->p3 = parse_v3(env, line);
	tr->n = v3_cross(v3_sub(tr->p3, tr->p1), v3_sub(tr->p2, tr->p1));
	if (is_null_v3(tr->n))
		exit_error(env, "Triangle points are collinear.");
	tr->n = v3_norm(tr->n);
	skip_blank(env, line);
	tr->color = parse_color(env, line);
	add_obj_to_render(env, tr, TRIANGLE);
}
