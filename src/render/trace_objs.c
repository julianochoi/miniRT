/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:48:16 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/05 16:33:31 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	hit_obj_plane(t_pl *pl, t_ray *ray, double *t)
{
	return (hit_plane(pl->c, pl->n, ray, t));
}

bool		hit(t_obj *objs, t_ray *ray, double *t)
{
	bool	has_hit;

	has_hit = false;
	if (objs->id == SPHERE)
		has_hit = hit_sphere(objs->data, ray, t);
	else if (objs->id == PLANE)
		has_hit = hit_obj_plane(objs->data, ray, t);
	else if (objs->id == SQUARE)
		has_hit = hit_square(objs->data, ray, t);
	else if (objs->id == CYLINDER)
		has_hit = hit_cylinder(objs->data, ray, t);
	else if (objs->id == TRIANGLE)
		has_hit = hit_triangle(objs->data, ray, t);
	return (has_hit);
}

t_obj		*trace_objs(t_obj *objs, t_ray *ray)
{
	t_obj	*current;
	t_obj	*nearest_obj;
	double	t;

	t = INFINITY;
	nearest_obj = NULL;
	current = objs;
	while (current)
	{
		if (hit(current, ray, &t))
		{
			if (t < ray->t_nearest)
			{
				ray->t_nearest = t;
				nearest_obj = current;
			}
		}
		current = current->next;
	}
	return (nearest_obj);
}
