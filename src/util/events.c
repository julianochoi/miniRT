/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:24:56 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/06 20:04:49 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "events.h"

int		handle_key(int keycode, void *param)
{
	t_main	*env;

	env = (t_main *)param;
	if (keycode == ESC_KEY)
		exit_success(env);
	if (keycode == SPC_KEY)
		switch_cam(env);
	return (0);
}

void	event_hooks(t_main *env)
{
	mlx_key_hook(env->win_ptr, handle_key, env);
	mlx_hook(env->win_ptr, MAPNOTIFY, STRNOTIFYMASK, reload_img, env);
	mlx_hook(env->win_ptr, DESTROYNOTIFY, STRNOTIFYMASK, exit_success, env);
	mlx_hook(env->win_ptr, CLIENTMSG, STRNOTIFYMASK, exit_success, env);
}
