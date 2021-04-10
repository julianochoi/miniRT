/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:35:34 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/06 23:03:48 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_img	create_img(t_main *env)
{
	t_img	img;

	img.size_x = env->res.size_x;
	img.size_y = env->res.size_y;
	img.img_ptr = mlx_new_image(env->mlx_ptr, img.size_x, img.size_y);
	img.pixels = mlx_get_data_addr(
					img.img_ptr,
					&(img.bpp),
					&(img.size_line),
					&(img.endian));
	img.next = NULL;
	return (img);
}

t_img	*malloc_img(t_main *env)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		exit_error(env, (char *)strerror(errno));
	*img = create_img(env);
	return (img);
}

void	free_img(void *mlx_ptr, t_img *to_free)
{
	mlx_destroy_image(mlx_ptr, (*to_free).img_ptr);
	free(to_free);
}
