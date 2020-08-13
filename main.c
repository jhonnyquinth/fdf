/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 20:10:02 by sbrynn            #+#    #+#             */
/*   Updated: 2020/02/29 01:32:07 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	deal_key_helper(int key, t_fdf *map)
{
	if (key == 2)
	{
		map->typeof_projection = (map->typeof_projection + 1) % 4;
		map->angel = 0.523599;
	}
	else if (key == 6)
		map->z_zoom += 2;
	else if (key == 7)
		map->z_zoom -= 2;
	else if (key == 8)
		map->zoom += 2;
	else if (key == 9)
		map->zoom -= 2;
}

int		deal_key(int key, t_fdf *map)
{
	if (key == 53)
		exit(0);
	else if (key == 126)
		map->shift_y -= 20;
	else if (key == 125)
		map->shift_y += 20;
	else if (key == 123)
		map->shift_x -= 20;
	else if (key == 124)
		map->shift_x += 20;
	else if (key == 0)
		map->angel += 0.1;
	else if (key == 1)
		map->angel -= 0.1;
	else
		deal_key_helper(key, map);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	drawer(map);
	return (0);
}

void	mlx_drawing(t_fdf *map)
{
	if (map->width > 300 || map->height > 300)
		map->zoom = 1;
	else if (map->width > 50 || map->height > 50)
		map->zoom = 4;
	else
		map->zoom = 16;
	map->z_zoom = 1;
	map_corrector(map);
	map->angel = 0.523599;
	map->angel_p = 0;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, map->size_x,
	map->size_y, "FDF");
	map->typeof_projection = 0;
	drawer(map);
	mlx_key_hook(map->win_ptr, deal_key, map);
	mlx_loop(map->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_fdf *map;

	map = NULL;
	if (ac >= 2)
	{
		map = read_fdf(av);
		mlx_drawing(map);
		map_cleaner(map->map);
	}
	else
		ft_putstr("usage: ./fdf [map]\n");
	return (0);
}
