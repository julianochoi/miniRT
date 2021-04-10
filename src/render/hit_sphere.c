/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:47:56 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/06 18:54:02 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	hit_sphere(t_sph *sp, t_ray *r, double *t)
{
	double	delta;
	double	coef[3];
	double	t1;
	double	t2;

	coef[0] = v3_dot(r->d, r->d);
	coef[1] = 2 * v3_dot(r->d, v3_sub(r->o, sp->c));
	coef[2] = v3_dot(v3_sub(r->o, sp->c), v3_sub(r->o, sp->c)) - pow(sp->r, 2);
	delta = pow(coef[1], 2) - 4 * coef[0] * coef[2];
	if (delta > 0)
	{
		t1 = (-coef[1] + sqrt(delta)) / (2 * coef[0]);
		t2 = (-coef[1] - sqrt(delta)) / (2 * coef[0]);
		if (t1 < 0 && t2 < 0)
			return (false);
		else if (min_double(t1, t2) < 0)
			*t = max_double(t1, t2);
		else
			*t = min_double(t1, t2);
		return (true);
	}
	return (false);
}
