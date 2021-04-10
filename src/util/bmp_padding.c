/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:46:21 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/07 16:46:58 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	bmp_padding(t_main *env, int fd)
{
	int mod;

	mod = env->res.size_x % 4;
	while (mod > 0)
	{
		if (write(fd, "0", 1) < 0)
			exit_error(env, (char *)strerror(errno));
		mod--;
	}
}

char	*change_filepath(uint32_t i)
{
	char *itoa_str;
	char *temp;
	char *filepath;

	itoa_str = ft_itoa(i);
	filepath = ft_strjoin(BMP_FILENAME, itoa_str);
	free_and_null(itoa_str);
	temp = ft_strdup(filepath);
	free_and_null(filepath);
	filepath = ft_strjoin(temp, ".bmp");
	free_and_null(temp);
	return (filepath);
}
