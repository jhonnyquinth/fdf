/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 01:34:36 by sbrynn            #+#    #+#             */
/*   Updated: 2020/02/29 01:36:39 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_cleaner(int **map)
{
	int **map_help;

	map_help = map;
	while (*map_help)
	{
		free(*map_help);
		map_help++;
	}
	free(map);
}
