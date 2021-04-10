/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:18:37 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/04 22:48:41 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool		is_in_shadow(t_obj *objs, t_ray *ray, t_v3 light_dir)
{
	t_obj		*current;
	t_ray		shadow_ray;
	double		t;

	t = v3_mag(light_dir);
	shadow_ray = gen_ray(ray->hit_p, v3_norm(light_dir), t);
	current = objs;
	while (current)
	{
		if (hit(current, &shadow_ray, &t))
		{
			if (t < shadow_ray.t_nearest)
				return (true);
		}
		current = current->next;
	}
	return (false);
}

static double	get_specular(t_ray *ray, t_light *light)
{
	t_v3	light_dir;
	t_v3	rev_dir;
	t_v3	reflection;
	double	coef;
	double	angle;

	light_dir = v3_norm(v3_sub(light->o, ray->hit_p));
	angle = v3_dot(ray->n, v3_norm(light_dir));
	coef = 0;
	rev_dir = v3_norm(v3_scalar(-1.0, ray->d));
	reflection = v3_sub(v3_scalar(2 * angle, ray->n), light_dir);
	v3_norm(v3_add(light_dir, rev_dir));
	if (v3_dot(reflection, rev_dir) > 0.0)
		coef = light->ratio * pow(v3_dot(reflection, rev_dir), SPECULAR_COEF);
	return (coef);
}

static void		lighting(t_obj *objs, t_light *light, t_ray *ray, t_rgb *sum)
{
	t_v3		light_dir;
	double		angle;
	double		coef;
	double		spec_coef;

	light_dir = v3_sub(light->o, ray->hit_p);
	angle = v3_dot(ray->n, v3_norm(light_dir));
	if (!is_in_shadow(objs, ray, light_dir) && angle > 0.0)
	{
		coef = light->ratio * v3_dot(v3_norm(ray->n), v3_norm(light_dir));
		*sum = color_add(*sum, color_scalar(coef, light->color));
		spec_coef = get_specular(ray, light);
		*sum = color_add(*sum, color_scalar(spec_coef, light->color));
	}
}

void			trace_lights(t_main *env, t_ray *ray)
{
	t_light		*current;
	t_rgb		sum;

	sum = gen_color(0.0, 0.0, 0.0);
	sum = color_add(sum, color_scalar(env->amb.ratio, env->amb.color));
	current = env->lights;
	while (current)
	{
		lighting(env->objs, current, ray, &sum);
		current = current->next;
	}
	ray->color = color_mult(ray->color, sum);
}
