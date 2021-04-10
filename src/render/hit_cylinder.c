/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 01:35:48 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/06 20:05:28 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	cylinder_coefs(t_cy *cy, t_ray *r, double *coef, double *delta)
{
	t_v3	x;

	x = v3_sub(r->o, cy->b1);
	coef[0] = v3_mag(r->d) - pow(v3_dot(r->d, cy->d), 2);
	coef[1] = 2 * (v3_dot(r->d, x) - (v3_dot(r->d, cy->d) * v3_dot(x, cy->d)));
	coef[2] = v3_dot(x, x) - pow(v3_dot(x, cy->d), 2) - pow(cy->r, 2);
	*delta = pow(coef[1], 2) - 4 * coef[0] * coef[2];
}

static bool	is_in_cyl_range(t_cy *cy, t_ray *r, double t)
{
	t_v3	hit_p;
	t_v3	b1_p;
	t_v3	b2_p;

	if (t < 0 || t == INFINITY)
		return (false);
	hit_p = ray_position(*r, t);
	b1_p = v3_sub(hit_p, cy->b1);
	b2_p = v3_sub(hit_p, cy->b2);
	return ((v3_dot(cy->d, b1_p) > 0.0)
		&& (v3_dot(cy->d, b2_p) < 0.0));
}

bool		hit_cylinder(t_cy *cy, t_ray *r, double *t)
{
	double	delta;
	double	coef[3];
	double	t1;
	double	t2;

	cylinder_coefs(cy, r, coef, &delta);
	if (delta < 0)
		return (false);
	t1 = (-coef[1] + sqrt(delta)) / (2 * coef[0]);
	t2 = (-coef[1] - sqrt(delta)) / (2 * coef[0]);
	if (t1 < 0 && t2 < 0)
		return (false);
	else if (min_double(t1, t2) < 0)
		*t = max_double(t1, t2);
	else
	{
		*t = min_double(t1, t2);
		if (!is_in_cyl_range(cy, r, *t))
			*t = max_double(t1, t2);
	}
	return (is_in_cyl_range(cy, r, *t));
}
