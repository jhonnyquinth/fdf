/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 20:06:26 by sbrynn            #+#    #+#             */
/*   Updated: 2020/02/29 01:32:35 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define RED 0xe80c0c
# define WHITE 0xffffff

# include <math.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct	s_fdf
{
	int		width;
	int		height;
	int		**map;
	int		zoom;
	int		color;
	int		shift_y;
	int		shift_x;
	float	angel;
	float	angel_p;
	int		z_zoom;
	int		typeof_projection;
	int		size_x;
	int		size_y;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_fdf;

t_fdf			*read_fdf(char **av);
void			map_cleaner(int **map);
void			map_printer(int **map);
void			line_writer(float x[2], float y[2], t_fdf *map);
void			drawer(t_fdf *map);
void			map_corrector(t_fdf *map);
#endif
