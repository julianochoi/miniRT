/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 23:29:23 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/04 00:27:10 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <errno.h>
# include <string.h>

# define ERR_BAD_COORD "Coordinates badly formatted."
# define ERR_NO_SEP "Missing separator."

void	print_error(char *err_msg);
void	exit_error(t_main *env, char *err_msg);
int		exit_success(t_main *env);

#endif
