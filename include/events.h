/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:54:30 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/06 22:57:10 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# define ESC_KEY 65307
# define SPC_KEY 32

# define KEYPRESS 2
# define DESTROYNOTIFY 17
# define MAPNOTIFY 19
# define CLIENTMSG 33

# define KEYPRESSMASK 1
# define STRNOTIFYMASK 131072

int		handle_key(int keycode, void *param);
void	event_hooks(t_main *env);

#endif
