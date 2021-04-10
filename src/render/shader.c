/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:45:21 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/07 01:40:01 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_v3	get_cylinder_normal(t_cy *cylinder, t_ray *ray, t_v3 hit_p)
{
	t_v3	bp;
	t_v3	normal;
	double	dot_prod;

	bp = v3_sub(hit_p, cylinder->b1);
	dot_prod = v3_dot(cylinder->d, bp);
	normal = v3_sub(bp, v3_scalar(dot_prod, cylinder->d));
	if (v3_dot(ray->d, normal) > 0.0)
		normal = v3_scalar(-1.0, normal);
	return (v3_norm(normal));
}

static void	get_obj_normal(t_obj *hit_obj, t_ray *ray, t_v3 hit_p)
{
	if (hit_obj->id == SPHERE)
		ray->n = v3_norm(v3_sub(hit_p, ((t_sph *)hit_obj->data)->c));
	else if (hit_obj->id == PLANE)
		ray->n = ((t_pl *)hit_obj->data)->n;
	else if (hit_obj->id == SQUARE)
		ray->n = ((t_sq *)hit_obj->data)->n;
	else if (hit_obj->id == CYLINDER)
		ray->n = get_cylinder_normal(hit_obj->data, ray, hit_p);
	else if (hit_obj->id == TRIANGLE)
		ray->n = ((t_tr *)hit_obj->data)->n;
	if (v3_dot(ray->d, ray->n) > 0.0)
		ray->n = v3_scalar(-1., ray->n);
}

static void	get_obj_color(t_obj *hit_obj, t_ray *ray)
{
	if (hit_obj->id == SPHERE)
		ray->color = ((t_sph *)hit_obj->data)->color;
	else if (hit_obj->id == PLANE)
		ray->color = ((t_pl *)hit_obj->data)->color;
	else if (hit_obj->id == SQUARE)
		ray->color = ((t_sq *)hit_obj->data)->color;
	else if (hit_obj->id == CYLINDER)
		ray->color = ((t_cy *)hit_obj->data)->color;
	else if (hit_obj->id == TRIANGLE)
		ray->color = ((t_tr *)hit_obj->data)->color;
}

void		shader(t_main *env, t_ray *ray)
{
	t_obj	*hit_obj;

	hit_obj = trace_objs(env->objs, ray);
	if (hit_obj)
	{
		get_obj_color(hit_obj, ray);
		ray->hit_p = ray_position(*ray, ray->t_nearest);
		get_obj_normal(hit_obj, ray, ray->hit_p);
		ray->hit_p = v3_add(ray->hit_p, v3_scalar(EPSILON, ray->n));
		trace_lights(env, ray);
	}
}
