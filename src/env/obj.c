/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:09:20 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/06 23:04:22 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	*create_obj(void *shape_data, t_objid shape_id)
{
	t_obj	*obj;

	obj = malloc(sizeof(t_obj));
	if (!obj)
		return (NULL);
	obj->id = shape_id;
	obj->data = shape_data;
	obj->next = NULL;
	return (obj);
}

void	add_obj(t_obj **objs, t_obj *new_obj)
{
	t_obj	*current;

	if (!objs || !new_obj)
		return ;
	current = *objs;
	if (*objs)
	{
		while (current->next)
			current = current->next;
		current->next = new_obj;
	}
	else
		*objs = new_obj;
}

void	del_objs(t_obj **objs)
{
	t_obj	*current;
	t_obj	*next_node;

	if (!objs)
		return ;
	current = *objs;
	if (*objs)
	{
		while (current)
		{
			next_node = current->next;
			free(current->data);
			free(current);
			current = next_node;
		}
		*objs = NULL;
	}
}

void	add_obj_to_render(t_main *env, void *to_add, t_objid objid)
{
	t_obj	*new_obj;

	new_obj = create_obj(to_add, objid);
	if (!new_obj)
		exit_error(env, (char *)strerror(errno));
	add_obj(&(env->objs), new_obj);
}
