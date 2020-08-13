/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_corrector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 01:31:48 by sbrynn            #+#    #+#             */
/*   Updated: 2020/02/29 01:35:32 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_max(int a, int b, int c)
{
	if (a >= b && a >= c)
		return (a);
	else if (b >= a && b >= c)
		return (b);
	else
		return (c);
}

static int		ft_abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

void			map_corrector(t_fdf *map)
{
	map->size_x = (map->zoom) * ft_max(map->width,
	(int)(0.9 * ft_abs(map->width - map->height)), 1) + 1000;
	map->size_y = (map->zoom) * ft_max(map->height,
	(map->width + map->height) / 2, 1) + 500;
	map->shift_x = (int)((map->size_x) / 2);
	map->shift_y = (int)((map->size_y) / 8);
}
