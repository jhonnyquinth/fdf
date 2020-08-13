/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 20:10:12 by sbrynn            #+#    #+#             */
/*   Updated: 2020/02/23 21:09:16 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			arr_init_x(float arr_x[2], float arr_y[2], float x, float y)
{
	arr_x[0] = x;
	arr_x[1] = x + 1;
	arr_y[0] = y;
	arr_y[1] = y;
}

void			arr_init_y(float arr_x[2], float arr_y[2], float x, float y)
{
	arr_x[0] = x;
	arr_x[1] = x;
	arr_y[0] = y;
	arr_y[1] = y + 1;
}

void			drawer(t_fdf *map)
{
	float x;
	float y;
	float arr_x[2];
	float arr_y[2];

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			arr_init_x(arr_x, arr_y, x, y);
			if (x < map->width - 1)
				line_writer(arr_x, arr_y, map);
			arr_init_y(arr_x, arr_y, x, y);
			if (y < map->height - 1)
				line_writer(arr_x, arr_y, map);
			x++;
		}
		y++;
	}
}
