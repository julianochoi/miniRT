/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 01:33:46 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/05 18:07:42 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	check_edge(t_v3 to, t_v3 from, t_v3 hit_p, t_v3 normal)
{
	t_v3		edge;
	t_v3		vec_p;

	edge = v3_sub(to, from);
	vec_p = v3_sub(hit_p, from);
	return (v3_dot(normal, v3_cross(edge, vec_p)) >= EPSILON);
}

static bool	is_in_triangle(t_tr *tr, t_v3 hit_p, t_v3 normal)
{
	return (((check_edge(tr->p2, tr->p1, hit_p, normal))
		&& (check_edge(tr->p3, tr->p2, hit_p, normal))
		&& (check_edge(tr->p1, tr->p3, hit_p, normal)))
		|| ((check_edge(tr->p1, tr->p2, hit_p, normal))
		&& (check_edge(tr->p3, tr->p1, hit_p, normal))
		&& (check_edge(tr->p2, tr->p3, hit_p, normal))));
}

bool		hit_triangle(t_tr *tr, t_ray *ray, double *t)
{
	t_v3		hit_p;

	hit_p = gen_v3(0.0, 0.0, 0.0);
	if (hit_plane(tr->p1, tr->n, ray, t))
	{
		if (v3_dot(ray->d, tr->n) > 0)
			tr->n = v3_scalar(-1.0, tr->n);
		hit_p = ray_position(*ray, *t);
		return (is_in_triangle(tr, hit_p, tr->n));
	}
	return (false);
}
