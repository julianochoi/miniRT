/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 00:32:32 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/06 00:32:15 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_amb(t_amb *amb)
{
	amb->is_declared = false;
	amb->ratio = 0.0;
	amb->color = gen_color(0.0, 0.0, 0.0);
}

void	init_res(t_res *res)
{
	res->is_declared = false;
	res->size_x = 0.0;
	res->size_y = 0.0;
}

void	init_minirt(t_main *env)
{
	env->mlx_ptr = mlx_init();
	env->win_ptr = NULL;
	env->title = "miniRT";
	env->imgs = NULL;
	init_res(&(env->res));
	init_amb(&(env->amb));
	env->cam_count = 0;
	env->cams = NULL;
	env->lights = NULL;
	env->objs = NULL;
}

void	quit_minirt(t_main *env)
{
	if (env->win_ptr)
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	del_imgs(env->mlx_ptr, &(env->imgs));
	del_cams(&(env->cams));
	del_lights(&(env->lights));
	del_objs(&(env->objs));
	free_and_null(env->mlx_ptr);
}
