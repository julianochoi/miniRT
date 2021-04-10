/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:57:47 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/06 23:04:09 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	*malloc_light(t_main *env)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		exit_error(env, (char *)strerror(errno));
	light->o = gen_v3(0.0, 0.0, 0.0);
	light->ratio = 0.0;
	light->color = gen_color(0.0, 0.0, 0.0);
	light->next = NULL;
	return (light);
}

void	add_light(t_light **lights, t_light *new_light)
{
	t_light	*current;

	if (!lights || !new_light)
		return ;
	if (*lights)
	{
		current = *lights;
		while (current->next)
			current = current->next;
		current->next = new_light;
	}
	else
		*lights = new_light;
}

void	del_lights(t_light **lights)
{
	t_light	*current;
	t_light	*next_node;

	if (!lights)
		return ;
	if (*lights)
	{
		current = *lights;
		while (current)
		{
			next_node = current->next;
			free(current);
			current = next_node;
		}
		*lights = NULL;
	}
}
