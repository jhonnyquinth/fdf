/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_writer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:06:55 by sbrynn            #+#    #+#             */
/*   Updated: 2020/02/29 01:33:35 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float		max_abs(float a, float b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	return (a > b ? a : b);
}

static void			projections(float *x, float *y, int z, t_fdf *map)
{
	float xpy;
	float xmy;

	xpy = (*x + *y);
	xmy = (*x - *y);
	if (map->typeof_projection == 0)
	{
		*x = xmy * cos(map->angel);
		*y = xpy * sin(map->angel) - z;
	}
	else if (map->typeof_projection == 1)
		*y = z;
	else if (map->typeof_projection == 2)
		*x = z;
}

static void			zoom_helper(float x[2], float y[2], t_fdf *map)
{
	x[0] *= map->zoom;
	y[0] *= map->zoom;
	x[1] *= map->zoom;
	y[1] *= map->zoom;
}

static void			shift_helper(float x[2], float y[2], t_fdf *map)
{
	x[0] += map->shift_x;
	x[1] += map->shift_x;
	y[0] += map->shift_y;
	y[1] += map->shift_y;
}

void				line_writer(float x[2], float y[2], t_fdf *map)
{
	float	x_step;
	float	y_step;
	float	max;
	int		z1;
	int		z2;

	z1 = (map->map[(int)y[0]][(int)x[0]]) * (map->z_zoom);
	z2 = (map->map[(int)y[1]][(int)x[1]]) * (map->z_zoom);
	map->color = (z1 || z2) ? RED : WHITE;
	zoom_helper(x, y, map);
	projections(&(x[0]), &(y[0]), z1, map);
	projections(&(x[1]), &(y[1]), z2, map);
	shift_helper(x, y, map);
	max = max_abs(x[1] - x[0], y[1] - y[0]);
	x_step = (x[1] - x[0]) / max;
	y_step = (y[1] - y[0]) / max;
	while ((int)(x[0] - x[1]) || (int)(y[0] - y[1]))
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x[0], y[0], map->color);
		x[0] += x_step;
		y[0] += y_step;
	}
}
