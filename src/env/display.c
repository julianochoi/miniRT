/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:18:44 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/03 21:39:50 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	open_win(t_main *env)
{
	env->win_ptr = mlx_new_window(
					env->mlx_ptr,
					env->res.size_x,
					env->res.size_y,
					env->title);
}

static void	img_to_win(t_main *env)
{
	mlx_put_image_to_window(
		env->mlx_ptr,
		env->win_ptr,
		env->imgs->img_ptr,
		0,
		0);
}

int			reload_img(t_main *env)
{
	img_to_win(env);
	return (0);
}

void		switch_cam(t_main *env)
{
	env->imgs = env->imgs->next;
	img_to_win(env);
}

void		display(t_main *env)
{
	open_win(env);
	img_to_win(env);
	event_hooks(env);
}
