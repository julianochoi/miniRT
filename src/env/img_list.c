/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:25:31 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/06 23:03:40 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_img(t_img **imgs, t_img *new_img)
{
	t_img	*current;

	if (!imgs || !new_img)
		return ;
	if (*imgs)
	{
		current = *imgs;
		while (current->next)
			current = current->next;
		current->next = new_img;
	}
	else
		*imgs = new_img;
}

void	del_imgs(void *mlx_ptr, t_img **imgs)
{
	t_img	*current;
	t_img	*head;

	if (!imgs)
		return ;
	if (*imgs)
	{
		head = *imgs;
		while (*imgs)
		{
			current = *imgs;
			*imgs = (*imgs)->next;
			free_img(mlx_ptr, current);
			if (*imgs == head)
				*imgs = NULL;
		}
	}
}

void	loop_img_list(t_img *imgs)
{
	t_img	*head;

	head = imgs;
	while (imgs->next)
		imgs = imgs->next;
	imgs->next = head;
}
