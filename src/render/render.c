/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 02:52:19 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/07 16:44:06 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	render_images(t_main *env)
{
	t_cam		*cursor;
	t_img		*img;
	uint32_t	i;

	i = 0;
	cursor = env->cams;
	while (i < env->cam_count)
	{
		img = malloc_img(env);
		trace_ray(env, cursor, img);
		add_img(&(env->imgs), img);
		cursor = cursor->next;
		i++;
	}
	loop_img_list(env->imgs);
}

void		render(t_main *env, bool save)
{
	if (save)
	{
		render_images(env);
		save_bmp(env);
	}
	else
	{
		ft_printf(
			"Generating %d image(s)\n\
			\rFor multiple cameras, press spacebar to switch view\n\
			\rPress ESC to exit\n",
			env->cam_count);
		render_images(env);
	}
}
